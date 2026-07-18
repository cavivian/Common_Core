NORTH = 1
EAST  = 2
SOUTH = 4
WEST  = 8

DX = {NORTH: 0, SOUTH: 0, EAST: 1, WEST: -1}
DY = {NORTH: -1, SOUTH: 1, EAST: 0, WEST: 0}

DIR_LETTERA = {NORTH: 'N', EAST: 'E', SOUTH: 'S', WEST: 'W'}


def il_path(grid, start, end):
    width = len(grid[0])
    height = len(grid)

    sx, sy = start #per coord di partenza
    ex, ey = end

    # giri per vedere le celle visitate
    visited = []
    for y in range(height):
        row = []
        for x in range(width):
            row.append(False)
        visited.append(row)

    parent = {} # diz che ricorda dove siamo arrivati x ogni cella

    stack = [(sx, sy)] # pila dfs da cella di inizio
    visited[sy][sx] = True

    while stack: # prende ultim cell inser nella pila 
        x, y = stack.pop()

        if (x, y) == (ex, ey): # se è a fine ritracciamo il percorso
            return ricostruz_percor(parent, start, end)

        for direction in [NORTH, EAST, SOUTH, WEST]: # prova tutte e 4 dir

            chiuso = grid[y][x] & direction
            if chiuso:
                continue

            nx = x + DX[direction] # coord cella vicina
            ny = y + DY[direction]

            dentro_x = 0 <= nx < width
            dentro_y = 0 <= ny < height

            if dentro_x and dentro_y:
                if not visited[ny][nx]:
                    visited[ny][nx] = True #segna come visitata
                    parent[(nx, ny)] = (x, y, direction) # ricorda arrivo
                    stack.append((nx, ny)) # aggiunge a pila

    return None # se pila vuota e niente fine non esiste percorso


def ricostruz_percor(parent, start, end):
    strada = []
    current = end

    while current != start: # risale al percc seguendo paret
        x, y, direction = parent[current]
        strada.append(DIR_LETTERA[direction]) # aggiuge lettera direz
        current = (x, y)

    strada.reverse() #percorso al contrario quindi inverte
    return ''.join(strada) #unisce tutte lettere a stringa tio sequenza di lette boh NNEEWWSS etc