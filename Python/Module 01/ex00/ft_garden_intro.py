def	ft_garden_intro():
	return('=== Welcome to My Garden ===')

def main():
	print(f"{ft_garden_intro()}")
	p = str(input("Plant: "))
	h = int(input("Height: " + "cm"))
	a = int(input("Age:  "+"days"))
	print("=== End of Program===")

if __name__ == "__main__":
	main()