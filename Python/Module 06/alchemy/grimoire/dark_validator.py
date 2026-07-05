from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    valid = ["bats", "frogs", "arsenic", "eyeball"]
    for ingredient in valid:
        if ingredient.casefold() in ingredients.casefold():
            return (f"{ingredients} - VALID")
    return (f"{ingredients} - INVALID")
