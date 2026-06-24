<<<<<<< HEAD


def validate_ingredients(ingredients: str) -> str:
    valid = ["earth", "air", "fire", "water"]
    for ingredient in valid:
        if ingredient.casefold() in ingredients.casefold():
            return (f"{ingredients} - VALID")
        else:
            return (f"{ingredients} - INVALID")
    
=======
from light_spellbook import light_spell_record


def validate_ingredients(ingredients: str) -> str:
    if ingredients in light_spell_record():
        return ("VALID")
    else:
        return("INVALID")
>>>>>>> temp
