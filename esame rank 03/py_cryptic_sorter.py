def cryptic_sorter(strings: list[str]) -> list[str]:
    return sorted(strings, key=lambda word:
                  (len(word),
                   word.lower(),
                   sum(c.lower() in 'aeiou' for c in word)))


if __name__ == "__main__":
    print(cryptic_sorter(["apple", "cat", "banana", "dog", "elephant"]))
    # cat dog apple banana elephant
    print(cryptic_sorter(["aaa", "bbb", "AAA", "BBB"]))  # aaa AAA bbb BBB
    print(cryptic_sorter(["hello", "world", "hi", "test"]))  # hi test hello
    # world
    print(cryptic_sorter([]))
    print(cryptic_sorter([""]))
