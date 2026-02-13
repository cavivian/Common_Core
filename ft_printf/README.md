*Questo progetto è stato creato come parte del curriculum 42 da < cavivian >*

# *ft_printf* 

_________

## Descrizione
### **ft_printf** progetto della 42 che consiste nel ricreare il comportamento della funzione *printf()*. Deve essere in grado di stampare caratteri, stringhe, void *, numeri decimali, interi a base 10, unsigned int in base 10, numeri in formato esadecimali minuscolo, numeri in formato esadecimale maiuscolo e il segno percentuale.
### 
    int ft_printf (const char *format, ...)
### e' la funzione principale, senza la quale il programma non funziona. Funzione che ritorna un int e che ha come parametri una stringa const e le funzioni variadiche. Quest'ultime servono per passare gli argomenti delle altre funzioni.
### in questa funzione avvengono dei controlli, che se verificati, si collegano alle rispettive funzioni. **ft_printf** ritorna il numero il numero dei caratteri stampati.
### Nel primo controllo, si incontra
	int ft_count(char a, va_list *ap)
### Questa funzione serve a contare il numero di caratteri che ft_printf dovra' stampare. Usa la funzione variadica per passare gli argomenti e specificare i loro tipi di dato; mentra "char a" corrisponde alla lettera dopo il "%".

### **stampe da riprodurre**
	void ft_putchar(char c)
### usato per "%c" e "%%" per stampare i caratteri.
	int ft_putstr(char *str)
### usato per "%s"per stampare stringhe.
	int ft_putint(int n)
### usato per "%i" e "%d" per stampare numeri in base 10.
	int ft_puthexlow(unsigned long nb, char a)
### usato per "%x" per stampare numeri in base 16 in lowercase.
	int ft_puthexupp(unsigned long nb)
### usato per "%X" per stampare numeri in base 16 in uppercase.
	int	ft_putnullpoint(void *c)
### usato per "%p" per stampare gli indirizi di memoria.
	int	ft_putunsnbr(unsigned int nb)
### usato per "%u" per stampare i numeri in base 10 unsigned.
__________

## Istruzioni
### 1. Compilare il programma:

```C
make
``` 

### 2. Eliminare file oggetto: 

```C
make clean 
``` 

### 3. Eliminare l'eseguibile:
```C
make fclean 
```
__________ 

## Risorse
### - Confronto diretto con gli altri studenti. 
### - Ricerca su Internet. Siti piu' utilizzati: codegrind.it, tutorialspoint.com 
### - Confronto con ChatGPT senza chiedere il codice pronto, usato invece come aiuto al ragionamento.
