from abc import ABC, abstractmethod
from ex1.capabilities import HealCapability, TransformCapability


class Creature(ABC):
    def __init__(self, name: str, types: str):
        self.name = name
        self.type = types

    def describe(self) -> str:
        return(f"{self.name} is a {self.type} type Creature")

    @abstractmethod
    def attack(self) -> str:
        pass


class Sproutling(Creature, HealCapability):
    def __init__(self):
        super().__init__('Sproutling', 'Grass')

    def attack(self) -> str:
        return (f"{self.name} uses Vine Whip!")

    def heal(self) -> str:
        return (f"{self.name} heals itself for a small amount")


class Bloomelle(Creature, HealCapability):
    def __init__(self):
        super().__init__('Bloomelle', 'Grass/Fairy')

    def attack(self) -> str:
        return (f"{self.name} uses Petal Dance!")

    def heal(self) -> str:
        return(f"{self.name} heals itself and others for a large amount")


class Shiftling(Creature, TransformCapability):
    def __init__(self):
        super().__init__('Schiftling', 'Normal')
        TransformCapability.__init__(self)

    def attack(self) -> str:
        if self.bloom is True:
            return (f"{self.name} perform a boosted strike!")
        else:
            return (f"{self.name} attacks normally.")

    def transform(self) -> str:
        self.bloom = True
        return (f"{self.name} shifts into a sharper form!")

    def revert(self) -> str:
        self.bloom = False
        return (f"{self.name} returns to normal.")


class Morphagon(Creature, TransformCapability):
    def __init__(self):
        super().__init__('Morphagon', 'Normal/Dragon')
        TransformCapability.__init__(self)

    def attack(self) -> str:
        if self.bloom is True:
            return (f"{self.name} unleashes a devastating morph strike!")
        else:
            return(f"{self.name} attacks normally.")

    def transform(self) -> str:
        self.bloom = True
        return(f"{self.name} morphs into a dragonic battle form!")

    def revert(self) -> str:
        self.bloom = False
        return (f"{self.name} stabilizes its form.")
