def pattern_tracker(text: str) -> int:
    i: int = 0
    counter: int = 0
    for c in text:
        if c.isdigit() and i + 1 < len(text) \
             and text[i + 1].isdigit() and c < text[i + 1]:
            counter += 1
        i += 1
    return counter


if __name__ == "__main__":
    print(pattern_tracker("1a2b3c4"))  # risultato atteso = 0
    print(pattern_tracker("123"))  # risultato atteso = 2
    print(pattern_tracker("9876543210"))  # risultato atteso = 0
    print(pattern_tracker("1234"))
