def bracket_validator(s: str) -> bool:
	stack: list[str] = []
	pairs: dict[str, str] = {
		"{" : "}",
		"(" : ")",
		"[" : "]"
	}
	for bracket in s:
		if bracket in pairs:
			stack.append(bracket)
		elif bracket in pairs.values():
			if not stack:
				return False
			if pairs[stack.pop()] != bracket:
				return False
	return len(stack) == 0

if __name__ == "__main__":
    print(bracket_validator("()"))
    print(bracket_validator("()[]{}"))
    print(bracket_validator("(]"))
    print(bracket_validator("hello(world)["))