#include <unistd.h>
#include <stdio.h>

//ft_putchar -> funzione che prende come parametro un char e lo stampa

void ft_putchar(char c) //dichiarazione della funzione con passaggio del parametro
{
    write(1, &c, 1);  //stampa del parametro utilizzando l'indirizzo.
}                     //se scrivessi semplicemente c, stamperebbe il carattere, non il parametro passato

// int main()
// {
// 	ft_putchar('a');
// }


//ft_print_alphabet -> funzione che stampa l'alfabeto completo
// void ft_print_alphabet(void) //non si passa nessun parametro perchè non serve
// {

//     char lettera = 'a'; //partiamo dal primo carattere dell'alfabeto
//     while(lettera >= 'a' && lettera <= 'z') //si scorre finquando non si arriva alla z
//     {
//         ft_putchar(lettera); //stampa della lettera attraverso una funzione esterna
//         lettera++; //si incrementa la lettera per andare avanti, siccome è un char si può fare
//     }              //se fosse stata una stringa non sarebbe andata bene, bisognava avere anche un indice
//     write(1, "\n", 1); //si stampa la new line come richiesto dal subject
// }


// ft_print_reverse_alphabet -> funzione che stampa  l'alfabeto all'incovercio
// void ft_print_reverse_alphabet(void) // non si passa nessun parametro perchè non ne abbiamo bisogno
// {
// 	int i = 'z'; // si parte dall'ultima lettera dell'alfabeto
//     while (i >= 'a') // inquando la lettera non arriva alla a
//     {
// 		ft_putchar(i); // stampa l'alfabeto
//         i--; // e decrementa, poichè è dalla fine all'inizio
//     }
// 	write(1, "\n", 1);
// }

// int main()
// {
// 	ft_print_reverse_alphabet();
// }


// ft_print_numbers -> funzione che stampa i numeri dallo 0 al 9
// void ft_print_numbers() // non si passa nessun parametro
// {
//     int i = 48; // si inizializza la variabile a 0
//     while(i <= 57) // finquando non arriva al 9
//     {
//         ft_putchar(i); // stampa i numeri
//         i++; // e incrementa
//     }
//     write(1, "\n", 1);
// }

// int main()
// {
// 	ft_print_numbers();
// }


// ft_is_negative -> funzione che stampa P se un numero è positivo e N se è negativo
// void ft_is_negative(int n) // in questo caso si passa un parametro
// {
//     if (n < 0) // controllo se il parametro è minore di 0
//         write(1, "N\n", 2); // in caso di esito positivo stampa la N
//     else if (n >= 0) // controllo se il parametro è maggiore o uguale di 0
//         write(1, "P\n", 2); // stampa P in questo caso
// }

// int main()
// {
// 	ft_is_negative(-5);

// 	ft_is_negative(0);

// 	ft_is_negative(42);
// }


// ft_char_type -> funzione che stampa un carattere diverso in base al tipo di dato pasato
// void ft_char_type(char c) //si passa come parametro il tipo di dato che vogliamo controllare
// {
//     if (c >= 'a' && c <= 'z') //se il carattere è compreso nell'alfabeto in minuscolo
//         ft_putchar('m'); //la funzione stamperà m
//     else if (c >= 'A' && c <= 'Z') //se invece è compreso nell'alfabeto maiuscolo
//         ft_putchar('M'); //stampa M
//     else if(c >= '0' && c <= '9') //se è compreso tra 0 e 9
//         ft_putchar('N'); //stampa N
//     else if((c >= 9 && c <= 13) || c == 32) //se invece è uno spazio/tabulazione/altro
//         ft_putchar('?'); //stampa ?
// }


// int main()
// {
// 	ft_char_type('a');
// 	ft_char_type('M');
// 	ft_char_type('9');
// 	ft_char_type(32);
// }



// ft_putstr -> funzione che stampa una stringa passata come parametro
// void ft_putstr(char *str) //passiamo la stringa come parametro
// {
//     int i = 0; //inizializiamo l'indice a zero con cui scorrere la stringa
//     while(str[i] != '\0') //finquando la stringa non arriva alla fine
//     {
//         ft_putchar(str[i]); //stampiamo tutti i caratteri che compongono la stringa
//         i++; //e incrementiamo
//     }
// }

// int main()
// {
// 	char *str = "ciao mamma!";
// 	ft_putstr(str);
// }


// ft_strlen -> funzione che conta il numero di caratteri in una stringa
int ft_strlen(char *str) //in questo caso la funzione ha il tipo di ritorno
{
    int i = 0; //inizializiamo l'indice a 0
    while (str[i] != '\0') //finquando la stringa esiste
    {
        i++; //incrementala, ogni volta i ha il valore aggioranato del numero dei caratteri
    }
    return (i); //ritorna il numero dei caratteri contati nel ciclo
}

// int main()
// {
// 	char *str= "ciao mamma!";
// 	printf("%d\n", ft_strlen(str));
// 	return 0;
// }


// ft_lowercase -> funzione che converte le lettere maiuscole in minuscole
// void ft_lowercase(char *str) //prende una stringa come parametro
// {
//     int i = 0; //inizializiamo l'indice a 0
//     while(str[i] != '\0') //si scorre la lista finquando esiste
//     { 
//         if (str[i] >= 'A' && str[i] <= 'Z') //se il carattere della stringa è compresa nell'alfabeto maiuscolo
//         {
//             str[i] = str[i] + 32; //si converte la stringa in minuscolo
//         }
//         write(1, &str[i], 1);
//         i++; //si va avanti
//     }
// 	write(1, "\n", 1);
// }

// int main()
// {
//     char str[] = "ciAo MaMma";
//     ft_lowercase(str);
//     return 0;
// }


//ulstr -> funzione che inverte i case, le maiuscole diventano minuscole e viceversa
// int main(int argc, char *argv[])
// {
//     if (argc != 2) //se argc non è 2
//     {
//         write(1, "\n", 1); //stampa la newline 
//         return 0; //e si ritorna
//     }
//     int i = 0; //inizializiamo l'indice a 0
//     while (argv[1][i] != '\0') //e scorriamo argv1 finquando esiste
//     {
// 		if(!(argv[1][i] >= 'A' && argv[1][i] <= 'Z') && !(argv[1][i] >= 'a' && argv[1][i] <= 'z')) // deve essere in grado di scrivere tutt gli altri caratteri
// 			write (1, &argv[1][i], 1);
//         if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') //se la stringa ha i char compresi nell'alfabeto maiuscolo
// 		{
// 			argv[1][i] += 32; //li converte in minuscoli
// 			write (1, &argv[1][i], 1); //e li stampa
// 		}
//         else //sennò se sono compresi nell'alfabeto minuscolo
// 		{
// 			argv[1][i] -= 32; //li converte in maiuscolo
// 			write (1, &argv[1][i], 1); //e li stampa
// 		}
//         i++; //si incrementa la i
//     }
//     write(1, "\n", 1); //si stampa la newline
//     return 0; //si termina il programma
// }


// first_word -> funzione che stampa la prima parola che trova in argv1
// int main(int argc, char *argv[])
// {
//     if (argc != 2) //se argv1 è diverso da 2
//     {
//         write(1, "\n", 1); //stampa la newline
//         return 0; //termina il programma
//     }
//     int i = 0; //inizializiamo l'indice a 0
//     if(argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13)) //se si incontrano spazi o caratteri speciali si avanza
//     {
//         i++; //incremento
//     }
//     while ((argv[1][i] != '\0' && argv[1][i] != 32) || (argv[1][i] >= 9 && argv[1][i] <= 13)) //finquando argv1 esiste e non è nè uno spazio nè un carattere speciale
//     {
//         write(1, &argv[1][i], 1); //stampa argv
//         i++; //e incrementa
//     }
//     write(1, "\n", 1); //stampa la newline
//     return 0; //termina il programma
// }


//rotone -> funzione che stampa il carattere successivo alfabetico
// int main(int argc, char *argv[])
// {
//     if (argc != 2) //se argv non è 2
//     {
//         write(1, "\n", 1); //stampa la newline
//         return 0; //e termina il programma
//     }
//     int i = 0; //inizializiamo l'indice a 0
//     while (argv[1][i] != '\0') //finquando argv1 esiste
//     {
//         if (argv[1][i] >= 'a' && argv[1][i] <= 'z') //se il char è compreso nell'alfabeto minuscolo
//         {
//             if(argv[1][i] == 'z') //si fa un controllo che se è la 'z'
//                 argv[1][i] = 'a'; //il carattere dopo deve essere una 'a'
//             else //altrimenti
//                 argv[1][i] += 1; //gli assegna la lettera alfabetica dopo
//         }
//         else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z') //se invece il char è compreso nell'alfabeto maiuscolo 
//         {
//             if(argv[1][i] == 'Z') //si fa il controllo se è una 'Z'
//                 argv[1][i] = 'A'; //perchè in questo caso il carattere successivo deve essere la 'A'
//             argv[1][i] += 1; //gli assegna il carattere successivo
//         }
//         write(1, &argv[1][i], 1); //stampa la temporanea
//         i++; //e incrementa l'indice
//     }
//     write(1, "\n", 1); //stampa la newline
//     return 0; //termina il programma
// }


//rev_print -> funzione che stampa un argomento passato all'incovercio
// int main(int argc, char *argv[])
// {
//     if (argc != 2) //si controlla che i parametri siano 2
//     {
//         write (1, "\n", 1); //nel caso si stampa la newline
//         return 0; //si termina il programma
//     }
//     int i = 0; //si inizializza l'indice a 0
//     int tmp = 0;
//     while (argv[1][i] != '\0') //e scorriamo argv1 finquando esiste
//     {
//         i++; //lo scorriamo
//     } //sottraiamo di 1 per iniziare la decrementazione
//     tmp = i - 1;
//     while (tmp >= 0) //una volta arrivati alla fine della stringa
//     {
//         write(1, &argv[1][tmp], 1); //e stampiamo i char
//         tmp--; //e decrementiamo
//     }
//     write(1, "\n", 1); //stampiamo la newline 
//     return 0; //cwterminiamo il programma
// }


//serach_and_replace -> funzione che cerca un char e lo rimpiazza con un altro
// int main(int argc, char *argv[])
// {
//     if (argc != 4 || argv[2][0] == '\0' || argv[2][1] != '\0' || argv[3][0] == '\0' || argv[3][1] != '\0') //facciamo una serie di controlli 
//     {
//         write (1, "\n", 1); //stampiamo la newline
//         return 0; //termina il programma
//     }
//     int i = 0; //inizializiamo l'indice a 0
//     char tmp = argv[3][0]; //dichiariamo una temporanea che contiene il char di sostituzione
//     while (argv[1][i] != '\0') //scorriamo tutta argv1
//     {
//         if (argv[1][i] == argv[2][0]) //quando troviamo che un char di argv1 è uguale a uno di argv2 
//         {
//             argv[1][i] = tmp; //assegnamo a argv1 la temporanea
//         }
//         write(1, &argv[1][i], 1); //stampiamo argv1
//         i++; //incrementiamo la i
//     }
//     write(1, "\n", 1); //si stampa la newline
//     return 0; //si termina il programma
// }


//repeat_alpha -> funziona che ristampa la lettera dell'alfabeto in base alla posizione in cui si trova
// int main(int argc, char *argv[])
// {
//     if (argc != 2) //si controlla che argv sia 2
//     {
//         write(1, "\n", 1); //si stampa la newline
//         return (0); //e si termina il programma
//     }
//     int i = 0; //inizializiamo l'indice a 0
//     int lettere_da_stampare; //creiamo un contatore per le lettere
//     while (argv[1][i] != '\0') //scorriamo tutta argv1
//     {
//         lettere_da_stampare = 1; //inizializiamo il contatore a 1, che ogni volta si resetta
//         if(argv[1][i] >= 'a' && argv[1][i] <= 'z') //controlliamo se il char fa parte dell'alfabeto minuscolo
//         {
//             lettere_da_stampare = argv[1][i] - 'a' + 1; //fa il conteggio di quante lettere stampare
//         }
//         else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z') //controlla se il char in considerazione f aparte dell'alfabeto maiuscolo
//         {
//             lettere_da_stampare = argv[1][i] - 'A' + 1; //fa il conteggio di quante lettere stampare
//         }
//         while(lettere_da_stampare > 0) //si fa un ciclo in cui stampare le lettere finquando sono più di 0, ciclo sempre vero perchè lettere parte da 1
//         {
//             write(1, &argv[1][i], 1);  //si stampano le lettere
//             lettere_da_stampare--; //si decrementano
//         }
//         i++; //avanziamo argv1
//     }
//     write(1, "\n", 1); //stampiamo la newline
//     return 0; //si termina il programma
// }



//ft_strcpy -> funzione che copia una stringa in un'altra
// char *ft_strcpy(char *s1, char * s2) //si passano come parametri due stinghe
// {
//     int i = 0; //inizializiamo un indice a 0
//     int j = 0; //inizializiamo un altro indice a 0
//     while (s2[i] != '\0') //scorriamo la stringa che deve essere copiata
//     {
//         s1[j] = s2[i]; //e la assegnamo all'altra stringa passata per parametro
//         i++; //incrementiamo un indice
//         j++; //incrementiamo anche l'altro
//     }
//     s1[j] = '\0'; //una volta finito terminiamo la string acon il carattere terminatore
//     return(s1); //e ritorniamo la stringa con la copia
// }

// int main(void)
// {
//     char sorgente[] = "Tutto Copito!";
//     char destinazione[50]; // Un contenitore vuoto abbastanza grande

//     ft_strcpy(destinazione, sorgente);
	
//     // Stampiamo la destinazione per vedere se la copia è riuscita
//     printf("Sorgente: %s\n", sorgente);
//     printf("Destinazione: %s\n", destinazione); 
	
//     return (0);
// }


//last_word -> funzione che stampa l'ultima parola di una stringa
// int main(int argc, char *argv[])
// {
//     if (argc != 2) //si controlla ceh i parametri passati siano 2
//     {
//         write(1, "\n", 1); //si stampa la newline
//         return 0; //si termina il programma
//     }
//     int i = 0; //indice che mi serve per scorrere intanto tutta la stringa
//     int j = 0; //indice che mi serve per memorizzare dove si trova l'ultima parola
//     while(argv[1][i] != '\0') //finquando argv1 esiste
//     {
//         i++; //arriva infondo
//     }
//     i--; //e decrementa di uno per stare sull'ultima lettera dell'ultima parola
//     if (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13)) // qui e' importante che ci sia scritto argv, non solo la i
//         i--;
//     while((argv[1][i] >= 1 && argv[1][i] != 32) && !(argv[1][i] >= 9 && argv[1][i] <= 13)) //ciclo finchè argv è maggiore= a 1, perchè così si evita che stampi roba a caso
//     //in memoria
//     {
//         i--; //si decrementa
//     }
//     j = i + 1; //si assegna a j la posizione dell'ultima parola
//     while(argv[1][j] != '\0') //scorriamo argv con la nuova posizione
//     {
//         write(1, &argv[1][j], 1); //stampiamo
//         j++; //e si incrementa
//     }
//     write(1, "\n", 1); //si stampa la newline
//     return 0; //termina il programma
// }



//union -> programma che prende 2 parametri e li unisce senza stampare duplicati(stesso procedimento di inter, aggiungendo solo un print)
// int main(int argc, char *argv[])
// {
//     if (argc != 3) //si controlla che i parametri siano 2
//     {
//         write(1, "\n", 1); //in caso si stampa la new line
//         return 0; //e si termina il programma
//     }
//     int i = 0; //si inizializza l'indice a 0
//     char tmp[256] = {0}; //si dichiara una temporanea con lunghezza di 256 caratteri(tab ASCII)
//     while(argv[1][i] != '\0') //si fa partire il ciclo finquando esiste
//     {
//         if(tmp[(int)argv[2][i]] == 0) //si fa subito un controllo dei duplicati
//         {
//             write(1, &argv[2][i], 1); //se non ci sono stampa i caratteri di argv
//             tmp[(int)argv[2][i]] = 1; //e li accende per dire che ci è già passata sopra 
//         }
//         i++; //si incrementa
//     }
//     i = 0; //si resetta a 0 l'indice
//     while(argv[2][i] != '\0') //si scorre argv2 finquando esiste
//     {
//         if(tmp[(int)argv[2][i]] == 0) //si controlla che il carattere non sia già status stampato
//         {
//             write(1, &argv[2][i], 1); //nel caso si stampa
//             tmp[(int)argv[2][i]] = 1; //e si imposta a 1 per accenderlo
//         }
//         i++; //si incrementa
//     }
//     write(1, "\n", 1); //si stampa la newline
//     return 0; //termina il programma
// }


//alpha_mirror -> funzione che stampa lo specchio dell'alfabeto ( a = z)
// int main(int argc, char *argv[]) //funzione che prende i parametri passati dal terminale
// {
//     if (argc != 2) //si controlla che sia solo un parametro  
//     {
//         write(1, "\n", 1); //se sono più di uno si stampa la newline
//         return 0; //si termina il programma
//     }
//     int i = 0; //si inizializza l'indice a 0
//     while (argv[1][i] != '\0') //si scorre tutta argv1 finquando esiste
//     {
//         if (argv[1][i] >= 'a' && argv[1][i] <= 'z') //si controlla che il suo contenuto sia compreso nell'alfabeto minuscolo
//         {
//             argv[1][i] = 'a' + 'z' - argv[1][i]; //se si, lo si trasforma nel suo specchio
//         }
//         else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z') //si controlla che il suo contenuto sia compreso nell'alfabeto maiuscolo
//         {
//             argv[1][i] = 'A' + 'Z' - argv[1][i]; //si trasforma nel suo specchio
//         }
//         write(1, &argv[1][i], 1); //si stampa fuori dai controlli, sennò i numeri o i caratteri speciali non li stampa
//         i++; //si avanza l'indice
//     }
//     write(1, "\n", 1); //si stampa la newline
//     return 0; //termina il programma
// }


//wdmatch -> funzione che stampa i caratteri della prima stringa solo se sono nello stesso ordine nella seconda
// int main(int argc, char *argv[])
// {
//     if (argc != 3) //si controlla che i parametri siano 2
//     {
//         write(1, "\n", 1); //si stampa la newline
//         return 0; //si termina il programma
//     }
//     int i = 0; //si inizializza l'indice di argv1 a 0
//     int j = 0; //si inizilaizza l'indice di argv2 a 0
//     while(argv[2][j] != '\0' && argv[1][i] != '\0') //si scorre argv2 e argv1 finquando esistono
//     {
//         if(argv[2][j] == argv[1][i]) //si controlla che i caratteri dei due parametri siano uguali
//         {
//             i++; //incrementiamo la i
//         }
//         j++; //si incrementa
//     }
//     if(argv[1][i] == '\0') //si controlla che la i si trovi sul carattere nullo
//     {
//         int n = 0; //si dichiara un nuovo indice per la temporanea
//         while (argv[1][n] != '\0') //si scorre la temporanea finquando esiste
//         {
//             write(1, &argv[1][n], 1); //si stampa la temporanea
//             n++; //si incrementa
//         } 
//     }
//     write(1, "\n", 1); //si stampa la newline 
//     return 0; //si termina il programma
// }


// camel_to_snake -> funzione che stampa un trattino basso prima di una maiuscola
// int main(int argc, char *argv[])
// {
// 	if (argc != 2) // prima si controlla che i parametri siano 2
// 	{
// 		write(1, "\n", 1); // altrimenti si stampa la newline
// 		return 0; // e si termina il programma
// 	}
// 	int i = 0; // inizializiamo l'indice a zero
// 	while (argv[1][i] != '\0') //si scorre tutta argv
// 	{
// 		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') //se troviamo un carattere maiuscolo
// 		{
// 			if (i == 0) // qui si fa il controllo se la prima lettera passata e' maiuscola
// 				argv[1][i] += 32; // va convertita in minuscolo
// 			else //altrimenti, se non e' la prima lettera 
// 			{
// 				write(1, "_", 1); //si stampa il trattino basso
// 				argv[1][i] += 32; //e si converte il maiuscolo in minuscolo
// 			}
// 		}
// 		write(1, &argv[1][i], 1); //si stampa la stringa
// 		i++; //e si avanza
// 	}
// 	write(1, "\n", 1); //una volta finito si stampa la newline
// 	return 0; //e si termina il programma
// }


 #include <stdio.h>
// ft_atoi -> funzione che converte una stringa di numeri in int
// int ft_atoi(const char *str)
// {
// 	int i = 0; //indice per scorrere la stringa
// 	int sign = 1; 
// 	int result = 0; //variabile per memorizzare
// 	if (!str[i]) //si controlla che la stringa esista
// 		return 0; //nel caso si termina il programma
// 	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32) //ogni volta che c'è uno spazio
// 		i++; //si incrementa
// 	if (str[i] == '-' || str[i] == '+') //si guarda se ha segni
// 	{
// 		if(str[i] == '-') //se ha il meno
// 			sign = -1; //si imposta il segno a -1
// 		i++; //e si incrementa
// 	}
// 	while (str[i] >= 48 && str[i] <= 57) //se si trova nel range dei numeri
// 	{
// 		result = result * 10 + (str[i] - 48); //si salva su result il risultato di tutti i controlli fatti
// 		i++; //si incrementa
// 	}
// 	return(result * sign); //si ritorna
// }


// int	main()
// {
// 	printf("%d\n", ft_atoi("   -2147483648"));
//     printf("%d\n", ft_atoi("1234a5"));
//     return (0);
// }


// is_power_of_2 -> funzione che determina se un numero è una potenza di 2
// int is_power_of_2(unsigned int n) //si passa come parametro un unsigned perchè non può essere negativo
// {
// 	if (n != 0) //se appena si passa è zero //si termina il programma
// 	{
// 		while(n % 2 == 0) //se il numero passato non ha resto
// 			n = n/2; //n è divisibile per 2
// 		if (n == 1) //se è uno 
// 			return 1; //si termina il programma con successo 
// 	}
// 	return 0; //si termina
// }

// int main()
// {
// 	printf("%d\n", is_power_of_2(9));
// 	printf("%d\n",is_power_of_2(18));
// 	printf("%d\n",is_power_of_2(4));
// }


// ft_strrev -> funzione che inverte una stringa
// char *ft_strrev(char *str) //funzione che prende una stringa come parametro
// {
// 	int start = 0; //creiamo una variabile di inizio
// 	int end = 0; //creiamo una variabile di fine
// 	char tmp; //e una variabile temporanea per fare lo swap
// 	if (!str) //se la stringa non esiste 
// 		return 0; //si termina il programma
// 	while (str[end] != '\0') //finquando end non arriva in fondo alla stringa
// 	{
// 		end++;  //si incrementa
// 	}
// 	end--; //e si decrementa di 1
// 	while (start < end) //si fa un altro ciclo finquando start non arriva a end 
// 	{
// 		tmp = str[start]; //la temporanea contiene start
// 		str[start] = str[end]; //poi passiamo end alla start
// 		str[end] = tmp; //e assegnamo a end la temporanea che contiene la start
// 		start++; //si incrementa la start
// 		end--; //e si decrementa end
// 	}
// 	return (str); //si ritorna la stringa modoficata
// }

// int main()
// {
// 	char str[] = "ciaoo";
// 	printf("%s\n", ft_strrev(str));
// }


// epur_str -> programma che prende una stringa e la visualizza con esattamente uno spazio
// int main(int argc, char *argv[])
// {
// 	if (argc != 2) //si controlla che gli argomenti passati siano 2
// 	{
// 		write(1, "\n", 1); //si stampa la newline
// 		return 0; //si termina il programma
// 	}
// 	int i = 0; //indiciziamo l'indice di scorrimento a 0
// 	int flag = 0; //si dichiara una variabile che si accende solo per una certa condizione
// 	while (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13)) //finquando si trovano spazi o caratteri speciali, se metto if, fa solo un controllo
// 	{
// 		i++; //si incrementa
// 	}
// 	while (argv[1][i] != '\0') //si scorre tutta argv1 finchè esiste
// 	{
// 		if (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13)) //se la i è uno spazio o un carattere speciale
// 		{
// 			flag = 1; //la flag si attiva
// 		}
// 		else //altrimenti 
// 		{
// 			if (flag == 1) //se la flag si è accesa
// 			{
// 				write(1, " ", 1); //si scrive uno spazio
// 				flag = 0; //e si spegne la flag
// 			}
// 			write(1, &argv[1][i], 1); //altrimenti si scrive la stringa
// 		}
// 		i++; //si incrementa la i
// 	}
// 	write(1, "\n", 1); //si stampa la newline
// 	return 0; //si termina il programma
// }


// str_capitalizer -> prigramma che prende 1 o + stringhe  e trasforma in maiuscolo la prima lettera della parola
// int main(int argc, char *argv[])
// {
// 	if (argc < 2) //se gli argomenti passati sono meno di 2
// 	{
// 		write (1, "\n", 1); //si stampa una newline
// 		return 0; //e si termina il programma
// 	}
// 	int i; //indice per scorrere le stringhe
// 	int arg = 1; //per scorrere i più argomenti passati con ac, av
// 	while (arg < argc) //finquando gli argomenti passati sono meno di argc
// 	{
// 		i = 0; //inizializiamo l'indice a 0
// 		while (argv[arg][i] != '\0') //e si scorre argv finchè non arriva alla fine
// 		{
// 			if ((argv[arg][i] >= 'a' && argv[arg][i] <= 'z') || (argv[arg][i] >= 'A' && argv[arg][i] <= 'Z')) //se il carattere corrente è una lettere maiusc o minusc
//             {
//                 if (i == 0 || argv[arg][i - 1] == ' ' || argv[arg][i - 1] == '\t')  //se è la prima oppure quella prima è uno spazio o un tab
//                 {
//                     if (argv[arg][i] >= 'a' && argv[arg][i] <= 'z') //se è compresa nell alfabeto minuscolo
//                         argv[arg][i] -= 32; //si converte in maiuscolo
//                 }
//                 else //altrimenti
//                 {
//                     if (argv[arg][i] >= 'A' && argv[arg][i] <= 'Z') //se è compresa nelle lettere maiuscole
//                         argv[arg][i] += 32; //si converte in minuscolo
//                 }
// 			}
// 			write(1, &argv[arg][i], 1); //si scrivono le stringhe
// 			i++; //si incrementa la i
// 		}
// 		write(1, "\n", 1); //si stampa la newline
// 		arg++; //e si aumentano gli argomenti
// 	}
// 	return 0; //si termina il programma
// }


// rstr_capitalizer -> programma che stampa l'ultima lettera di una parola in maiuscolo
// int main(int argc, char *argv[])
// {
// 	if(argc < 2) //se gli argomenti sono meno di 2
// 	{
// 		write(1, "\n", 1); //si stampa la mewline
// 		return 0; //e si termina il programma
// 	}
// 	int arg = 1; //inizializiamo il conteggio degli argomenti a 1
// 	int i; //inizializiamo l'indice a 0
// 	while(arg < argc) //finquando gli arg sono meno di argc
// 	{
// 		i = 0;
// 		while(argv[arg][i] != '\0') //finquando non si arriva alla fine della stringa
// 		{
// 			if ((argv[arg][i] >= 'a' && argv[arg][i] <= 'z') || (argv[arg][i] >= 'A' && argv[arg][i] <= 'Z')) //se è una lettera
//             {
//                  if (argv[arg][i + 1] == '\0' || argv[arg][i + 1] == ' ' || argv[arg][i + 1] == '\t')  //e quella dopo è la fine o un tab o uno spazio
//                  {
//                      if (argv[arg][i] >= 'a' && argv[arg][i] <= 'z') //se il char è minuscolo
//                          argv[arg][i] -= 32; //si converte in maiuscolo
//                  }
//                  else //altrimenti
//                  {
//                      if (argv[arg][i] >= 'A' && argv[arg][i] <= 'Z') //se il char è maiuscolo
//                        argv[arg][i] += 32; //si converte in minuscolo
//                  }
//  			}
//  			write(1, &argv[arg][i], 1); //si stampa la stringa
//  			i++; //si incrementa la i
// 		}
// 		arg++; //si va avanti con gli argomenti
// 		write(1, " ", 1);
// 	}
// 	write(1, "\n", 1); //si stampa la newline
// 	return 0; //e si termina il programma
// }


// hidendp -> funzione che ritorna 1 se i char sono nello stesso ordine 
// int main(int argc, char *argv[])
//  {
//      if (argc != 3) //controlliamo che i parametri passati siano 3
//      {
//          write(1, "\n", 1); //altrimenti si stampa la newline
//          return 0; //e si termina il programma
//      }
//      int i = 0; //inizializiamo l'indice per il primo parametro
//      int j = 0; //inizializiamo l'indice per il secondo parametro
//      while(argv[2][j] != '\0' && argv[1][i] != '\0') //finquando esistono tutti e due
//      {
//          if(argv[2][j] == argv[1][i]) //se un char del 2 par è uguale a un char del 1
//          {
//              i++; //si incrementa l'indice del 1 parametro
//          }
//          j++; //si incrementa l'indice del secondo parametro
//      }
//      if(argv[1][i] == '\0') //se il primo parametro è finito
// 	 {
//         write(1, "1", 1); //si stampa l'1
//         write(1, "\n", 1); //e si va a capo
//      }
//      else //altrimenti non è andato a buon fine
//     {
//         write(1, "0", 1); //si stampa 0
//         write(1, "\n", 1); //e si stampa la newline
//     }
//     return 0; //termina il programma
// }


// void ft_putchar(char c)
// {
//     write (1, &c, 1);
// }


int ft_atoi(const char *str) //passiamo alla funzione una stringa come parametro
{
    if (!str) //se la stringa non esiste
        return 0; //terminiamo il programma
    int i = 0; //indicizializiamo a 0
    int sign = 1; //si setta il segno a 1
    int result = 0;  //il risultato a 0
    while((str[i] >= 9 && str[i] <= 13) || str[i] == 32) //se la stringa è nei caratteri speciali
        i++; //si va avanti
    while(str[i] == '+' || str[i] == '-') //se è un + o un -
    {
        if (str[i] == '-') //se è un -
            sign = -1; //il segno è -1
        i++; //si incrementa
    }
    while(str[i] >= 48 && str[i] <= 57) //finquando la stringa è compresa tra lo 0 e il 9
    {
        result = result * 10 + (str[i] - 48);  //il risultato è la moltiplicazione di sè setsso * 10 + la str convertita in int
        i++; //si incrementa
    }
    return (result * sign); //si ritorna il risultato per il segno
}


//ft_putnbr -> funzione che scrive i numeri
int ft_putnbr(int n) //si passa coem parametro un int
{
    if (n == -2147483648) //se è maggiore del massimo e del minimo
    {
        write(1, "-2147483648", 11); //scrive il numro minimo stampabile con int
        return  0;
    }
    if (n < 0) //se è minore di 0
    {
        ft_putchar('-'); //si stampa il - prima del numero
        n *= -1; //e si moltiplica l'int per -1
    }
    if (n < 10) //se è maggiore di 10
    {
		ft_putnbr(n / 10); //si divide per 10
		ft_putchar(n % 10 + 48); //e si stampa il resto
    }
    else //altrimenti
    {
		ft_putchar(n + 48); //si converte in stringa e si stampa con putchar
    }
	return (n);
}

// int main()
// {
// 	ft_putnbr('a');
// }


// tab_mult -> programma che prende un numero intero positivo come parametro e visualizza la sua tabella di moltiplicazione da 1 a 9.
// int main(int argc, char *argv[]) 
// {
//     if (argc != 2) //controlliamo che gli argomenti passati siano 2
//     {
//         write(1, "\n", 1); //altrimenti si stampa la newline
//         return 0; //e si termina il programma
//     }
//     int n = 1; //e un int a 1
//     int conv = ft_atoi(argv[1]); //variabile che serve per fare la conversione in int dei char passati come parametri
//     while (n >= 1 && n <= 9)  //finquando n è compreso tra 1 e 9
//     {
//         ft_putnbr(n); //stampa il numero
//         write(1, " x ", 3); //stampa l ax per la moltiplicazione
//         ft_putnbr(conv); //stampa la conversione da char a int
//         write(1, " = ", 3); //stampa l'uguale
//         ft_putnbr(n * conv); //stampa il risultato tra l'int e la conversione
//         write(1, "\n", 1); //stampa la newline
//         n++; //va avanti con la n
//     }
//     return 0; //termina il programma
// }


// ft_putnbr_base -> funzione che stampa i numeri in formato esadecimale
// void ft_putnbr_base(int n) si passa un int come parametro
// {
//    char *base = "0123456789abcdef"; gli si passa una stringa come base d'apppoggio per la conversione
//    if (n >= 16) se l'int passato è maggiore di 16
//    {
//         ft_putnbr_base(n / 16); dividilo per 16
//    }
//    write(1, &base[n % 16], 1); e stampi il resto usando la stringa
// }


// is_prime -> funzione che controlla se il numero passato è un numero primo
// int is_prime(int n) //si passa un int come parametro
// {
//    if (n <= 1) //se n è negativo o uguale a uno 
//    {
//       return 0; //si termina il programma (1 è un numero primo)
//    }
//    int div = 2; //si divide partendo da 2 (tutti i numeri sono divisibili per 1)
//    while(div < n) //finquando il divisore è minore del dividendo
//    {
//       if(n % div == 0) //se il resto da risultato 0, vuoldire che è un int primo
//       {
//          return 0; //si termina il programma
//       }
//       div++; //altrimenti andiamo avanti
//    }
//    return 1; //se è andato liscio dentro il ciclo while, vuol dire che non erano primi quindi ritorna 1
// }

// int main()
// {
// 	printf("%d\n", is_prime(7));
// 	printf("%d\n", is_prime(670));
// 	printf("%d\n", is_prime(89));
// 	printf("%d\n", is_prime(18));
// }


// funzione collegata a is_prime, è il suo main
// int main(int argc, char *argv[])
// {
//    if (argc != 2) si controlla che i parametri passati siano esattamente 2
//    {
//       write(1, "\n", 1); altrimenti si stampa la newline
//       return 0; e si termina il programma
//    }
//    int i = 2; anche qui si inizializza a 2, perchè 1 è primo
//    int conv = ft_atoi(argv[1]); facciamo la conversione di argv
//    int result = 0; e creiamo un avariabile per salvare il risultato
//    while (i <= conv) stessa condizione del ciclo di is_prime
//    {
//       if (is_prime(i) == 1) se il numero trovato dalla funzione è primo
//       {
//          result = result + i; lo sommi insieme a tutti gli altri che hai trovato
//       }
//       i++; e vai avanti
//    }
//    ft_putnbr(result); si stampa il risultato
//    write(1, "\n", 1); si stampa la newline
//    return 0; si termina il programma
// }


// pgcd -> funzione che calcola il massimo comune divisore di due numeri passati per parametri
// int main(int argc, char *argv[])
// {
//    if (argc != 3) //si controlla che gli argomenti passati siano esattamente 3
//    {
//       write(1, "\n", 1); //altrimenti si stampa la newline
//       return 0; //e si termina il programma
//    }
//    int value1 = ft_atoi(argv[1]); //si converte in int argv1
//    int value2 = ft_atoi(argv[2]); //e anche argv2
//    int tmp = 0; //si crea una temporanea per memorizzare value2
//    while (value2 != 0) //si controlla che solo value2 sia diverso da 0, perchè lui è il risultato della divisione
//    {
//       tmp = value2; //quindi si assegna alla temporanea il valore di value2
//       value2 = value1 % value2; //value2 diventa il risultato del resto tra value1 e value2
//       value1 = tmp;  //value1 adesso ha il valore iniziale di value2
//    }
//    printf("%d\n", value1); //quindi alla fine del ciclo value1 avrà il risultato
//    return 0; //si termina il programma
// }


// lcm -> funzione che calcola l'mcm
// unsigned int lcm(unsigned int a, unsigned int b)
// {
//    if ( a == 0 || b == 0) //si controlla che i numeri passati non siano 0
//       return 0; //e si termina il programma
//    unsigned int n = 0; //temporanea per calcolare quale dei 2 numeri passati è maggiore
//    if (a > b) //se il maggiore è a
//       n = a;  //n prende il suo valore
//    else //se invece è b
//       n = b; //n prende il valore di b
//    while (n > 0) //finquando n è più grande di 0 (è necessario un ciclo infinito)
//    {
//       if (n % a == 0 && n % b == 0) //se non hanno resto 
//       {
//          return(n); //si torna il risultato dell'mcm
//       }
//       n++; // e si incrementa la n
//    }
//    return 0; //si termina il programma
// }


// // collegato alla funzione lcm sopra
// int main() //main per la funzione dell'mcm
// {
//    unsigned int a = 256; //inizializzo i numeri
//    unsigned int b = 94; //e anche il secondo

//    printf("%d\n", lcm(a, b)); //stampo il risultato
//    return 0; //termino il programma
// }


// epur_str -> funzione che se trova più spazi ne stampa solo uno
// int epur_str(char *str) //prende una stringa come parametro
// {
//     if (!str)//se la stringa non esiste
//         return (0); //il programma termina
//     int i = 0; //inizializiamo l'indice a 0
//     int flag = 0; //e la flag per il controllo degli spazi
//     while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32) //tutte le volte che incontra uno spazio all'inizio o alla fine della stringa
//         i++; //va avanti senza contarlo
//     while (str[i] != '\0') //finquando esiste la stringa
//     {
//         if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32) //se trova uno spazio o un carattere speciale
//         {
//             flag = 1; //la flag  si attiva
//         }
//         else //altrimenti
//         {
//             if (flag == 1) //se la flag è attiva e quindi ha trovato uno spazio
//             {
//                 write(1, " ", 1); //ne stampa solo uno
//                 flag = 0; //e imposta la flag come disattivata
//             }
//             write(1, &str[i], 1); //scrive la stringa
//         }
//         i++; //incrementa la stringa
//     }
//     write(1, "\n", 1); //stampa la newline 
//     return 0; //e termina il programma
// }


// // collegato all'esercizio epur_str
// int main()
// {
//     char *str = " ciao  mamma                       dove         andiamo ";
//     epur_str(str);
//     return 0;
// }


// expand_str -> funzione che stampa 3 spazi quando ne incontra 1
// int expand_str(char *str) //prende una stringa come parametro
// {
//     if (!str) //se non esiste
//         return (0); //il programma termina
//     int i = 0; //si inizializza l'indice a zero
//     int flag = 0; //si setta la flag a spenta
//     while((str[i] >= 9 && str[i] <= 13) || str[i] == 32) //finquando incontra uno spazio o un char speciale
//         i++; //va avanti
//     while(str[i] != '\0') //finquando la stringa esiste
//     {
//         if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32) //se è uno spazio o una tab
//         {
//             flag = 1; //si setta la flag come accesa perchè l'ha trovato
//         }
//         else //altrimenti
//         {
//             if (flag == 1) //se la flag è 1, quindi accesa
//             {
//                 write(1, "   ", 3); //stampa 3 spazi
//                 flag = 0; //e la spenge
//             }
//             write(1, &str[i],1); //si scrive sempre la stringa a prescindere dalle condizioni
//         }
//         i++; //e si incrementa
//     }
//     write(1, "\n", 1); //si stampa la newline
//     return 0; //e si termina il programma
// }


// // collegato alla funzione expand_str
// int main()
// {
//     char *str = " ciao mamma ";
//     expand_str(str);
//     return 0;
// }


// ft_print_str -> funzione che mi serve per stampare i numeri
// void ft_print_putnbr(int nbr) // gli passiamo la n della nostra funzione come parametro 
// {
// 	char c;

// 	if (nbr >= 10)
// 		ft_print_putnbr(nbr / 10);
// 	c = (nbr % 10) + 48;
// 	write(1, &c, 1);
// }



// int fizzbuzz(void)
// {
// 	int n = 1;
// 	while (n <= (10 * 10))
// 	{
// 		if(n % 3 == 0 && n % 5 != 0)
// 			write(1, "fizz", 4);
// 		else if(n % 5 == 0 && n % 3 != 0)
// 			write(1, "buzz", 4);
// 		else if (n % 3 == 0 && n % 5 == 0)
// 			write(1, "fizzbuzz", 8);
// 		else
// 			ft_print_putnbr(n);
// 		write(1, "\n", 1);
// 		n++;
// 	}
// 	return 0;
// }

// int main()
// {
// 	fizzbuzz();
// }


// void ft_swap(int *a, int *b)
// {
// 	int tmp = 0;
// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

// int main()
// {
// 	int a = 1;
// 	int b = 2;
// 	ft_swap(&a, &b);
// 	printf("%d\n", a);
// 	printf("%d\n", b);
// 	return 0;
// }


// rot_13 -> copia di rotone ma aggiungendo 13 anziche' 1
// char replace_c(char c)
// {
// 	if (((c <= 'z') && (c >= 'n')) || ((c <= 'Z') && (c >= 'N')))
// 		c -= 13;
// 	else if(((c <= 'a') && (c >= 'm')) || ((c <= 'A') && (c >= 'M')))
// 		c += 13;
// 	return (c);
// }

// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	while (argv[1][i] != '\0')
// 	{
// 		argv[1][i] = replace_c(argv[1][i]);
// 		write(1, &argv[1][i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return 0;
// }

#include <stdlib.h>


// int main(int argc, char *argv[])
// {
// 	if (argc != 4)
// 	{
// 		write(1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	int arg = 1;
// 	int numb = atoi(&argv[1][i]);
// 	int n = atoi(&argv[3][i]);
// 	int tmp = 0;
// 	if (arg < argc)
// 	{
// 		if (argv[2][i] == '+')
// 		{
// 			tmp = numb + n;
// 		}
// 		else if (argv[2][i] == '-')
// 		{
// 			tmp = numb - n;
// 		}
// 		else if (argv[2][i] == '/')
// 		{
// 			tmp = numb / n;
// 		}
// 		else if (argv[2][i] == '%')
// 		{
// 			tmp = numb % n;
// 		}
// 		printf("%d\n", tmp);
// 	}
// 	write (1, "\n", 1);
// 	return 0;
// }


// int ft_strcmp(char *s1, char *s2)
// {
// 	int lunghezza1 = ft_strlen(s1);
// 	int lunghezza2 = ft_strlen(s2);
// 	return(lunghezza1 - lunghezza2);
// }

// int main()
// {
// 	char *str1 = "ciao mamma";
// 	char *str2 = "ciao";
// 	printf("%d\n", ft_strcmp(str1, str2));
// 	return 0;
// }



// int ft_strlen(char *str)
// {
// 	int i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }


// char *ft_strdup(char *src)
// {
// 	int len = 0;
// 	char *dest = malloc(ft_strlen(src) + 1);
// 	while (src[len] !='\0')
// 	{
// 		dest[len] = src[len];
// 		len++;
// 	}
// 	dest[len] = '\0';
// 	return dest;
// }



// size_t ft_strcspn(const char *s, const char *reject)
// {
// 	size_t j;
// 	size_t i = 0;

// 	while(s[i] != '\0')
// 	{
// 		j = 0;
// 		while(reject[j])
// 		{
// 			if (s[i] == reject[j])
// 				return i;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return 1;
// }


// char *ft_strrev(char *str)
// {
// 	int len = 0;
// 	int i = 0;
// 	char *tmp;
// 	while (str[len] != '\0')
// 		len++;
// 	len -= 1;
// 	while (len > 1)
// 	{
// 		tmp = str[i];
// 		str[i] = str[len];
// 		str[len] = tmp;
// 		i++;
// 		len--;
// 	}
// 	return(str);
// }


// int max(int *tab, unsigned int len)
// {
// 	if (len == 0)
// 		return (0);
// 	int max = tab[len];
// 	unsigned int i = 1;
// 	while(i < len)
// 	{
// 		if(tab[i] > max)
// 			max = tab[i];
// 		i++;
// 	}
// 	return (max);
// }


// int main()
// {
// 	int tab[] = {23, 42, 24};
// 	printf("%d\n", max(tab, 3));
// 	return 0;
// }


// void print_bits(unsigned char octet)
// {
// 	int i = 7;
// 	char bit;
// 	while (i >= 0)
// 	{
// 		if(octet & (1 << i))
// 			bit ='1';
// 		else
// 			bit = '0';
// 		write(1, &bit, 1);
// 		i--;
// 	}
// }


// unsigned char reverse_bits(unsigned char octet)
// {
// 	int i = 0;
// 	unsigned char bit = 0;
// 	while (i <= 7)
// 	{
// 		if (octet & (1 << i))
// 			bit = bit | (1 << (7 - i));
// 		i++;
// 	}
// 	return (bit);
// }


// unsigned char swap_bits(unsigned char octet)
// {
// 	return((octet << 4) | (octet >> 4));
// }

// void print_bits(unsigned char octet)
// {
// 	int i = 7;
// 	unsigned char bit;
// 	while (i >= 0)
// 	{
// 		if (octet & (1 << i))
// 			bit = '1';
// 		else
// 			bit = '0';
// 		i--;
// 	}
// }


// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		write (1, '0', 1);
// 		write (1, "\n", 1);
// 		return 0;
// 	}
// 	int i = 0;
// 	int n = ft_atoi(argv[1]);
// 	while(n < 0)
// 	{
// 		write (1, '0', 1);
// 		write (1, "\n", 1);
// 		return 0;
// 	}
// 	while (n > 1)
// 	{
// 		if (is_prime(n) == 1)
// 			i += n;
// 		n--;
// 	}
// 	ft_putnbr(i);
// 	write (1, "\n", 1);
// 	return 0;
// }



















