def string_sculptor(text: str) -> str:
    to_low: bool = True
    clean_text: str = ""
    for i in range(len(text)):
        if text[i].isspace():
            to_low = True
        if text[i].isalpha():
            if to_low:
                clean_text += text[i].lower()
                to_low = False
            else:
                clean_text += text[i].upper()
                to_low = True
        else:
            clean_text += text[i]
    return clean_text


if __name__ == "__main__":
    print(string_sculptor("Hello World!"))  # "hElLo wOrLd"
    print(string_sculptor("abc123def"))  # "aBc123DeF"
