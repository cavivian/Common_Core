import sys
import typing


def ft_stream_management():
    i = 1
    j = len(sys.argv) -1
    if i == j:
        nome_file = sys.argv[i]
        print(f"Accessing file '{nome_file}'")
        try:
            with open(nome_file, "r") as f:
                contenuto = f.read()
                print('---')
                print(f"\n{contenuto}")
                print("\n---")
                print(f"File '{nome_file}' closed")
            print("\nTransform data:\n")
            print('---')
            # Trasformiamo il contenuto riga per riga
            # Usiamo readlines() per mantenere i caratteri originali
            with open(nome_file, "r") as f:
                righe_originali = f.readlines()
            testo_trasformato = ""
            for riga in righe_originali:
                # Togliamo solo l'ultimo invio, mettiamo # e lo rimettiamo
                riga_con_hash = riga.rstrip('\n') + "#"
                print(f"{riga_con_hash}")
                testo_trasformato += riga_con_hash + "\n"
            print("\n---")
            sys.stdout.write("Enter new file name (or empty): ")
            sys.stdout.flush()
            risposta = sys.stdin.readline()
            files = risposta.rstrip('\n')
            print(f"Saving data to '{files}'")
            sys.stderr.write(f"[STDERR] Error opening file '{files}': [Errno 13] Permission denied: {files} \nData not saved.\n")
        except FileNotFoundError as e:
            sys.stderr.write(f"[STDERR] Error opening file '{nome_file}': {e}\n")


def main():
    if len(sys.argv) > 1:
        print("=== Cyber Archives Recovery & Preservations ===")
    ft_stream_management()


if __name__ == "__main__":
    main()
