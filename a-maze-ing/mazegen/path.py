"""Shortest-path search inside an already generated maze grid.

The maze is represented as a grid of integers, where each cell encodes
its closed walls as 4 bits (North, East, South, West). This module finds
the shortest path between two cells and encodes it as a string of
cardinal-direction letters (N, E, S, W).
"""

from collections import deque

NORTH = 1
EAST = 2
SOUTH = 4
WEST = 8

DX = {NORTH: 0, SOUTH: 0, EAST: 1, WEST: -1}
DY = {NORTH: -1, SOUTH: 1, EAST: 0, WEST: 0}

DIR_LETTERA = {NORTH: 'N', EAST: 'E', SOUTH: 'S', WEST: 'W'}


def il_path(grid: list, start: tuple, end: tuple) -> str | None:
    """Find the shortest path between two cells of the maze.

    A breadth-first search (BFS) is used on purpose instead of a
    depth-first search: once ``PERFECT`` is disabled the maze can
    contain loops, so several paths may exist between ``start`` and
    ``end``. BFS guarantees that the first time ``end`` is reached, it
    has been reached through the shortest possible route.

    Args:
        grid: The maze grid, one row per list, one hexadecimal-wall
            value per cell.
        start: The (x, y) coordinates of the entry cell.
        end: The (x, y) coordinates of the exit cell.

    Returns:
        The shortest path from ``start`` to ``end`` as a string made of
        the letters 'N', 'E', 'S', 'W', or ``None`` if no path exists.
    """
    width = len(grid[0])
    height = len(grid)

    sx, sy = start  # coordinate di partenza
    ex, ey = end

    visited = []
    for y in range(height):
        row = []
        for x in range(width):
            row.append(False)
        visited.append(row)

    parent: dict[tuple, tuple] = {}
    # dizionario che ricorda da dove siamo arrivati per ogni cella

    queue = deque([(sx, sy)])  # coda BFS, garantisce il percorso più corto
    visited[sy][sx] = True

    while queue:  # prende la cella più vecchia inserita nella coda
        x, y = queue.popleft()

        if (x, y) == (ex, ey):  # arrivati alla fine, ricostruiamo il percorso
            return ricostruz_percor(parent, start, end)

        for direction in [NORTH, EAST, SOUTH, WEST]:  # prova le 4 direzioni

            chiuso = grid[y][x] & direction
            if chiuso:
                continue

            nx = x + DX[direction]  # coordinate della cella vicina
            ny = y + DY[direction]

            dentro_x = 0 <= nx < width
            dentro_y = 0 <= ny < height

            if dentro_x and dentro_y:
                if not visited[ny][nx]:
                    visited[ny][nx] = True  # segna come visitata
                    parent[(nx, ny)] = (x, y, direction)  # ricorda arrivo
                    queue.append((nx, ny))  # aggiunge in coda

    return None  # se la coda si vuota senza raggiungere la fine


def ricostruz_percor(
        parent: dict[tuple, tuple], start: tuple, end: tuple
) -> str:
    """Rebuild the path from ``start`` to ``end`` as a string of letters.

    Args:
        parent: Mapping built during the search, from each visited cell
            to the (previous_x, previous_y, direction_taken) tuple that
            reached it.
        start: The (x, y) coordinates of the entry cell.
        end: The (x, y) coordinates of the exit cell.

    Returns:
        The path from ``start`` to ``end`` as a string of 'N', 'E', 'S',
        'W' letters, in travel order.
    """
    strada = []
    current = end

    while current != start:  # risale il percorso seguendo i genitori
        x, y, direction = parent[current]
        strada.append(DIR_LETTERA[direction])  # aggiunge la lettera
        current = (x, y)

    strada.reverse()  # il percorso era al contrario, va invertito
    return ''.join(strada)  # unisce le lettere in una stringa, es. "NNEESS"
