"""Reusable maze generation module.

This module exposes a single class, ``Maze``, which builds a
rectangular maze using a recursive-backtracker algorithm (a randomized
depth-first search over the grid of cells). Each cell is represented as
one integer whose 4 lowest bits encode its closed walls:

    bit 0 (1)  -> North wall closed
    bit 1 (2)  -> East wall closed
    bit 2 (4)  -> South wall closed
    bit 3 (8)  -> West wall closed

A closed wall between two neighbouring cells is always mirrored on both
sides (e.g. if cell (x, y) has its East wall closed, cell (x+1, y) has
its West wall closed too), so the grid always stays coherent.

Basic usage::

    from mazegen import Maze

    gen = Maze(width=20, height=15, seed=42, perfect=True)
    grid = gen.generate()  # grid[y][x] is the wall value of that cell

Passing the same ``seed`` twice always produces the same maze, which
makes the generator reproducible for testing purposes.
"""

import random

NORTH = 1
EAST = 2
SOUTH = 4
WEST = 8

OPPOSITE = {
    NORTH: SOUTH,
    SOUTH: NORTH,
    EAST: WEST,
    WEST: EAST,
}

DIRECTIONS = [NORTH, EAST, SOUTH, WEST]

DX = {NORTH: 0, SOUTH: 0, EAST: 1, WEST: -1}
DY = {NORTH: -1, SOUTH: 1, EAST: 0, WEST: 0}

# The '42' pattern: a small block of fully closed cells drawn inside the
# maze. A 1 means "this cell must stay fully closed" (wall value 15).
PATTERN_42 = [
    [1, 0, 1, 0, 1, 1, 1],
    [1, 0, 1, 0, 0, 0, 1],
    [1, 1, 1, 0, 1, 1, 1],
    [0, 0, 1, 0, 1, 0, 0],
    [0, 0, 1, 0, 1, 1, 1],
]

PATTERN_HEIGHT = len(PATTERN_42)
PATTERN_WIDTH = len(PATTERN_42[0])


class Maze:
    """Generate a maze on a rectangular grid of cells.

    The generator can produce either a perfect maze (exactly one path
    between any two cells, a spanning tree with no loops) or, when
    ``perfect`` is set to ``False``, a maze with a few extra openings
    that create loops while still respecting the maze constraints
    (connectivity, closed borders, no area wider than 2 cells, and a
    fully closed '42' pattern).

    Attributes:
        width: Number of columns of the maze.
        height: Number of rows of the maze.
        seed: Seed used for the random number generator, for
            reproducibility. ``None`` means a random seed.
        perfect: Whether the maze must stay a perfect maze (a single
            path between any two cells) or may contain loops.
    """

    def __init__(
            self,
            width: int,
            height: int,
            seed: int | None,
            perfect: bool = True,
    ) -> None:
        """Initialise the grid, full of closed cells, ready to generate.

        Args:
            width: Number of columns of the maze.
            height: Number of rows of the maze.
            seed: Seed for the random number generator, or ``None`` for
                a non-reproducible random maze.
            perfect: If ``True``, the maze will have exactly one path
                between any two cells. If ``False``, a few extra walls
                are removed to create loops.
        """
        self.width = width
        self.height = height
        self.seed = seed
        self.perfect = perfect
        self._randgen = random.Random(seed)
        self.ha42 = False
        self._pattern_start = (0, 0)
        # coordinate (x, y) della cella in alto a sinistra del pattern 42

        self.grid = []
        for y in range(height):
            row = []
            for x in range(width):
                row.append(15)  # parte con tutti i muri chiusi (15 = 1111)
            self.grid.append(row)

        self.visited = []
        for y in range(height):
            row = []
            for x in range(width):
                row.append(False)  # matrice delle celle visitate
            self.visited.append(row)

    def generate(self) -> list:
        """Generate a new maze and return its grid.

        Resets the internal grid, places the '42' pattern (if the maze
        is large enough), carves the maze with a recursive backtracker,
        and finally, if ``perfect`` is ``False``, removes a few extra
        walls to introduce loops.

        Returns:
            The generated grid: a list of rows, each row a list of
            per-cell wall values.
        """
        self.grid = []  # ricrea la griglia e la matrice delle visitate
        for y in range(self.height):
            row = []
            for x in range(self.width):
                row.append(15)
            self.grid.append(row)
        self.visited = []
        for y in range(self.height):
            row = []
            for x in range(self.width):
                row.append(False)
            self.visited.append(row)

        self.ha42 = self.metti42()
        if not self.ha42:
            print("Maze too small to place '42' pattern")

        self._dfs(0, 0)  # inizia la generazione dalla cella (0, 0)
        if not self.perfect:
            self._rompi_muri_extra()  # rompe muri extra per non-perfetto
        return self.grid

    def metti42(self) -> bool:
        """Place the fully closed '42' pattern at the centre of the grid.

        Returns:
            ``True`` if the maze is large enough and the pattern was
            placed, ``False`` otherwise.
        """
        if self.width < PATTERN_WIDTH + 2 or self.height < PATTERN_HEIGHT + 2:
            return False

        start_x = (self.width - PATTERN_WIDTH) // 2
        start_y = (self.height - PATTERN_HEIGHT) // 2  # per centrarlo

        self._pattern_start = (start_x, start_y)

        for py in range(PATTERN_HEIGHT):
            for px in range(PATTERN_WIDTH):
                if PATTERN_42[py][px] == 1:
                    x = start_x + px
                    y = start_y + py
                    self.grid[y][x] = 15
                    self.visited[y][x] = True

        return True

    def _dfs(self, x: int, y: int) -> None:
        """Carve the maze with a randomized recursive backtracker.

        Args:
            x: Column of the cell currently being visited.
            y: Row of the cell currently being visited.
        """
        self.visited[y][x] = True

        directions = [NORTH, EAST, SOUTH, WEST]
        self._randgen.shuffle(directions)  # ordine random di esplorazione

        for direction in directions:
            nuovax = x + DX[direction]  # coordinate della cella accanto
            nuovay = y + DY[direction]
            dentro_x = 0 <= nuovax < self.width  # dentro i limiti griglia
            dentro_y = 0 <= nuovay < self.height

            if dentro_x and dentro_y:
                if not self.visited[nuovay][nuovax]:
                    self.grid[y][x] = self.grid[y][x] & ~direction
                    # mette a 0 solo il muro da abbattere
                    direzioneopp = OPPOSITE[direction]
                    # es. se vado a nord, la cella accanto perde il muro sud
                    self.grid[nuovay][nuovax] = (
                        self.grid[nuovay][nuovax] & ~direzioneopp
                    )
                    self._dfs(nuovax, nuovay)  # ricorsione sulla cella vicina

    def _e_cella_42(self, x: int, y: int) -> bool:
        """Check whether cell (x, y) belongs to the '42' pattern area.

        Args:
            x: Column of the cell to check.
            y: Row of the cell to check.

        Returns:
            ``True`` if (x, y) is one of the fully closed '42' cells.
        """
        start_x, start_y = self._pattern_start
        px = x - start_x
        py = y - start_y

        if 0 <= px < PATTERN_WIDTH and 0 <= py < PATTERN_HEIGHT:
            return PATTERN_42[py][px] == 1

        return False

    def _apertura_sicura(
            self, x: int, y: int, direzione: int, nx: int, ny: int
    ) -> bool:
        """Check that opening one more wall stays within maze rules.

        The subject forbids open areas wider than 2 cells (e.g. a 2x3
        block is fine, a 3x3 block is not). Extra walls are only broken
        between cells that do not already have several walls open,
        which keeps the resulting open pockets small. The '42' pattern
        cells are always left untouched.

        Args:
            x: Column of the first cell.
            y: Row of the first cell.
            direzione: Direction of the wall to break, seen from (x, y).
            nx: Column of the neighbouring cell.
            ny: Row of the neighbouring cell.

        Returns:
            ``True`` if breaking this wall is considered safe.
        """
        if self._e_cella_42(x, y) or self._e_cella_42(nx, ny):
            return False

        # numero di muri già aperti per ciascuna delle due celle
        aperture_x = sum(1 for d in DIRECTIONS if not self.grid[y][x] & d)
        aperture_nx = sum(1 for d in DIRECTIONS if not self.grid[ny][nx] & d)

        # se una delle due celle ha già 2 o più muri aperti, non se ne
        # aggiunge un altro: evita di creare tasche troppo grandi
        return aperture_x < 2 and aperture_nx < 2

    def _rompi_muri_extra(self) -> None:
        """Remove a few extra walls to make the maze contain loops.

        Only used when ``perfect`` is ``False``. Candidate walls are
        picked at random and only broken when ``_apertura_sicura``
        confirms it will not create an open area wider than 2 cells and
        will not touch the '42' pattern.
        """
        n_extra = (self.width * self.height) // 10  # numero di rotture
        for _ in range(n_extra):
            x = self._randgen.randrange(self.width)
            y = self._randgen.randrange(self.height)
            direzione = self._randgen.choice(DIRECTIONS)
            nx, ny = x + DX[direzione], y + DY[direzione]

            if 0 <= nx < self.width and 0 <= ny < self.height:
                if self._apertura_sicura(x, y, direzione, nx, ny):
                    self.grid[y][x] &= ~direzione
                    self.grid[ny][nx] &= ~OPPOSITE[direzione]

    def get_grid(self) -> list:
        """Return the current maze grid.

        Returns:
            The grid: a list of rows, each row a list of per-cell wall
            values.
        """
        return self.grid

    def get_cell(self, x: int, y: int) -> int:
        """Return the wall value of a single cell.

        Args:
            x: Column of the cell.
            y: Row of the cell.

        Returns:
            The wall value of cell (x, y), a 4-bit integer.
        """
        return self.grid[y][x]

    def has_wall(self, x: int, y: int, direction: int) -> bool:
        """Check whether a given wall of a cell is closed.

        Args:
            x: Column of the cell.
            y: Row of the cell.
            direction: One of NORTH, EAST, SOUTH, WEST.

        Returns:
            ``True`` if the wall in that direction is closed.
        """
        return bool(self.grid[y][x] & direction)
