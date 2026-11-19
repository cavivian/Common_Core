import sys
from parser import Parse


def main():
    if len(sys.argv) != 2:
        raise SystemExit("I only need 1 argument")
    try:
        io = Parse(sys.argv[1])
        io.open()
        print(len(io.connections))
        print(len(io.zone))
    except FileNotFoundError:
        raise SystemExit("File corrupted")


if __name__ == "__main__":
    main()
