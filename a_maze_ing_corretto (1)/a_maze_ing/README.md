*This project has been created as part of the 42 curriculum by chimasier, cavivian.*

# A-Maze-ing

## Description

A-Maze-ing is a maze generator written in Python. You give it a config
file, and it builds a maze (a rectangular grid of cells with walls),
writes it in a `.txt` file using hexadecimal digits, finds the shortest
path from the entry to the exit, and shows the maze in the terminal
with ASCII characters.

The maze can be "perfect" (only one possible path between any two
cells) or not, depending on the config. It also always contains a
closed-off "42" shape hidden in the middle of the maze, if the maze is
big enough for it to fit.

Once the maze is displayed, you can interact with it: make a new one,
show/hide the solution path, or change the color of the walls.

The part of the code that actually builds the maze is in its own
package called `mazegen`, so it can be reused later in another project
without the rest of this program.

## Instructions

### Requirements

- Python 3.10 or newer.

### How to run it

```bash
make install     # installs the mazegen package
make run         # runs the program with config.txt
```

or directly:

```bash
python3 a_maze_ing.py config.txt
```

When it starts, the maze is written to the output file, printed in the
terminal, and then you get a little menu:

- `1` -> make a new maze
- `2` -> show/hide the path
- `3` -> change the wall color (white, red, green, blue, yellow)
- `4` -> quit

### Other Makefile commands

- `make debug` : runs the program with pdb (the Python debugger).
- `make lint` : runs flake8 and mypy the way the subject asks.
- `make lint-strict` : same but with mypy --strict (this one is not
  mandatory, it's the "optional" version from the subject).
- `make clean` : removes cache files and the maze.txt that gets
  generated.
- `make build` : builds the mazegen package (the .whl and .tar.gz).

## Configuration file format

One `KEY=VALUE` per line. Lines that start with `#` are comments and
get ignored.

| Key           | What it is                       | Example                |
|---------------|-----------------------------------|--------------------------|
| WIDTH         | width of the maze, in cells      | WIDTH=20                |
| HEIGHT        | height of the maze, in cells     | HEIGHT=15                |
| ENTRY         | entry cell, x,y                  | ENTRY=0,0                |
| EXIT          | exit cell, x,y                   | EXIT=19,14                |
| OUTPUT_FILE   | name of the output file (.txt)   | OUTPUT_FILE=maze.txt    |
| PERFECT       | if the maze should be perfect    | PERFECT=True              |
| SEED          | seed for the randomness (opt.)   | SEED=42                    |

ENTRY and EXIT can't be the same cell, and both need to be inside the
maze. If you don't put a SEED, the maze is different every time you
run the program.

## Maze generation algorithm

We used a recursive backtracker. It's basically a DFS on the grid:
start at cell (0,0), pick a random neighbor cell that hasn't been
visited yet, break the wall between them, go there, and repeat. When
there's no unvisited neighbor left, go back (backtrack) to the
previous cell and try another direction from there.

This algorithm gives you a perfect maze automatically, because it never
connects a cell that was already visited: there's no way to create a
loop, so you get exactly one path between any two cells without having
to check for that afterward.

If PERFECT is set to False, after the maze is generated we run one more
step that removes a few extra walls at random, so the maze gets some
loops. We made sure this step never touches the walls around the "42"
pattern, and never opens too many walls close together, so we don't
get an area wider than 2 cells (the subject says that's not allowed).

### Why we picked this algorithm

- It's not too hard to understand and to keep bug-free, and it builds
  a perfect maze "for free", we don't need extra code to check that.
- It gives long, winding corridors, which look nicer in the terminal
  than an algorithm that makes short, boring corridors everywhere.
- It works well with a seed, so it's easy to make the maze
  reproducible, which the subject asks for.

To find the shortest path we did NOT use DFS again, we used BFS
(breadth-first search) instead. The reason: once the maze can have
loops (PERFECT=False), there can be more than one path between the
entry and the exit, and DFS does not always find the shortest one, it
just finds *a* path. BFS always finds the shortest one because of how
it explores the grid (closest cells first).

## Reusable part

The `mazegen` package has all the maze logic and can be used on its
own:

```python
from mazegen import MazeGenerator

gen = MazeGenerator(width=20, height=15, seed=42, perfect=True)
grid = gen.generate()
```

Parameters you can change: `width`, `height`, `seed` (int or None),
`perfect` (True/False).

To get the shortest path between two cells:

```python
from mazegen import il_path

path = il_path(grid, (0, 0), (19, 14))
```

You can also access the grid directly with `gen.get_grid()`, or check
one cell with `gen.get_cell(x, y)` / `gen.has_wall(x, y, direction)`.
Note that this grid (a list of ints) is not the same format as the
output .txt file, even if it stores the same information.

The package is at the root of the repo and can be built like this:

```bash
pip install build
python3 -m build
pip install dist/mazegen-1.0.0-py3-none-any.whl
```

## Resources

- Maze generation algorithms, Wikipedia: https://en.wikipedia.org/wiki/Maze_generation_algorithm
- Jamis Buck's blog post about the recursive backtracker: https://weblog.jamisbuck.org/2010/12/27/maze-generation-recursive-backtracking
- Breadth-first search, Wikipedia: https://en.wikipedia.org/wiki/Breadth-first_search
- Python docs for `random`, `typing` and `collections.deque`.
- Python Packaging Authority tutorial for building the mazegen package: https://packaging.python.org/en/latest/tutorials/packaging-projects/

### How we used AI

We used an AI assistant (Claude) mostly to review our code against the
subject, not to write it for us. It pointed out what was wrong or
missing (Makefile mistakes, missing type hints, flake8 errors, the
DFS/BFS issue for the shortest path, the README missing sections...)
but most of the time it did not give us the fix directly, we had to
find it and write it ourselves, then it checked again.

We also used it to understand things we didn't get right away, for
example why BFS gives the shortest path and DFS doesn't, and to help
debug some environment problems (a Makefile with spaces instead of
tabs, a pip/pycodestyle version conflict).

At the end we asked it to also do a full pass and fix things directly
(this README included), because we had already understood the "why"
behind most of the fixes and wanted to save time on the parts that
were more about writing/formatting than about understanding the
project.

## Team and project management

- **chimasier**: TODO — write your role and what you mainly worked on
  (algorithm? packaging? something else?).
- **cavivian**: TODO — same here (config parsing? display? README?).

**Planning.** TODO — how did you plan to split the work at the
beginning, and did it actually go like that or did it change along the
way?

**What went well / what we'd do differently.** TODO — for example,
maybe testing earlier would have caught the DFS/shortest-path bug
sooner, or maybe splitting config-parsing and maze-generation from day
one would have helped.

**Tools.** Git/GitHub, flake8 and mypy for the checks, and an AI
assistant like explained above. (add pytest here if you end up writing
the test suite the subject recommends in III.3)
