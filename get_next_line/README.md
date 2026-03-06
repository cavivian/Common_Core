*Questo progetto è stato creato come parte del curriculum 42 da <cavivian>*

# *get_next_line* 

_________

## Descrizione

`get_next_line` è una funzione in C che **legge una riga alla volta da un file descriptor**.

In pratica:

* Apre un file (o legge da input standard).
* Restituisce **una riga per volta**, inclusa la `\n` (se presente).
* Mantiene in memoria quello che non ha ancora restituito.

È un progetto molto famoso della scuola **42 School**, pensato per insegnare:

* gestione della memoria
* file descriptor
* variabili statiche
* lettura da file con `read()`

---

## Prototipo della funzione

```c
char *get_next_line(int fd);
```

### Parametri

* `fd` → file descriptor (restituito da `open()`)

### Ritorno

* Una stringa con la prossima riga
* `NULL` se:

  * fine del file
  * errore

---

## Come funziona (Spiegazione semplice)

1. Legge dal file usando `read()`
2. Salva il contenuto in una variabile statica
3. Controlla se trova un `\n`
4. Se trova `\n`:

   * restituisce la riga
   * salva il resto per la prossima chiamata
5. Se non trova `\n`:

   * continua a leggere
6. Quando finisce il file → ritorna `NULL`

---

## Cos’è un File Descriptor?

Un **file descriptor (fd)** è un numero che rappresenta un file aperto.

Esempio:

```c
int fd = open("file.txt", O_RDONLY);
```

Alcuni fd speciali:

* `0` → input standard
* `1` → output standard
* `2` → error standard

---

## BUFFER_SIZE

Nel progetto si usa una macro:

```c
#define BUFFER_SIZE 42
```

Indica quanti byte leggere ogni volta con `read()`.

Più è grande → meno chiamate a `read()`
Più è piccolo → più chiamate a `read()`

---

## Struttura tipica del progetto

Di solito il progetto è diviso così:

```
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

### get_next_line.c

Contiene la funzione principale.

### get_next_line_utils.c

Contiene funzioni di supporto:

* `ft_strlen`
* `ft_strjoin`
* `ft_strdup`
* `ft_substr`
* ecc.

### get_next_line.h

Header con:

* prototipi
* include
* definizione di `BUFFER_SIZE`

---

## Concetto importante: Variabile Statica

Esempio:

```c
static char *str;
```

Una variabile `static`:

* mantiene il valore tra una chiamata e l’altra
* è fondamentale per ricordare ciò che resta dopo aver restituito una riga

Senza `static`, la funzione dimenticherebbe tutto ogni volta.

---


## Risorse
### - Confronto diretto con gli altri studenti. 
### - ricerca su internet. Siti piu' utilizzati: codegrind.it, tutorialspoint.com 
### - Confronto con ChatGPT senza chiedere il codice pronto, usato invece come aiuto al ragionamento.
