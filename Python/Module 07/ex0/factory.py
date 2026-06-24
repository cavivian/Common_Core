from abc import ABC, abstractmethod
from ex0.creature import Creature, Aquabub, Flameling, Pyrodon, Torragon


class CreatureFactory(ABC):

    @abstractmethod
    def create_base(self):
        pass

    @abstractmethod
    def create_evolved(self):
        pass


class FlameFactory(CreatureFactory):
    def create_base(self) -> None:
        return (Flameling())
    
    def create_evolved(self):
        return (Pyrodon())


class AquaFactory(CreatureFactory):
    def create_base(self):
        return (Aquabub())
    
    def create_evolved(self):
        return (Torragon())