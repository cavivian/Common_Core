from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1.creature import Creature
from ex1.capabilities import HealCapability, TransformCapability


class menage_error(Exception):
    pass

class BattleStrategy(ABC):
    
    @abstractmethod
    def is_valid(self, Creature) -> bool:
        pass

    @abstractmethod
    def act(self, Creature):
        pass



class NormalStrategy(BattleStrategy):
    
    def is_valid(self, Creature) -> bool:
        return True
    
    def act(self, Creature):
        if not self.is_valid(Creature):
           raise menage_error(f"Invalid Creature '{Creature.name}' for this normal strategy")
        print (Creature.attack())
         

class AggressiveStrategy(BattleStrategy):
    
    def is_valid(self, Creature):
        return isinstance(Creature, TransformCapability)
    
    def act(self, Creature):
        if not self.is_valid(Creature):
            raise menage_error(f"Invalid Creature '{Creature.name}' for this aggressive strategy")
        print(Creature.transform())
        print(Creature.attack())
        print(Creature.revert())
         

class DefensiveStrategy(BattleStrategy):
    
    def is_valid(self, Creature):
        return isinstance(Creature, HealCapability)
    
    def act(self, Creature):
        if not self.is_valid(Creature):
            raise menage_error(f"Invalid Creature '{Creature.name}' for this defensive strategy")
        print(Creature.attack())
        print(Creature.heal())
         