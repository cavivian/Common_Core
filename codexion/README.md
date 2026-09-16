This project has been created as part of the 42 curriculum by cavivian

# Description

Codexion is a C project where we have to handle the behavior of Threads. Infact the Coders are threads that have to do three actions: **Compile, Debug and Refactor**, for a minimum number of compiles required passed from terminal. In addition to the minimum of number of compiles required, you have to give to the program seven more parameters: **number_of_coders** (how many coders do you want), **time_to_burnout** (time within which coder must perform actions), **time_to_compile** (compile execution time), **time_to_debug** (debug execution time), **time_to_refactor** (refactor execution time), **time_to_compiles_required** (as said above), **dongle_cooldown** (dongle rest time, time where the dongle is not available), **scheduler** (algorithm that is choosed, between FIFO and EDF). At the start of the simulation each coder need to check if two dongles are avaialble simultaneously, if not they rest, instead if it's available the coder can start compile, and once he have done compiling he puts down the dongle, starts debug and later refactor. After a compile the dongles have to rest for a time frame chose by the user. For debug and refactor the dongles are not used.


# Instructions

To run this program write "make" on terminal, and then give it the eight parameters that are requested by the subject.

#### Example:
```` ./codexion 4 10000 1000 1000 1000 5 0 FIFO ````


# Blocking cases handled







# Resources

To do this project I studied Threads from a channel on YouTube called CodeGrind