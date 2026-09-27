def echo_validator(text: str) -> str:
    if text == "":
        return False
    clean_text: str = ""
    for c in text:
        if c.isalpha():
            clean_text += c
    return (clean_text == clean_text[::-1])
            


if __name__ == "__main__":
    print(echo_validator("  arara"))
    print(echo_validator("hello"))
    print(echo_validator(""))
    print(echo_validator("  "))