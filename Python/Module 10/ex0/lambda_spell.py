def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return (sorted(artifacts,
                   key=lambda elemento: elemento['power'],
                   reverse=True))


def power_filter(mages: list[dict], min_power: int):
    return list(filter(lambda maghetti: maghetti['power'] >= min_power, mages))


def spell_transformer(spells: list[str]):
    return list(map(lambda stringa: "* "+stringa+" *", spells))


def mage_stats(mages: list[dict]):
    if not mages:  # Protezione contro la lista vuota
        return None, None, 0.0
    maxi = max(mages, key=lambda mago: mago['power'])
    mini = min(mages, key=lambda mago: mago['power'])
    media = round(sum(mago['power'] for mago in mages) / len(mages), 2)
    return (maxi, mini, media)


if __name__ == "__main__":
    artifacts = [{'name': "Fire Staff", 'power': 92, 'type': "fire"},
                 {'name': "Crystal Orb", 'power': 85, 'type': "glass"}]
    sortato = artifact_sorter(artifacts)
    print("Testing artifact sorter...")
    print(f"{sortato[0]['name']} ({sortato[0]['power']} power) comes before "
          f"{sortato[1]['name']} ({sortato[1]['power']} power)")

    magie = ["fireball", "heal", "shield"]
    print("\nTesting spell transformer...")
    transf = spell_transformer(magie)
    for magia in transf:
        print(magia, end=" ")
    print()
