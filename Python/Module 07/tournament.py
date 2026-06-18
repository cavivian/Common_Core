from ex0.factory import CreatureFactory, FlameFactory, AquaFactory
from ex1.creature import Creature
from ex1.factory import CreatureFactory, HealingCreatureFactory, TransformCreatureFactory
from ex2.strategy import BattleStrategy, NormalStrategy, AggressiveStrategy, DefensiveStrategy, menage_error
from typing import List


def battle(opp: List):
    print ("*** Tournament ***")
    print(f"{len(opp)} opponents involved")
    coppie = []
    for factory, strategy in opp:
        crea = factory.create_base()
        coppie.append((crea, strategy))
    for i, (opp_1, strat_1) in enumerate(coppie):
        for (opp_2, strat_2) in coppie[i + 1:]:
            print(f"\n* Battle *")
            print(opp_1.describe())
            print(" vs.")
            print(opp_2.describe())
            print(" now fight!")
            try:
                strat_1.act(opp_1)
                strat_2.act(opp_2)
            except menage_error as e:
                print(f"Battle error, aborting tournament: {e}")
                return
    


if __name__ == "__main__":
    fuoco = FlameFactory()
    acqua = AquaFactory()
    heal = HealingCreatureFactory()
    transform = TransformCreatureFactory()
    norm = NormalStrategy()
    agg = AggressiveStrategy()
    defe = DefensiveStrategy()
    print("Tournament 0 (basic)")
    print("[(Flameling+Normal), (Healing+Defensive) ]")
    battle([(fuoco, norm), (heal, defe)])
    print("\nTournament 1 (error)")
    print("[(Flameling+Aggressive), (Healing+Defensive) ]")
    battle([(fuoco, agg), (heal, defe)])
    print("\nTournament 2 (multiple)")
    print("[(Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
    battle([(acqua, norm), (heal, defe), (transform,agg)])