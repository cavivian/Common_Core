class Plant:
	def __init__(self, name: str, height: float, age: int) -> None:
		self.name = name
		self.height = height
		self.days = age


	def show(self) -> str:
		return f"{self.name}: {self.height:.1f}cm, {self.days} days old"
	
	def grow(self) -> float:
		self.height += 8/10
		return self.height

	def	age(self):
		self.days += 1
		return self.days

def main():
	print("=== Garden Plant Growth ===")
	nome_pianta = Plant('Rose', 25.0, 30)
	for days in range(1, 8):
		print(f"=== Day {days} ===")
		print(nome_pianta.show())
		nome_pianta.grow()
		nome_pianta.age()
	print(f"Growth his week: {(days) * 8 / 10}")

if __name__ == "__main__":
	main()