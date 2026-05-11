class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.height = height
        self.a = age

    def show(self) -> None:
        print(f'{self.name}: {self.height:.1f}cm, {self.a} days old')

    def grow(self, value) -> None:
        self.height += value

    def age(self, days) -> None:
        self.a += days


class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.color = color
        self.is_blooming = False

    def bloom(self) -> None:
        self.is_blooming = True

    def show(self) -> None:
        super().show()
        print(f' Color: {self.color}')
        if self.is_blooming:
            print(f' {self.name} is blooming succesfully!')
        else:
            print(f' {self.name} has not bloomed yet')


class Tree(Plant):
    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        print(
            f'Tree {self.name} now produce a '
            f'shade of {self.height}cm '
            f'long and {self.trunk_diameter}cm wide.'
        )

    def show(self) -> None:
        super().show()
        print(f' Trunk diameter: {self.trunk_diameter}cm')


class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def grow_and_age(self, days, growth) -> None:
        self.age(days)
        self.grow(growth)
        self.nutritional_value += days  # aumenta con l'eta'

    def show(self) -> None:
        super().show()
        print(f' Harvest season: {self.harvest_season}')
        print(f' Nutritioal value: {self.nutritional_value}')


def main():
    print('=== Garden Plant Types ===')
    print('=== Flower')
    fiore = Flower('Rose', 15, 10, 'red')
    fiore.show()
    print("[Asking the rose to bloom]")
    fiore.bloom()
    fiore.show()
    print('\n=== Tree')
    albero = Tree('Oak', 200.0, 365, 5.0)
    # print('Oak: 200.0cm, 365 days old')
    albero.show()
    print('[Asking the oak to produce shade]')
    albero.produce_shade()
    print('\n=== Vegetable')
    ortaggi = Vegetable('Tomato', 5, 10, 'April')
    # print('Tomato: 5.0cm, 10 days old')
    ortaggi.show()
    print('[Make tomato grow and age for 20 days]')
    ortaggi.grow_and_age(20, 42)
    ortaggi.show()


if __name__ == "__main__":
    main()
