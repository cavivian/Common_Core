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

PATTERN_42 = [
    [1, 0, 1, 0, 1, 1, 1],
    [1, 0, 1, 0, 0, 0, 1],
    [1, 1, 1, 0, 1, 1, 1],
    [0, 0, 1, 0, 1, 0, 0],
    [0, 0, 1, 0, 1, 1, 1],
] # con bit 1 = 15 cioe chiusa

PATTERN_HEIGHT = len(PATTERN_42)
PATTERN_WIDTH  = len(PATTERN_42[0])


class MazeGenerator:

    def __init__(self, width: int, height: int, seed: int = None, perfect: bool = True):
        self.width = width
        self.height = height
        self.seed = seed
        self.perfect = perfect
        self._randgen = random.Random(seed) #gener di num con seed
        self.ha42 = False

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

        self.ha42 = self.metti42()
        if not self.ha42:
            print("Maze too small to place '42' pattern")

        self._dfs(0, 0) #inizio gen da cella con coord 0,0
        if not self.perfect:
            self._rompi_muri_extra() #rompo muri extra per renderlo non perfetto 
        return self.grid
    

    def metti42(self):
        if self.width < PATTERN_WIDTH + 2 or self.height < PATTERN_HEIGHT + 2:
            return False

        start_x = (self.width - PATTERN_WIDTH) // 2
        start_y = (self.height - PATTERN_HEIGHT) // 2 #per centrarlo al centro

        for py in range(PATTERN_HEIGHT):
            for px in range(PATTERN_WIDTH):
                if PATTERN_42[py][px] == 1:
                    x = start_x + px
                    y = start_y + py
                    self.grid[y][x] = 15
                    self.visited[y][x] = True

        return True

    def _dfs(self, x: int, y: int):
        self.visited[y][x] = True

        directions = [NORTH, EAST, SOUTH, WEST]
        self._randgen.shuffle(directions) # mescola le direz per esploraz random

        for direction in directions:
            nuovax = x + DX[direction] # coord per cella accanto
            nuovay = y + DY[direction]
            dentro_x = 0 <= nuovax < self.width #per veder se dentro liniti griglia
            dentro_y = 0 <= nuovay < self.height

            if dentro_x and dentro_y:
                if not self.visited[nuovay][nuovax]:
                    self.grid[y][x] = self.grid[y][x] & ~direction #coi mette a 0 solo il muro da abbattere
                    direzioneopp = OPPOSITE[direction] #es se vado a nord perde cella sud
                    self.grid[nuovay][nuovax] = self.grid[nuovay][nuovax] & ~direzioneopp
                    self._dfs(nuovax, nuovay)#ricorsione per cella vicina
                    
    def _rompi_muri_extra(self):
        """Rimuove alcuni muri extra per rendere il labirinto non perfetto."""
        n_extra = (self.width * self.height) // 10  # quante rotture, a piacere
        for _ in range(n_extra):
            x = self._randgen.randrange(self.width)
            y = self._randgen.randrange(self.height)
            direzione = self._randgen.choice(DIRECTIONS)
            nx, ny = x + DX[direzione], y + DY[direzione]
            if 0 <= nx < self.width and 0 <= ny < self.height:
                # non toccare le celle del pattern 42
                if self.grid[y][x] != 15 or not self._e_cella_42(x, y):
                    self.grid[y][x] &= ~direzione
                    self.grid[ny][nx] &= ~OPPOSITE[direzione]

    def get_grid(self):
        return self.grid

    def get_cell(self, x: int, y: int) -> int:
        return self.grid[y][x]

    def has_wall(self, x: int, y: int, direction: int) -> bool:
        return bool(self.grid[y][x] & direction)
