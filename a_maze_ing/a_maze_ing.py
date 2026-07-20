import sys
from mazegen import MazeGenerator, il_path

NORTH = 1
EAST = 2
SOUTH = 4
WEST = 8


def parse(nomefile: str) -> dict:
    config = {}

    try:
        file = open(nomefile, 'r')
    except FileNotFoundError:
        print(f"Error: file '{nomefile}' not found")
        sys.exit(1)

    for row in file:
        rigacontinua = row.strip()

        if not rigacontinua:
            continue

        if rigacontinua.startswith('#'):
            continue

        if '=' not in rigacontinua:
            print(f"Error: invalid line: {rigacontinua}")
            sys.exit(1)

        parte = rigacontinua.split('=', 1)
        nome = parte[0].strip()
        value = parte[1].strip()
        config[nome] = value

    file.close()
    return config


def valida(config: dict) -> tuple:

    required = ['WIDTH', 'HEIGHT', 'ENTRY', 'EXIT', 'OUTPUT_FILE', 'PERFECT']
    for requi in required:
        if requi not in config:
            print(f"Error: missing key '{requi}' in config")
            sys.exit(1)

    if not config['WIDTH'].isdigit():
        print("Error: WIDTH must be an integer")
        sys.exit(1)
    if not config['HEIGHT'].isdigit():
        print("Error: HEIGHT must be an integer")
        sys.exit(1)

    if not config['OUTPUT_FILE'].endswith('.txt'):
        print("Error: OUTPUT_FILE must be a .txt file")
        sys.exit(1)
    width = int(config['WIDTH'])
    height = int(config['HEIGHT'])

    if width < 2:
        print("Error: WIDTH must be at least 2")
        sys.exit(1)
    if height < 2:
        print("Error: HEIGHT must be at least 2")
        sys.exit(1)

    entry = config['ENTRY'].split(',')
    if len(entry) != 2:
        print("Error: ENTRY must be in format x,y")
        sys.exit(1)
    if not entry[0].isdigit() or not entry[1].isdigit():
        print("Error: ENTRY must be in format x,y")
        sys.exit(1)
    entrx = int(entry[0])
    entry = int(entry[1])

    exitt = config['EXIT'].split(',')
    if len(exitt) != 2:
        print("Error: EXIT must be in format x,y")
        sys.exit(1)
    if not exitt[0].isdigit() or not exitt[1].isdigit():
        print("Error: EXIT must be in format x,y")
        sys.exit(1)
    uscix = int(exitt[0])
    usciy = int(exitt[1])

    if entrx < 0 or entrx >= width:
        print("Error: ENTRY x is outside maze bounds")
        sys.exit(1)
    if entry < 0 or entry >= height:
        print("Error: ENTRY y is outside maze bounds")
        sys.exit(1)

    if uscix < 0 or uscix >= width:
        print("Error: EXIT x is outside maze bounds")
        sys.exit(1)
    if usciy < 0 or usciy >= height:
        print("Error: EXIT y is outside maze bounds")
        sys.exit(1)

    if entrx == uscix and entry == usciy:
        print("Error: ENTRY and EXIT must be different")
        sys.exit(1)

    perfectval = config['PERFECT'].lower()
    if perfectval != 'true' and perfectval != 'false':
        print("Error: PERFECT must be True or False")
        sys.exit(1)
    if perfectval == 'true':
        perfect = True
    else:
        perfect = False
    print(f"seed: {config.get('SEED', 'None')}")
    seed = None
    if 'SEED' in config:
        if config['SEED'] != '':
            if not config['SEED'].isdigit():
                print("Error: SEED must be an integer")
                sys.exit(1)
            seed = int(config['SEED'])

    return (width,
            height,
            (entrx, entry),
            (uscix, usciy),
            config['OUTPUT_FILE'],
            perfect,
            seed
            )


def writeoutput(
        filepath: str,
        grid: list,
        entry: tuple,
        exit_: tuple,
        path: str
        ) -> None:

    try:
        file = open(filepath, 'w')
    except IOError:
        print(f"Error: cannot write to file '{filepath}'")
        sys.exit(1)

    for riga in grid:
        convesadecimale = ''
        for cell in riga:
            convesadecimale += format(cell, 'X')
        file.write(convesadecimale + '\n')

    file.write('\n')

    file.write(str(entry[0]) + ',' + str(entry[1]) + '\n')

    file.write(str(exit_[0]) + ',' + str(exit_[1]) + '\n')

    file.write(path + '\n')

    file.close()

""" funzione che mostra a schermo il labirinto, proponendo anche i possibili colori con i quali può essere
visto."""
def display(
        grid: list,
        entry: tuple,
        exit_: tuple,
        path: str | None = None,
        mostrapath: bool = False,
        murocolore: str = 'white') -> None:

    colori = {
        'white':  '\033[97m',
        'red':    '\033[91m',
        'green':  '\033[92m',
        'blue':   '\033[94m',
        'yellow': '\033[93m',
    }
    reset = '\033[0m'

    if murocolore in colori:
        color = colori[murocolore]
    else:
        color = colori['white']

    width = len(grid[0])
    height = len(grid)

    cellestrada = set()
    if mostrapath and path:
        cellestrada = stradacells(entry, path)

    rigasuperiore = color + '+' + reset
    for x in range(width):
        rigasuperiore += color + '--+' + reset
    print(rigasuperiore)

    for y in range(height):

        riga = color + '|' + reset

        for x in range(width):
            cella = grid[y][x]

            if (x, y) == entry:
                char = 'EN'
            elif (x, y) == exit_:
                char = 'EX'
            elif cella == 15:
                char = '██'
            elif mostrapath and (x, y) in cellestrada:
                char = '..'
            else:
                char = '  '

            riga += char

            if cella & EAST:
                riga += color + '|' + reset
            else:
                riga += ' '

        print(riga)

        fondo = color + '+' + reset
        for x in range(width):
            cella = grid[y][x]
            if cella & SOUTH:
                fondo += color + '--' + reset + color + '+' + reset
            else:
                fondo += '  ' + color + '+' + reset
        print(fondo)


def stradacells(entry: tuple, path: str) -> set:

    DX = {'N': 0, 'S': 0, 'E': 1, 'W': -1}
    DY = {'N': -1, 'S': 1, 'E': 0, 'W': 0}

    cells = set()

    x = entry[0]
    y = entry[1]

    cells.add((x, y))

    for letter in path:
        x = x + DX[letter]
        y = y + DY[letter]
        cells.add((x, y))

    return cells


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: python3 a_maze_ing.py config.txt")
        sys.exit(1)

    nomefile = sys.argv[1]

    config = parse(nomefile)

    width, height, entry, exit_, outputfile, perfect, seed = valida(config)

    gen = MazeGenerator(width, height, seed, perfect)
    grid = gen.generate()

    path = il_path(grid, entry, exit_)
    if path is None:
        print("Error: no path found between entry and exit")
        sys.exit(1)

    writeoutput(outputfile, grid, entry, exit_, path)
    print(f"Maze written to {outputfile}")

    display(grid, entry, exit_)

    mostrapath = False
    murocolor = 'white'

    while True:
        print("\n[1] regenerate")
        print("[2] toggle path")
        print("[3] change color")
        print("[4] quit")

        cmd = input("> ").strip().lower()

        if cmd == '4':
            break

        elif cmd == '1':
            gen = MazeGenerator(width, height, seed, perfect)
            grid = gen.generate()
            path = il_path(grid, entry, exit_)
            if path is None:
                print("Error: no path found between entry and exit")
                sys.exit(1)
            writeoutput(outputfile, grid, entry, exit_, path)
            display(grid, entry, exit_, path, mostrapath, murocolor)

        elif cmd == '2':
            mostrapath = not mostrapath
            display(grid, entry, exit_, path, mostrapath, murocolor)

        elif cmd == '3':
            print("Available colors: white, red, green, blue, yellow")
            murocolor = input("Choose color: ").strip().lower()
            display(grid, entry, exit_, path, mostrapath, murocolor)

        else:
            print("Unknown command")
