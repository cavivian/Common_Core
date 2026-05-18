import sys


def main() -> None:
    print('=== Command Quest ===')
    i = 0
    j = len(sys.argv) - 1
    nome_file = sys.argv[i]
    print(f'Program name: {nome_file}')
    if j == 0:
        print('No arguments provided!')
    else:
        i = 1
        print(f'Arguments received: {j}')
        while i < len(sys.argv):
            print(f'Argument {i}: {sys.argv[i]}')
            i += 1
    print(f'Total arguments: {len(sys.argv)}')


if __name__ == "__main__":
    main()
