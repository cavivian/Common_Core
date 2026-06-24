<<<<<<< HEAD
from alchemy.grimoire.light_validator import validate_ingredients


def light_spell_allowed_ingredients() -> list[str]:
=======
def light_spell_allowed_ingredients() -> str:
>>>>>>> temp
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
<<<<<<< HEAD
    ingr = validate_ingredients(ingredients)
    return f"Spell recorded: {spell_name} ({ingr})"
=======
    if spell_name in light_spell_allowed_ingredients():
        return ingredients
>>>>>>> temp
