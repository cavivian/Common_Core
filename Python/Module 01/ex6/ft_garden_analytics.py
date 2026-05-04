class Plant:
    class Analytics:
        def __init__(self):
            self.grow_calls = 0
            self.age_calls = 0
            self.show_calls = 0
            self.shade_calls = 0

        def display(self):
            print(f'Stats: {self.grow_calls} grow, {self.age_calls} age, {self.show_calls} show')

        def display_tree(self):
            print(f'Stats: {self.grow_calls} grow, {self.age_calls} age, {self.show_calls} show, \n {self.shade_calls} shade')

    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.current_age = age
        self.stats = self.Analytics()

    def show(self):
        print(f'{self.name}: {self.height:.1f}cm, {self.current_age} days old')
        self.stats.show_calls += 1

    @classmethod
    def create_anonymus(cls):
        return cls(name = "Unknown plant", height =0.0, age=0)

    @staticmethod
    def age_control(age):
        if age < 365:
            print(f'Is {age} days more than a year? -> False')
        else:
            print(f'Is {age} days more than a year? -> True')
        
    def grow(self, value) -> float:
        self.height += value
        self.stats.grow_calls += 1
    
    def age(self, days) -> int:
        self.current_age += days
        self.stats.age_calls += 1

class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.color = color
        self.is_blooming = False

    def bloom(self):
        self.is_blooming = True

    def show(self):
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

    def produce_shade(self) -> str:
        print(f'Tree {self.name} now produce a shade of {self.height:.1f}cm long and {self.trunk_diameter:.1f}cm wide.')
        self.stats.shade_calls += 1

    def show(self):
        super().show()
        print(f' Trunk diameter: {self.trunk_diameter}cm')


class Seeds(Flower):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age, color)
        self.color = color
        self.is_blooming = False
        self.seed_count = 0

    def bloom(self):
        self.is_blooming = True

    def show(self):
        super().show()
        if self.is_blooming:
            self.seed_count = 42
            print(f' Seeds: {self.seed_count}')
        else:
            print(' Seeds: 0')

    def grow(self, value) -> float:
        self.height += value
        self.stats.grow_calls += 1
    
    def age(self, days) -> int:
        self.current_age += days
        self.stats.age_calls += 1


def main():
    print('=== Garden statistics ===')
    print('=== Check year-old')
    Plant.age_control(30)
    Plant.age_control(400)
    print('\n=== Flower')
    fiore = Flower('Rose', 15, 10, 'red')
    fiore.show()
    print(' [statistics for Rose]')
    fiore.stats.display()
    print(' [Asking the rose to grow and bloom]')
    fiore.bloom()
    fiore.show()
    print(' [Statstics for Rose]')
    fiore.stats.display()
    print('\n=== Tree')
    albero = Tree('Oak', 200, 365, 5)
    albero.show()
    print(' [statistics for Oak]')
    albero.stats.display_tree()
    print(' [Asking the Oak to produce shade]')
    albero.produce_shade()
    print(' [statistics for Oak]')
    albero.stats.display_tree()
    print('\n=== Seed')
    seme = Seeds('Sunflower', 80, 45, 'yellow')
    seme.show()
    print(' [Make sunflower grow, age and bloom]')
    seme.grow(30)
    seme.age(20)
    seme.bloom()
    seme.show()
    print(' [Statistics for Sunflower]')
    seme.stats.display()
    print('=== Anonymus')
    anonimo = Plant.create_anonymus()
    anonimo.show()
    print(' [Statistics for Unknown plant]')
    anonimo.stats.display()



if __name__ == "__main__":
    main()
