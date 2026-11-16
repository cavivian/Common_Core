import sys
from parser import Parse


def main():
    try:
        with open(sys.argv[1], "r") as f:
            content = f.read()
            print(content)
        contenuto = Parse(content)
        contenuto.from_content_to_list(content)
    except FileExistsError:
        SystemExit()

if __name__ == "__main__":
    main()
