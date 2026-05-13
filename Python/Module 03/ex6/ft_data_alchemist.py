import random

def main() -> None:
    print("=== Game Data Alchemist ===")
    player = ['Alice', 'bob', 'Charlie', 'dylan', 'Emma', 'Gregory', 'jhon',
              'kevin', 'Liam']
    print(f"\nNew list of players: {player}")
    nomi_capitalizzati = [nome.capitalize() for nome in player]
    print(f"New list with all name capitalized: {nomi_capitalizzati}")
    words_capitalize = [name for name in player if name.istitle()]
    print(f"New list of capitalized name only: {words_capitalize}")
    dict = {}
    for name in nomi_capitalizzati:
        numb = random.randint(1, 1000)
        dict[name] = numb
    print(f"Score dict: {dict}")
    total_quantity = sum(dict.values())
    media = total_quantity / len(dict)
    print(f"Score average is {media:.2f}")
    high_scores = {}
    for name, score in dict.items():
        if score >= media:
            high_scores[name] = score
    print(f"High score: {high_scores}")


if __name__ == "__main__":
    main()
    