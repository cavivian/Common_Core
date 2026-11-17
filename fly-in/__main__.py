import sys
from parser import Parse


def main():
    try:
        with open(sys.argv[1], 'r') as f:
            content = f.readline()
            while content:
                contenuto = Parse(content)
                contenuto.from_content_to_list_of_dict(content)
                content = f.readline()  # serve x stoppare il ciclo, x la fine
    except FileExistsError:
        SystemExit()


if __name__ == "__main__":
    main()
