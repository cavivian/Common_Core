from ex1 import CreatureFactory, HealingCreatureFactory, TransformCreatureFactory


def prova_factory(CreatureFactory):
    print ("Testing Creature with healing capability")
    print (" base:")
    primo = CreatureFactory.create_base()
    print(primo.describe())
    print(primo.attack())
    print(primo.heal())
    print(" evolved:")
    secondo = CreatureFactory.create_evolved()
    print(secondo.describe())
    print(secondo.attack())
    print(secondo.heal())


def prova_transform(CreatureFactory):
    print()
    print ("Testing Creature with transform capability")
    print(" base:")
    base = CreatureFactory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.transform())
    print(base.attack())
    print(base.revert())
    print (" evolved:")
    evo = CreatureFactory.create_evolved()
    print(evo.describe())
    print(evo.attack())
    print(evo.transform())
    print(evo.attack())
    print(evo.revert())


if __name__ == "__main__":
    heal = HealingCreatureFactory()
    transform = TransformCreatureFactory()
    prova_factory(heal)
    prova_transform(transform)
    

    

