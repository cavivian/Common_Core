def light_spell_allowed_ingredients() -> str:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    if spell_name in light_spell_allowed_ingredients():
        return ingredients