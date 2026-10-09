"""mazegen: a reusable maze generation and pathfinding package.

Exposes:
    Maze: builds a maze grid (see mazegen.generator).
    il_path: finds the shortest path inside a maze grid (see mazegen.path).
"""

from .generator import Maze
from .path import il_path
from .mazegen import MazeGenerator
from .gest import valida, display, writeoutput

__all__ = ["Maze", "il_path", "MazeGenerator",
           "valida", "display", "writeoutput"]
