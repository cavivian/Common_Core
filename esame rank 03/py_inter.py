def inter(s1: str, s2: str) -> str:
    result: str = ""
    for c in s1:
        if c is not result and c in s2:
            result += c
    return result


if __name__ == "__main__":
    print(inter("hello", "world"))
    print(inter("abc", "xyz"))
    print(inter("", "abc"))
