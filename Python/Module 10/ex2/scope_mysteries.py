from typing import Callable


def mage_counter() -> Callable:
    count = 0

    def counter() -> int:
        nonlocal count
        count += 1
        return count
    return counter


def spell_accumulator(initial_power: int) -> Callable:
    total = initial_power

    def accumul(quant: int) -> int:
        nonlocal total
        total += quant
        return total
    return accumul


def enchantment_factory(enchantment_type: str) -> Callable:
    def enchanta(item: str) -> str:
        return f"{enchantment_type} {item}"
    return enchanta


def memory_vault() -> dict[str, Callable]:
    memory = {}

    def store(key: str, value) -> None:
        # nonlocal memory
        memory[key] = value

    def recall(key: str) -> object:
        if key in memory:
            return memory[key]
        return "Memory not found"

    return {'store': store, 'recall': recall}


if __name__ == "__main__":

    print("Testing mage counter...")
    a = mage_counter()
    b = mage_counter()
    print(f"counter_a call 1: {a()}")
    print(f"counter_a call 2: {a()}")
    print(f"counter_b call 1: {b()}")

    print("\nTesting spell accumulator...")
    acc = spell_accumulator(100)
    print(f"Base 100, add 20: {acc(20)}")
    print(f"Base 100, add 30: {acc(30)}")

    print("\nTesting enchantment factory...")
    flaming = enchantment_factory("Flaming")
    frozen = enchantment_factory("Frozen")
    print(flaming("Sword"))
    print(frozen("Shield"))

    print("\nTesting memory vault...")
    vault = memory_vault()
    vault['store']('secret', 42)
    print("Store 'secret' = 42")
    print(f"Recall 'secret': {vault['recall']('secret')}")
    print(f"Recall 'unknown': {vault['recall']('unknown')}")
