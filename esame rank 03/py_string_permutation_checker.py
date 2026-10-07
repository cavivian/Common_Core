def string_permutation_checker(s1: str, s2: str) -> bool:
    return (sorted(s1) == sorted(s2))


if __name__ == "__main__":
    print(string_permutation_checker("abc", "bca"))  # True
    print(string_permutation_checker("abc", "def"))  # False
    print(string_permutation_checker("", ""))  # True
