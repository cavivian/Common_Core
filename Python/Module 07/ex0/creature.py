from abc import ABC, abstractmethod


class Creature(ABC):
    def __init__(self, name: str, types: str):
        self.name = name
        self.type = types

    def describe(self) -> str:
        return(f"{self.name} is a {self.type} type Creature")
    
    @abstractmethod
    def attack(self):
        pass


class Flameling(Creature):
    def __init__(self):
        super().__init__('Flameling', 'Fire')


    def attack(self):
        return (f"{self.name} uses Ember!")


class Pyrodon(Creature):
    def __init__(self):
        super().__init__('Pyrodon', 'Fire/Flying')

    def attack(self):
        return (f"{self.name} uses Flamethrower!")


class Aquabub(Creature):
    def __init__(self):
        super().__init__('Aquabub', 'Water')
       

    def attack(self):
        return (f"{self.name} uses Water Gun!")
    

class Torragon(Creature):
    def __init__(self):
        super().__init__('Torragon', 'Water')
        

    def attack(self):
        return (f"{self.name} uses Hydro Pump!")
    
if __name__ == "__main__":
    pass