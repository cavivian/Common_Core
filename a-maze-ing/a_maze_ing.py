"""A-Maze-ing: a configurable maze generator with terminal display.

Usage:
    python3 a_maze_ing.py config.txt

Reads a plain-text configuration file, generates a maze accordingly,
writes it to the configured output file, and lets the user interact
with it in the terminal (regenerate, toggle the solution path, change
the wall colour).
"""

import sys
from mazegen.gest import control


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: python3 a_maze_ing.py config.txt")
        sys.exit(1)
    control(sys.argv)
