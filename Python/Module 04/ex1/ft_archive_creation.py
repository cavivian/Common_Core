import sys


def ft_archive_creation():
    i = 1
    j = len(sys.argv) - 1
    if i == j:
        nome_file = sys.argv[i]
        print(f"Accessing file '{nome_file}'")
        try:
            with open(nome_file, "r") as nome_file:
                contenuto = nome_file.read()
                print('---')
                print(f"\n{contenuto}")
                print("\n---")
                print(f"File '{nome_file}' closed")
            print("\nTransform data:\n")
            print('---')
            # Trasformiamo il contenuto riga per riga
            # Usiamo readlines() per mantenere i caratteri originali
            with open(nome_file, "r") as nome_file:
                righe_originali = nome_file.readlines()
            testo_trasformato = ""
            for riga in righe_originali:
                # Togliamo solo l'ultimo invio, mettiamo # e lo rimettiamo
                riga_con_hash = riga.rstrip('\n') + "#"
                print(f"\n{riga_con_hash}")
                testo_trasformato += riga_con_hash + "\n"

            print("\n---")
        except FileNotFoundError as e:
            print(f"Error opening file '{nome_file}': {e}")
        print("\n---")
        name = input("Enter new file name (or empty): ")
        try:
            f = open(name)
            f.read()
            print(f"Saving data to '{name}'")
            print(f"Data saved in file '{name}'")
            f.close()
        except Exception:
            raise ("Not saving data")


def main():
    if len(sys.argv) > 1:
        print("=== Cyber Archives Recovery & Preservations ===")
    ft_archive_creation()


if __name__ == "__main__":
    main()
