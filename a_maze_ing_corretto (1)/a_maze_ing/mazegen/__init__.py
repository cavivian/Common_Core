"""mazegen: a reusable maze generation and pathfinding package.

Exposes:
    MazeGenerator: builds a maze grid (see mazegen.generator).
    il_path: finds the shortest path inside a maze grid (see mazegen.path).
"""

from .generator import MazeGenerator
from .path import il_path

__all__ = ["MazeGenerator", "il_path"]
