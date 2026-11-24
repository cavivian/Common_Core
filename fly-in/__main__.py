import sys
from parse import Parsing, ParseError
from classes import Fleet, ZoneStatus


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit("I only need 1 argument")
    try:
        io = Parsing(sys.argv[1])
        io.open()
        print(len(io.connections))
        print(len(io.zone))
        assert io.nb_drones is not None
        start = next(z.name for z in io.zone
             if z.status == ZoneStatus.START_HUB)
        end = next(z.name for z in io.zone
                   if z.status == ZoneStatus.END_HUB)
        fleet = Fleet(start, io.nb_drones, end)
        print(fleet.check_if_end())
    except FileNotFoundError:
        raise SystemExit(f"Error: file '{sys.argv[1]}' not found")
    except OSError as e:
        raise SystemExit(f"Error: cannot read '{sys.argv[1]}': {e.strerror}")
    except (ParseError, ValueError) as e:
        raise SystemExit(f"Error: {e}")


if __name__ == "__main__":
    main()
