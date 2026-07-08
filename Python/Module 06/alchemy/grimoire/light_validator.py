

def validate_ingredients(ingredients: str) -> str:
    from .light_spellbook import light_spell_allowed_ingredients
    valid = light_spell_allowed_ingredients()
    for ingredient in valid:
        if ingredient.casefold() in ingredients.casefold():
            return (f"{ingredients} - VALID")
    return (f"{ingredients} - INVALID")
