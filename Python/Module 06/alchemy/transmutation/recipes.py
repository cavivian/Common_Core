<<<<<<< HEAD
from alchemy.elements import create_air
from alchemy.potions import strength_potion
from elements import create_fire
=======
import elements
from ..potions import strength_potion
from ..elements import create_air
>>>>>>> temp


def lead_to_gold() -> str:
    return(f"Recipe transmuting Lead to Gold: brew '{create_air()}' "
           f"and '{strength_potion()}' mixed with "
<<<<<<< HEAD
           f" '{create_fire()}'")
=======
           f" {elements.create_fire()}")
>>>>>>> temp
