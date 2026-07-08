import sys
import os
import site


def in_venv():
    return sys.prefix != sys.base_prefix


def se_venv():
    path = sys.prefix
    version = sys.executable
    package = site.getsitepackages()
    nome = info_env(path)
    print("MATRIX STATUS: Welcome to the construct")
    print()
    print(f"Current Python: {version}")  # dobbiamo usare sys
    print(f"Virtual environment: {nome}")  # dobbiamo usare os
    print(f"Environment path: {path}")  # dobbiamo usare sys.prefix
    print()
    print("SUCCESS: You're in an isolated environment")
    print("Safe to install packages without affecting")
    print("the global system")
    print()
    print("Package installation path:")
    print(package)  # qui c'è da usare il site,
    # serve per vedere il percorso di installazione


def info_env(path):
    return os.path.basename(path)


def se_non_venv():
    print("MATRIX STATUS: You're still plugged in")
    print()
    print(f"Current Python: {sys.executable}")
    print("Virtual environment: None detected")
    print()
    print("WARNING: You're in the global environment")
    print("The machines can see everything you install")
    print()
    print("To enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate # On Unix")
    print("martix_env/Script/activate # On Windows")
    print()
    print("Then run this programm again.")


if __name__ == "__main__":
    if in_venv():
        se_venv()
    else:
        se_non_venv()
