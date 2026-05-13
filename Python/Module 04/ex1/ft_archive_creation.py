import sys
from typing import IO

def ft_archive_creation():
    i = 1
    j = len(sys.argv) -1
    if i == j:
        nome_file = sys.argv[i]
        print(f"Accessing file '{nome_file}'")
        try:
            with open(nome_file, "r") as f:
                contenuto = f.read()
                print('---')
                print(f"\n{contenuto}")
                print("\n---")
                print(f"File '{nome_file}' closed")
        except FileNotFoundError as e:
            print(f"Error opening file '{f}': {e}")
        print("\nTransform data")
        try:
            with open(nome_file, "a") as file_scrittura:
                print('---')
                print(f"{contenuto}#")
        except FileNotFoundError as e:
            print(f"Error opening file '{nome_file}': {e}")
        print("\n---")
        name = input("Enter new file name (or empty): ")
        if not name:
            print("Not saving data")
        else:
            print(f"Saving data to '{name}'")
            print(f"Data saved in file '{name}'")


def main():
    if len(sys.argv) > 1:
        print("=== Cyber Archives Recovery & Preservations ===")
    ft_archive_creation()


if __name__ == "__main__":
    main()
