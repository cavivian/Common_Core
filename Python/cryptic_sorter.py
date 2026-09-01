def cryptic_sorter(strings: list[str]) -> list[str]:
    """
    Write a function that sorts a list of strings according to multiple criteria:
    1. Primary sort: By string length (shortest first)
    2. Secondary sort: ASCII order, except letters are compared case-insensitively
   (for strings of same length)
    3. Tertiary sort: By number of vowels (ascending, for same length and lexically equal)
    4. Equal strings will appear in the same order as in the input list.
    """
    return sorted(
        strings, key=lambda word:
        (len(word),
         word.lower(),
         sum(c.lower() in 'aeiou' for c in word)
         )
    )


# if __name__ == "__main__":
#     print(cryptic_sorter(["apple","cat","banana","dog","elephant"]))
#     print(cryptic_sorter(["aaa","bbb","AAA","BBB"]))
#     print(cryptic_sorter(["hello","world","hi","test"]))
#     print(cryptic_sorter([]))
#     print(cryptic_sorter([""]))


def inter(s1: str, s2: str) -> str:
    """
    Returns a string with the characters that appears
    in both strings, without repetitions.
    Characters are added in the order that
    they appear in the first string.
    """
    res: str = ""
    for c in s1:
        if c not in res and c in s2:
            res += c
    return res


if __name__ == "__main__":
    print(inter("hello", "world"))
    print(inter("abc", "xyz"))
    print(inter("", "abc"))