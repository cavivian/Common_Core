#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}


// void ft_print_alphabet(void)
// {
//     char lettera = 'a';
//     while(lettera >= 'a' && lettera <= 'z')
//     {
//         ft_putchar(lettera);
//         lettera++;
//     }
//     write(1, "\n", 1);
// }

// int main()
// {
//     ft_print_alphabet();
// }



// void ft_print_reverse_alphabet(void)
// {
//     int i = 'z';
//     while (i >= 'a')
//     {
//         ft_putchar(i);
//         i--;
//     }
    
// }

// void ft_print_numbers()
// {
//     int i = 48;
//     while(i <= 57)
//     {
//         ft_putchar(i);
//         i++;
//     }
// }

// void ft_is_negative(int n)
// {
//     if (n < 0)
//         write(1, "N\n", 2);
//     else if (n >= 0)
//         write(1, "P\n", 2);
// }

// void ft_char_type(char c)
// {
//     if (c >= 'a' && c <= 'z')
//         ft_putchar('m');
//     else if (c >= 'A' && c <= 'Z')
//         ft_putchar('M');
//     else if(c >= '0' && c <= '9')
//         ft_putchar('N');
//     else if(c >= 9 && c <= 13 || c == 32)
//         ft_putchar('?');
// }

// void ft_print_interval(char start, char end)
// {
//     while(start <= end)
//     {
//         ft_putchar(start);
//         start++;
//     }
//     write(1, "\n", 1);
// }

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

// int ft_strlen(char *str)
// {
//     int i = 0;
//     while (str[i] != '\0')
//     {
//         i++;
//     }
//     return (i);
// }

// void ft_lowercase(char *str)
// {
//     int i = 0;
//     while(str[i] != '\0')
//     { 
//         if (str[i] >= 'A' && str[i] <= 'Z')
//         {
//             str[i] += 32;
//         }
//         i++;
//     }
// }


//ulstr -> funzione che inverte i case, le maiuscole diventano minuscole e viceversa
// int main(int argc, char *argv[])
// {
//     if (argc != 2)
//     {
//         write(1, "\n", 1);
//         return 0;
//     }
//     int i = 0;
//     while (argv[1][i] != '\0')
//     {
//         if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
//             {
//                 argv[1][i] += 32;
//                 write (1, &argv[1][i], 1);
//             }
//         else
//             {
//                 argv[1][i] -= 32;
//                 write (1, &argv[1][i], 1);
//             }
//         i++;
//     }
//     write(1, "\n", 1);
//     return 0;
// }

// first_word
// int main(int argc, char *argv[])
// {
//     if (argc != 2)
//     {
//         write(1, "\n", 1);
//         return 0;
//     }
//     int i = 0;
//     if(argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13))
//     {
//         i++;
//     }
//     while (argv[1][i] != '\0' && argv[1][i] != 32 || (argv[1][i] >= 9 && argv[1][i] <= 13))
//     {
//         write(1, &argv[1][i], 1);
//         i++;
//     }
//     write(1, "\n", 1);
//     return 0;
// }

//rotone
// int main(int argc, char *argv[])
// {
//     if (argc != 2)
//     {
//         write(1, "\n", 1);
//         return 0;
//     }
//     int i = 0;
//     char tmp = argv[1][i];
//     while (argv[1][i] != '\0')
//     {
//         if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
//         {
//             if(argv[1][i] == 'z')
//                 tmp = 'a';
//             else
//                 tmp += 1;
//         }
//         else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
//         {
//             if(argv[1][i] == 'Z')
//                 tmp = 'A';
//             else
//                 tmp += 1;
//         }
//         write(1, &tmp, 1);
//         i++;
//     }
//     write(1, "\n", 1);
//     return 0;
// }

//rev_print
// int main(int argc, char *argv[])
// {
//     if (argc != 2)
//     {
//         write (1, "\n", 1);
//         return 0;
//     }
//     int i = 0;
//     while (argv[1][i] != '\0')
//     {
//         i++;
//     }
//     i--;
//     if (argv[1][i] == '\0')
//     {
//         while(i >= 0)
//         {
//             write(1, &argv[1][i], 1);
//             i--;
//         }
//     }
//     write(1, "\n", 1);
//     return 0;
// }


//serach_and_replace
// int main(int argc, char *argv[])
// {
//     if (argc != 4 || argv[2][0] == '\0' || argv[2][1] != '\0' || argv[3][0] == '\0' || argv[3][1] != '\0')
//     {
//         write (1, "\n", 1);
//         return 0; 
//     }
//     int i = 0;
//     char tmp = argv[3][0];
//     while (argv[1][i] != '\0')
//     {
//         if (argv[1][i] == argv[2][0])
//         {
//             argv[1][i] = tmp;
//         }
//         write(1, &argv[1][i], 1);
//         i++;
//     }
//     write(1, "\n", 1);
//     return 0;
// }


//repeat_alpha
// int main(int argc, char *argv[])
// {
//     if (argc != 2)
//     {
//         write(1, "\n", 1);
//         return (0);
//     }
//     int i = 0;
//     int lettere_da_stampare;
//     while (argv[1][i] != '\0')
//     {
//         lettere_da_stampare = 1;
//         if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
//         {
//             lettere_da_stampare = argv[1][i] - 'a' + 1;
//         }
//         else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
//         {
//             lettere_da_stampare = argv[1][i] - 'A' + 1;
//         }
//         while(lettere_da_stampare > 0)
//         {
//             write(1, &argv[1][i], 1);
//             lettere_da_stampare--;
//         }
//         i++;
//     }
//     write(1, "\n", 1);
//     return 0;
// }


//ft_strcpy
// char *ft_strcpy(char *s1, char * s2)
// {
//     int i = 0;
//     int j = 0;
//     while (s2[i] != '\0')
//     {
//         s1[j] = s2[i];
//         i++;
//         j++;
//     }
//     s1[j] = '\0';
//     return(s1);
// }

// int main(void)
// {
//     char sorgente[] = "Tutto Copiato!";
//     char destinazione[50]; // Un contenitore vuoto abbastanza grande

//     ft_strcpy(destinazione, sorgente);
    
//     // Stampiamo la destinazione per vedere se la copia è riuscita
//     printf("Sorgente: %s\n", sorgente);
//     printf("Destinazione: %s\n", destinazione); 
    
//     return (0);
// }

//last_word
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    int i = 0;
    int j = 0;
    while(argv[1][i] != '\0')
    {
        i++;
    }
    i--;
    printf("il valore di i è %d", i);
    while((argv[1][i] >= 1 && argv[1][i] != 32) && !(argv[1][i] >= 9 && argv[1][i] <= 13))
    {
        i--;
    }
    j = i + 1;
    while(argv[1][j] != '\0')
    {
        write(1, &argv[1][j], 1);
        j++;
    }
    write(1, "\n", 1);
    return 0;
}



















