import random

def gen_player_achievements():
    player = ['Alice', 'Bob', 'Charlie', 'Dylan'] #lista, può essere iterata
    actions = {'Crafting Genius', 'Strategist', 'World Savior', 'Speed Runner',
               'Survivor', 'Master Explorer', 'Treasure Hunter'} #set con ordine sparso, non può essere iterato
    actions2 = {'Unstoppable', 'First Steps', 'Collector Supreme', 'Untouchable', 'Sharp Mind', 'Boss Slayer'}
    tot = set.union(actions, actions2) #unione dei due set
    salvataggio = {} #dizionario
    i = 0 #per iterazione della lista 
    for name in player: #per ogni giocatore si stabilisce un numero e delle 'abilità' randomiche
        num = random.randint(5, 9)
        premi = set(random.sample(list(tot), num)) #estrazione randomica dei premi per ciascun giocatore
        salvataggio[name] = premi #salvataggio delle estrazioni per poterle confrontare dopo
        print(f"Player {player[i]}: {premi}")  #stampa delle varie estrazioni
        i += 1 #iterazione
    print(f"\nAll distinct achievements: {tot}")
    common = salvataggio[name] & salvataggio['Alice'] & salvataggio['Bob'] & salvataggio['Charlie'] & salvataggio['Dylan']
    print(f"\nCommon achievements: {common}")
    print()

    # Ciclo principale: prendiamo un giocatore alla volta
    for name in salvataggio:
        miei_premi = salvataggio[name]
    
    # Adesso creiamo un set che contiene i premi di TUTTI GLI ALTRI
        premi_altri = set()
        for altro_nome in salvataggio:
            if altro_nome != name: # Se il nome è diverso da quello che stiamo analizzando
            # Uniamo i suoi premi a quelli degli altri
               premi_altri = premi_altri.union(salvataggio[altro_nome])
    
    # Finalmente facciamo la differenza
        only = miei_premi.difference(premi_altri)
    
    # Stampiamo il risultato (Python stamperà set() se è vuoto)
        print(f"Only {name} has: {only}")
    for name in salvataggio:
        differences = tot - salvataggio[name]
        print(f'\n{name} is missing: {differences}')


def main():
    print('=== Achievement Tracker System ===')
    gen_player_achievements()


if __name__ == "__main__":
    main()
