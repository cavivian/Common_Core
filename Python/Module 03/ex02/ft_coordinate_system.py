import math

def get_player_pos():
    print('\nGet a first set of coordinates')
    try:
        input(int("Enter new coordinates as floats in format 'x,y,z': "))
        print(f"Got a first tuple: ({input(tuple())})")
    except:
        print('Invalid syntax')



def main():
    print('=== Game Coordinate System ===')
    get_player_pos()

if __name__ == "__main__":
    main()