import random


NORTH = 1  
EAST  = 2  
SOUTH = 4  
WEST  = 8 

OPPOSITE = {
    NORTH: SOUTH,
    SOUTH: NORTH,
    EAST:  WEST,
    WEST:  EAST
}

DIRECTIONS = [NORTH, EAST, SOUTH, WEST]

DX = {NORTH: 0, SOUTH: 0, EAST: 1, WEST: -1}
DY = {NORTH: -1, SOUTH: 1, EAST: 0, WEST: 0} #x y giuste ?

class MazeGenerator:

    def __init__(self, width: int, height: int, seed: int = None):
        self.width = width
        self.height = height
        self.seed = seed
        self._rng = random.Random(seed) #gener di num con seed

        self.grid = []
        for y in range(height):
            row = []
            for x in range(width):
                row.append(15) #parte a muri chiusi xk 15 1111 in binario
            self.grid.append(row)

        self.visited = []
        for y in range(height):
            row = []
            for x in range(width):
                row.append(False) #matrice per vedere le vistate con fals
            self.visited.append(row)

    def generate(self):
        self.grid = [] #rifaccio griglia e matrice visted
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
        self._dfs(0, 0) #inizio gen da cella con coord 0,0
        return self.grid
    
    def _dfs(self, x: int, y: int):
        self.visited[y][x] = True

        directions = [NORTH, EAST, SOUTH, WEST]
        self._rng.shuffle(directions) # mescola le direz per esploraz random

        for direction in directions:
            nuovax = x + DX[direction] # coord per cella accanto
            nuovay = y + DY[direction]
            dentro_x = 0 <= nuovax < self.width #per veder se dentro liniti griglia
            dentro_y = 0 <= nuovay < self.height

            if dentro_x and dentro_y:
                if not self.visited[nuovay][nuovax]:
                    self.grid[y][x] = self.grid[y][x] & ~direction #coi mette a 0 solo il muro da abbattere
                    direzione_opposta = OPPOSITE[direction] #es se vado a nord perde cella sud
                    self.grid[nuovay][nuovax] = self.grid[nuovay][nuovax] & ~direzione_opposta
                    self._dfs(nuovax, nuovay)#ricorsione per cella vicina

    def get_grid(self):
        return self.grid

    def get_cell(self, x: int, y: int) -> int:
        return self.grid[y][x]

    def has_wall(self, x: int, y: int, direction: int) -> bool:
        return bool(self.grid[y][x] & direction)