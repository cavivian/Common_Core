class Plant:
	def __init__(self, name: str, height: float, age: int) -> None:
		self.name = name
		self.height = height
		self.days = age

	def show(self) -> str:
		return f"Created: {self.name}: {self.height:.1f}cm, {self.days} days old"
	
	def	grow(self) -> int:
		self.height = float

def main() ->None:
	print("=== Plant Factory Output ===")
	nomepianta1 = Plant('Rose', 25, 30)
	print(nomepianta1.show())

if __name__ == "__main__":
	main()