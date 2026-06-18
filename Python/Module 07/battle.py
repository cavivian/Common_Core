from ex0 import CreatureFactory, FlameFactory, AquaFactory


def prova_factory(CreatureFactory):
    print ("Testing factory")
    primo = CreatureFactory.create_base()
    secondo = CreatureFactory.create_evolved()
    print(primo.describe())
    print(primo.attack())
    print(secondo.describe())
    print(secondo.attack())



def prova_battle(uno: CreatureFactory, due: CreatureFactory):
    print ("Testing battle")
    base_1 = uno.create_base()
    base_2 = due.create_base()
    print(base_1.describe())
    print(" vs.")
    print(base_2.describe())
    print("Fight!")
    print(base_1.attack())
    print(base_2.attack())



if __name__ == "__main__":
    fuoco = FlameFactory()
    prova_factory(fuoco)
    print()
    acqua = AquaFactory()
    prova_factory(acqua)
    print()
    prova_battle(fuoco, acqua)

    

    

