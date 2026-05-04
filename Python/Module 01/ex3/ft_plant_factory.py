class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.days = age

    def show(self) -> str:
        return f"Created: {self.name.capitalize()}: {self.height:.1f}cm, {self.days} days old"

def main() -> None:
    print("=== Plant Factory Output ===")
    names = ["rose", "cactus", "oak", "daisy", "pine"]
    heights = [25.0, 200.0, 5.5, 80.0, 15.2]
    ages = [30, 365, 90, 80, 15]
    for n, h, a in zip(names, heights, ages):
        pianta = Plant(n, h, a)
        print(pianta.show())

if __name__ == "__main__":
    main()
