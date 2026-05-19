import sys


def ft_ancient_fragment():
    i = 1
    j = len(sys.argv) - 1
    if j == 0:
        print('Usage: ft_ancient_text.py <file>')
    elif i == j:
        f = sys.argv[i]
        print(f"Accessing file '{f}'")
        files = f
        try:
            with open(f, "r") as f:
                mio_file = f.read()
                print('---')
                print(f"\n{mio_file}")
                print("\n---")
                print(f"File '{files}' closed")
        except FileNotFoundError as e:
            print(f"Error opening file '{f}': {e}")


def main():
    if len(sys.argv) > 1:
        print("=== Cyber Archives Recovery ===")
    ft_ancient_fragment()


if __name__ == "__main__":
    main()
