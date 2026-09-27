def shadow_merge(list1: list[str], list2: list[str]) -> list[str]:
	return sorted(list1 + list2)

if __name__ == "__main__":
    print(shadow_merge([1, 3, 5], [2, 4, 6]))
    print(shadow_merge([1, 1, 2], [1, 3, 3]))