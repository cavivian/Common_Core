class Plant:
	def __init__(self, name: str, height: float, age: int):
		self.name = name
		self.height = height
		self.age = age

	def show(self) -> str:
		return f"Plant created: {self.name}: {self.height:.1f}cm, {self.age} days old"
	
	def set_height(self) -> int:
		alt = int(input("Height update: "))
		self.height = alt
		if self.height < 0:
			print(f"{self.name}: Error, height can't be negative")
			print("Height update rejected")
		elif self.height > 0:
			print(f"Height update: {self.height}cm")


	def set_age(self) -> int:
		eta = int(input('Age update: '))
		self.age = eta
		if self.age < 0:
			print(f"{self.name}: Error, age can't be negative")
			print('Age update rejected')

	def get_height(self) -> int:
		pass

	def get_age(self) -> int:
		pass
	
def main():
	print('=== Gardeb Security System ===')
	pianta = Plant("Rose", 15, 10)


if __name__ == "__main__":
	main()