class Plant:
	def __init__(self, name: str, height: float, age: int) -> None:
		self.name = name
		self.height = height
		self.days = age

	def show(self) -> str:
		return f"Created: {self.name.capitalize()}: {self.height:.1f}cm, {self.days} days old"
	
	def grow(self) -> float:
		self.height += 1
		return self.height
	
	def age(self) -> int:
		self.days += 1
		return self.days


def main():
	print("=== Plant Factory Output ===")
	pianta1 = Plant("Rose", 25, 30)
	pianta2 = Plant("Oak", 200, 365)
	pianta3 = Plant("Cactus", 5, 90)
	pianta4 = Plant("Sunflower", 80, 45)
	pianta5 = Plant("Fern", 15, 120)

	print(pianta1.show())
	print(pianta2.show())
	print(pianta3.show())
	print(pianta4.show())
	print(pianta5.show())

if __name__ == "__main__":
	main()