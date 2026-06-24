from light_spellbook import light_spell_record


def validate_ingredients(ingredients: str) -> str:
    if ingredients in light_spell_record():
        return ("VALID")
    else:
        return("INVALID")