def parse(name_file) -> None:
    try:
    #try che serve per controllare effetivamente che ci sia il file
        with open(name_file, 'r') as file:
            #ciclo che scorre tutte le righe per leggere le informazioni
            for row in file:
                #serve per pulire la stringa da spazi bianchi e dalla \n a fine file
                clean_row = row.strip()
                #controlla se c'è una riga vuota
                if not clean_row:
                    continue
                #si divide la lista in due parti, dividendola con split
                parts = clean_row.split('=')
                #si cerca il numero delle parti splittate
                size = len(parts)
                #7se sono più di 1
                if size > 1:
                    #si crea una variabile a cui si assegna la parte di sinistra che riguarda il nome
                    name = parts[0]
                    #si controlla che sia composta solo da lettere
                    if not name.isalpha():
                        #si stampa il messaggio di errore se trova un numero
                        raise ValueError(f"invalid literal for int() with base 10: '{name}'")
                    #si dichiara un'altra variabile che contiene i valori numerici
                    value = parts[1]
                    #si controlla che sia composta solo da numeri
                    while size < len(parts) - 2:
                        print(f"{name}={value} ")
                        #si stampa il messaggio di errore di default
                        if value.isalpha():
                            raise ValueError(f"ValueError: invalid literal for int() with base 10: '{value}'.")
                #collegato al punto 7
                else:
                    print("Missing sign '='")
                    break
                print(f"{name}={value}")
    except FileNotFoundError as e:
        print(e)


def main() -> None:
    try:
        parse("config.txt")
    except RuntimeError as e:
        print(e)

if __name__ == "__main__":
    main()