from typing import Callable, Tuple


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target}"


def heal(target: str, power: int) -> str:
    return f"Heals {target}"


def powerino(target: str, power: int) -> int:
    return power


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def comb(target: str, power: int) -> Tuple[str, str]:
        uno = spell1(target, power)
        due = spell2(target, power)
        return (uno, due)
    return comb


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def mult(target: str, power: int) -> str:
        new_power = power * multiplier
        return base_spell(target, new_power)
    return mult


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def controlli(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"
    return controlli


def spell_sequence(spells: list[Callable]) -> Callable:
    def lista(target: str, power: int) -> list:
        magie = []
        for incantesimo in spells:
            magie.append(incantesimo(target, power))
        return magie
    return lista


if __name__ == "__main__":
    print("Master the Ancient Arts of Functional Programming\n")

    print("Testing spell combiner...")
    combined = spell_combiner(fireball, heal)
    result = combined("Dragon", 10)
    print(f"Combined spell result: {result[0]}, {result[1]}")

    print("\nTesting power amplifier...")
    mega_power = power_amplifier(powerino, 3)
    print(f"Original: {powerino('Dragon', 10)}, "
          f"Amplified: {mega_power('Dragon', 10)}")

    print("\nTesting conditional caster...")

    def is_powerful(target: str, power: int) -> bool:
        return power > 50

    cast_if_strong = conditional_caster(is_powerful, fireball)
    print(cast_if_strong("Goblin", 80))
    print(cast_if_strong("Goblin", 20))

    print("\nTesting spell sequence...")
    sequence = spell_sequence([fireball, heal, powerino])
    print(sequence("Orc", 15))
