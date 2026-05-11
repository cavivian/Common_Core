class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self._height = 15.0
        self._age = 30
        self.set_height(height)
        """serve come contenitore del dato, si usa dentro la classe,
        mai fuori. Serve per avere piu' privacy all'interno del codice"""
        self.set_age(age)

    def show(self) -> str:
        return (
            f'Plant created: {self.name}: '
            f'{self._height:.1f}cm, {self._age} days old'
        )

    def set_height(self, value) -> None:
        if value < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        elif value > 0:
            self._height = float(value)

    def set_age(self, value) -> None:
        if value < 0:
            print(f"{self.name}: Error, age can't be negative")
            print('Age update rejected')
        elif value > 0:
            self._age = int(value)

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def __str__(self) -> str:
        return f"{self.name}: {self._height:.1f}cm, {self._age} days old"


def main() -> None:
    print('=== Garden Security System ===')
    pianta = Plant("Rose", 15, 10)
    print(f'{pianta.show()}, \n')
    pianta.set_height(25)
    print('Height updated: 25cm')
    pianta.set_age(30)
    print('Age updated: 30 days \n')
    pianta.set_height(-25)
    pianta.set_age(-30)
    print()
    print(f'Current state: {pianta}')


if __name__ == "__main__":
    main()

# L'underscore serve a impedire che l'oggetto "Plant"
# finisca in uno stato assurdo (altezza o età negative).
# L'underscore _ è il muro, il metodo set è il guardiano al cancello.
