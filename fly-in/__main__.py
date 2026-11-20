import sys
from parse import Parse, ParseError


def main():
    if len(sys.argv) != 2:
        raise SystemExit("I only need 1 argument")
    try:
        io = Parse(sys.argv[1])
        io.open()
        # print(io.zone)
        # print(io.connections)
        print(len(io.connections))
        print(len(io.zone))
    except FileNotFoundError:
        raise SystemExit(f"Error: file '{sys.argv[1]}' not found")
    except (ParseError, ValueError) as e:
        raise SystemExit(f"Error: {e}")


if __name__ == "__main__":
    main()
