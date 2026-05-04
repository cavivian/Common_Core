import random

def gen_player_achievements():
    player = {'Alice', 'Bob', 'Charlie', 'Dylan'}
    actions = {'Crafting Genius', 'Strategist', 'World Savior', 'Speed Runner',
               'Survivor', 'Master Explorer', 'Treasure Hunter'}
    actions2 = {'Unstoppable', 'First Steps', 'Collector Supreme', 'Untouchable', 'Sharp Mind', 'Boss Slayer'}
    tot = set.union(actions, actions2)
    salvataggio = {}
    for name in player:
        num = random.randint(5, 9)
        premi = set(random.sample(list(tot), num))
        salvataggio[name] = premi
        print(f"Player {name}: {premi}")
    print(f"\nAll distinct achievements: {tot}")
    common = salvataggio['Alice'].intersection(salvataggio['Bob'], salvataggio['Charlie'], salvataggio['Dylan'])
    print(f"\nCommon achievements: {common}")
    for name in salvataggio:
        difference = set.difference(salvataggio['Alice'], common)
        print(f'\n{name} is missing: {difference}')


def main():
    print('=== Achievement Tracker System ===')
    gen_player_achievements()

if __name__ == "__main__":
    main()
