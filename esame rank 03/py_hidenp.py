def hidenp(small: str, big: str) -> str:
    it = iter(big)
    return all(c in it for c in small)


if __name__ == "__main__":
    print(hidenp("abc", "a1b2c3"))   # True
    print(hidenp("ace", "abcde"))    # True
    print(hidenp("aec", "abcde"))    # False
    print(hidenp("", "abc"))   # True
    print(hidenp("", ""))      # True
