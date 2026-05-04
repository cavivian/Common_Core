class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> str:
        return f"{self.name}: {self.height}cm, {self.age} days old"
    
def main() -> None:
    print("=== Garden Plant Registry ===")
    pianta1 = Plant("Rose", 25, 30)
    pianta2 = Plant("Sunflower", 80, 45)
    pianta3 = Plant("Cactus", 15, 120)
    print(pianta1.show())
    print(pianta2.show())
    print(pianta3.show())

if __name__ == "__main__":
    main()
