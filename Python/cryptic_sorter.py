# def cryptic_sorter(strings: list[str]) -> list[str]:
#     """
#     Write a function that sorts a list of strings
# according to multiple criteria:
#     1. Primary sort: By string length (shortest first)
#     2. Secondary sort: ASCII order, except letters
# are compared case-insensitively
#    (for strings of same length)
#     3. Tertiary sort: By number of vowels (ascending,
# for same length and lexically equal)
#     4. Equal strings will appear in the same order as in the input list.
#     """
#     return sorted(
#         strings, key=lambda word:
#         (len(word),
#          word.lower(),
#          sum(c.lower() in 'aeiou' for c in word)
#          )
#     )


# if __name__ == "__main__":
#     print(cryptic_sorter(["apple","cat","banana","dog","elephant"]))
#     print(cryptic_sorter(["aaa","bbb","AAA","BBB"]))
#     print(cryptic_sorter(["hello","world","hi","test"]))
#     print(cryptic_sorter([]))
#     print(cryptic_sorter([""]))


# def inter(s1: str, s2: str) -> str:
#     """
#     Returns a string with the characters that appears
#     in both strings, without repetitions.
#     Characters are added in the order that
#     they appear in the first string.
#     """
#     res: str = ""
#     for c in s1:
#         if c not in res and c in s2:
#             res += c
#     return res


# if __name__ == "__main__":
#     print(inter("hello", "world"))
#     print(inter("abc", "xyz"))
#     print(inter("", "abc"))

# def echo_validator(text: str) -> bool:
#     """
#     Write a function that checks if a string is a palindrome,
#     ignoring spaces and case, only consider alphabetic characters
#     for the comparison
#     """
#     if text == "":
#         return False

#     clean_text: str = ""

#     for c in text:
#         if c.isalpha():
#             clean_text = clean_text + c.lower()
#     return (clean_text == clean_text[::-1])


# if __name__ == "__main__":
#     print(echo_validator("  arara"))
#     print(echo_validator("hello"))
#     print(echo_validator(""))
#     print(echo_validator("  "))


# def twist_sequence(arr: list[int], k: int) -> list[int]:
#     """
#     rotates an array to the right by k positions.
#     Rotating right by k means the last k elements move to the front.
#     """
#     if not arr:
#         return []
#     k %= len(arr)
#     return arr[-k:] + arr[:-k]


# if __name__ == "__main__":
#     print(twist_sequence([1,2,3,4,5], 2))
#     print(twist_sequence([1,2,3], 1))
#     print(twist_sequence([1,2,3], 5))
#     print(twist_sequence([], 3))


# def whisper_cipher(text: str, shift: int) -> str:
#     """
#     Creates a Caesar cipher by shifting letters in a
#     string by a given amount.
#     Non-alphabetic characters should remain unchanged.
#     The shift can be negative (shift left).
#     """
#     res: str = ""

#     for c in text:
#         if 'a' <= c <= 'z':
#             res += chr((ord(c) - ord('a') + shift) % 26 + ord('a'))
#         elif 'A' <= c <= 'Z':
#             res += chr((ord(c) - ord('A') + shift) % 26 + ord('A'))
#         else:
#             res += c

#     return res

# if __name__ == "__main__":
#     print(whisper_cipher('hello', 3))
#     print(whisper_cipher('ABC123def', 5))
#     print( whisper_cipher('abc', -1))
#     print(whisper_cipher('abc', 26))