class Plant:
	def __init__(self, name: str, height: int, age: int) -> None:
		self.name = name
		self.height = height
		self.age = age


	def show(self) -> str:
		return f"{self.name}: {self.height}cm, {self.age} days old"
	
	def grow() -> int:
		