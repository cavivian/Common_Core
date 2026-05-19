import random


# Definiamo i premi totali fuori come
# costante globale (così la funzione è pulita)
ACHIEVEMENTS = {
    'Crafting Genius', 'Strategist', 'World Savior', 'Speed Runner',
    'Survivor', 'Master Explorer', 'Treasure Hunter', 'Legendary Stuntman',
    'Master Alchemist', 'Silent Assassin', 'Resource Magnet', 'Dragon Slayer',
    'Unstoppable', 'First Steps', 'Collector Supreme', 'Untouchable',
    'Sharp Mind', 'Boss Slayer', 'Hidden Path Finder', 'Social Butterfly',
    'Marathon Runner', 'Puzzle Master', 'Night Owl'
}


def gen_player_achievements() -> set[str]:
    # Sceglie un numero casuale di obiettivi (es. tra 10 e 15)
    num = random.randint(10, 15)

    # Estrae il set di premi casuali dal totale
    premi = set(random.sample(list(ACHIEVEMENTS), num))

    # RESTITUISCE il set (questo è il return richiesto dal subject!)
    return premi


def main() -> None:
    print('=== Achievement Tracker System ===\n')

    players = ['Alice', 'Bob', 'Charlie', 'Dylan']
    salvataggio = {}

    # Per ogni giocatore, chiamiamo la funzione che GENERA e RITORNA il set
    for name in players:
        premi_ricevuti = gen_player_achievements()
        salvataggio[name] = premi_ricevuti
        print(f"Player {name}: {premi_ricevuti}")

    print(f"\nAll distinct achievements: {ACHIEVEMENTS}")

    # Calcolo dei premi in comune (Intersection)
    common = (salvataggio['Alice'] & salvataggio['Bob'] &
              salvataggio['Charlie'] & salvataggio['Dylan'])
    print(f"\nCommon achievements: {common}\n")

    # Ciclo per trovare i premi UNICI di ciascuno
    for name in salvataggio:
        miei_premi = salvataggio[name]

        # Creiamo il set degli altri
        premi_altri: set[str] = set()
        for altro_nome in salvataggio:
            if altro_nome != name:
                premi_altri = premi_altri.union(salvataggio[altro_nome])

        only = miei_premi.difference(premi_altri)
        print(f"Only {name} has: {only}")

    # Ciclo per trovare i premi MANCANTI di ciascuno
    for name in salvataggio:
        differences = ACHIEVEMENTS - salvataggio[name]
        print(f'\n{name} is missing: {differences}')


if __name__ == "__main__":
    main()
