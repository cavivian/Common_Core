class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age

    def show(self):
        print(f'{self.name}: {self.height:.1f}cm, {self.age} days old')

    @staticmethod
    def age_control(age):
        if age < 365:
            print(f'Is {age} days more than a year? -> False')
        else:
            print(f'Is {age} days more than a year? -> True')

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

class Seeds(Flower):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age, color)

def main():
    print('=== Garden statistics ===')
    print('=== Check year-old')

if __name__ == "__main__":
    main()