This project has been created as part of the 42 curriculum by *cavivian*

# Push_swap
## Description
Il progetto Push_swap prevede la creazione di un algoritmo, che con il minor numero possibile di mosse, ordina dei numeri passati come parametri. L'algoritmo utilizzato è il Chunk, che divide gli stack in sotto gruppi. Per semplificare il processo di identificazione dei numeri più grandi, e qundi risparmiare mosse totali, ho creato la funzione indexing. Essa trasforma i valori reali in una sequenza da 0 a N-1. Questo permette all'algoritmo di ignorare l'entità dei numeri (es. 100, 5000, 2) e lavorare solo sulla loro posizione relativa, ottimizzando la gestione dei chunk. Questo permette inoltre di stabilire dei range entro i quali i numeri saranno inclusi per l'ordinamento. Infatti il mio algoritmo divide il chunk precendentemente diviso in altri mini chunk. È proprio dentro questi mini chunk che avvengono le mosse.

Il mio progetto è in grado di accettare i parametri sia passati con le virgolette (es. ./push_swap "42 33 1 2"), sia senza (es. ./push_swap 42 33 1 2), che misti (es. ./push_swap "42 33 1 2" 4 6 "98") grazie all'implemento della funzione ft_split.

L'obbiettivo è creare un algoritmo efficiente.

## Instructions
Il programma non ha bisogno di particolari comandi lanciati dal terminale. Oppure può essere testato usando il checker.

Alcuni esempi:

*./push_swap*  -> nessun risultato atteso

*./push_swap 42* -> nessun risultato atteso perchè già ordinato

*./push_swap 1 2 3* -> nessun risultato atteso

*./push_swap 1 2 a 4* -> risultato atteso: Error

*./push_swap 1 2 3 2* -> risultato atteso: Error

*./push_swap 2147483648* -> risultato atteso: Error

*./push_swap -2147483649* -> risultato atteso: Error

*./push_swap + -* -> risultato atteso: Error

### test con il checker
*ARG= "2 1 0"; ./push_swap $ARG | ./checker.linux $ARG*

*ARG= "1 5 2 4 3"; ./push_swap $ARG | ./checker.linux $ARG*

### test randomici
*ARG=$(shuf -i 1-100 -n 100); ./push_swap $ARG | wc -l*

*ARG=$(shuf -i 1-500 -n 500); ./push_swap $ARG | wc -l*

*ARG=$(shuf -i 1-500 -n 500); ./push_swap "$ARG" | wc -l*

### test che potrebbero crashare
*./push_swap ""*

*./push_swap "  "*

*./push_swap 1 "2 3 4" 5 "6 7"*

*./push_swap 00001 0002 3*

### test con Valgrind

*ARG=$(shuf -i 1-100 -n 100); valgrind --leak-check=full ./push_swap $ARG*

## Resources
Per questo progetto ho usato i consigli degli altri studenti, relativi soprattutto alla scelta dell'algoritmo e sull'opzione lista/array.
Siti come Codegrind.com, w3schools.com, learn-c.org, youtube.com per vari approfondimenti.
Ho usato l'AI principalmente per farmi spiegare i motivi di seg.fault e come spalla per il ragionamento dell'intero algoritmo e progetto. 