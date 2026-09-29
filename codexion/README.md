*This project has been created as part of the 42 curriculum by cavivian.*

# Description

Codexion is a C project where we have to handle the behavior of threads. In fact the coders are threads that have to do three actions: **compile, debug and refactor**, for a minimum number of compiles required passed from terminal.

The coders sit around a table and share the dongles: there is one dongle for each coder, and to compile a coder needs **two dongles at the same time** (the left one and the right one). Because of this, the coders must compete for the dongles, and the goal of the project is to manage this competition without data races, deadlocks or starvation.

The program needs eight parameters:

| Parameter | Meaning |
|---|---|
| **number_of_coders** | how many coders (and dongles) there are |
| **time_to_burnout** | time (ms) within which a coder must start a new compile, otherwise he burns out |
| **time_to_compile** | compile execution time (ms) |
| **time_to_debug** | debug execution time (ms) |
| **time_to_refactor** | refactor execution time (ms) |
| **number_of_compiles_required** | how many times each coder must compile before the simulation ends |
| **dongle_cooldown** | dongle rest time (ms), time where the dongle is not available after a compile |
| **scheduler** | algorithm that decides who gets the dongle first: `fifo` or `edf` |

At the start of the simulation each coder needs to check if two dongles are available simultaneously. If not, he waits. If they are available, the coder can start to compile, and once he has done compiling he puts down the dongles, starts to debug and later to refactor. For debug and refactor the dongles are not used.

The simulation ends when all the coders have compiled at least `number_of_compiles_required` times, or when one coder burns out. The program prints every action with a timestamp in milliseconds:

```
<timestamp_in_ms> <coder_id> has taken a dongle
<timestamp_in_ms> <coder_id> is compiling
<timestamp_in_ms> <coder_id> is debugging
<timestamp_in_ms> <coder_id> is refactoring
<timestamp_in_ms> <coder_id> burned out
```

### The two schedulers

Every dongle has its own waiting queue, implemented as a **heap**. A coder can take the dongles only if he is at the top of the queue of both of them.

- **FIFO** (First In, First Out): the priority is the moment when the coder asked for the dongles. Who arrives first, goes first.
- **EDF** (Earliest Deadline First): the priority is the moment of the last compile start of the coder. The coder who is closer to the burnout is served first.


# Instructions

To compile the program write `make` on terminal, and then give it the eight parameters that are requested by the subject. The program needs the pthread library, and it is compiled for Linux.

#### Example:
```` ./codexion 4 10000 1000 1000 1000 5 0 fifo ````

This runs 4 coders, with a burnout time of 10000 ms, 1000 ms for compile, debug and refactor, 5 compiles required for each coder, no cooldown on the dongles and the FIFO scheduler.

The parameters must be positive integers (the scheduler must be written in lowercase, `fifo` or `edf`). If the parameters are wrong, the program stops without starting the simulation.

Other useful commands:

- `make clean` removes the object files
- `make fclean` removes the object files and the executable
- `make re` recompiles everything


# Blocking cases handled

**Deadlock.** A coder never holds one dongle while he waits for the other one. He looks at both dongles while he holds both their mutexes, and he takes them only if both are free and he is first in both queues. If even one of the two is not available he releases everything and tries again later, so the "hold and wait" condition of the deadlock never happens. The two dongles of the first coder are also swapped in the initialization, so the dongles are not locked in a circular order.

**Starvation.** A coder cannot wait forever, because the dongles are given following the priority of the heap. With FIFO nobody can be overtaken by a coder who arrived later. With EDF the coder who is closest to the burnout goes first.

**Burnout.** A separate monitor thread checks all the coders continuously. If the time from the last compile start of a coder is greater than or equal to `time_to_burnout`, the monitor stops the simulation and prints the burnout message.

**Only one coder.** With one coder there is only one dongle, so he can never take two dongles. The coder just waits for the burnout time, and then the monitor prints that he burned out.

**Stop of the simulation.** The stop flag is shared between all the threads and it is always read and written with its mutex. When the flag is set, the coders stop to wait for the dongles and exit their routine, so all the threads can be joined and the memory can be cleaned without leaks.

**Mixed output.** Every message is printed while holding a print mutex, so the lines of two coders never mix together. After the simulation is stopped no more messages are printed, except the burnout one.

**Errors.** If the parameters are not valid, or if a `malloc`, a mutex init or a thread creation fails, the program stops and frees what was already allocated.


# Thread synchronization mechanisms

The program uses only the POSIX threads library (`pthread`).

- **One thread for each coder** (`pthread_create`) and **one monitor thread**. At the end all of them are joined with `pthread_join`.
- **`m_dongle` (mutex, one for each dongle)**: protects the state of the dongle (`is_not_available`, `t_available_dongle`) and its waiting heap. A coder locks both his dongles to check and take them in a single step.
- **`mutex` (one for each coder)**: protects `last_compile_start` and `n_of_compiles`, that are written by the coder and read by the monitor.
- **`m_simulation_stop`**: protects the flag that says if the simulation is finished.
- **`m_print`**: guarantees that only one thread at a time writes on the terminal.

The coders wait for the dongles with a loop that checks the availability and sleeps for a very short time with `usleep`, and the same is done by the monitor. The waiting is not done with condition variables.

**Communication between coder and monitor.** The coders update their own data (last compile start, number of compiles) under their mutex, and the monitor reads the same data with the same mutex. The monitor is the only one that decides that the simulation is finished for a burnout, and it communicates it to the coders through the stop flag.

**Race conditions avoided.** Every data shared between threads is accessed only while holding the mutex that protects it. The code was checked with Helgrind (`valgrind --tool=helgrind`) to find the data races.


# Resources

To do this project I studied threads from a channel on YouTube called CodeGrind.

Classic references used:

- `man pthread_create`, `man pthread_join`, `man pthread_mutex_lock` and the other pthread man pages
- `man usleep` and `man gettimeofday`
- Documentation of Valgrind and Helgrind, to find the data races
- Articles and lessons about the dining philosophers problem and about heaps (priority queues)

**Use of AI.** AI was used as a support tool, not to write the project. In particular:

- to read the code and to help me understand the data races that Helgrind was reporting, and to explain why they were happening (the fixes were done by me);
- to help me write and to correct the English of this README, starting from my notes and from my code.

All the code of the project was written and is understood by me.
