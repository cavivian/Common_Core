def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:
	for num in matrix:
		num.reverse()
	return matrix

if __name__ == "__main__":
    print(mirror_matrix([[1, 2, 3], [4, 5, 6]]))