def validate_ingredients(ingredients: str) -> str:
    valid = ["earth", "air", "fire", "water"]
    for ingredient in valid:
        if ingredient.casefold() in ingredients.casefold():
            return (f"{ingredients} - VALID")
    return (f"{ingredients} - INVALID")
