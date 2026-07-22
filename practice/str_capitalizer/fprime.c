#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_sqrt(int n) {
    if (n < 0)
        return -1;

    if (n == 0)
        return 0;

    int x = n;
    int precedente = 0;

    while (x != precedente) {
        precedente = x;
        x = (x + n / x) / 2;
    }

    return x;
}

int is_prime(int n) {
    if (n <= 1) return 0;       // 0 e 1 non sono primi
    if (n == 2) return 1;       // 2 è l'unico primo pari
    if (n % 2 == 0) return 0;   // Esclude gli altri pari
    
    // Controlla solo i divisori dispari fino alla radice quadrata
    for (int i = 3; i <= ft_sqrt(n); i += 2) {
        if (n % i == 0) return 0; // Se divisibile, non è primo
    }
    return 1; // È primo
}


int main(int argc, char *argv[])
{
	int i = 2;
	int num = atoi(argv[1]);
	printf("num: %d, i: %d\n", num, i);
	while (i <= num)
	{
		if (is_prime(i) == 1 && num % i == 0)
		{
			printf("%d", i);
			num /= i;
			printf("num: %d, i: %d\n", num, i);
		}
		if (num != 0)
			printf("*");
		else
			break ;
		printf("num: %d, i: %d\n", num, i);
		i++;
	}
	printf("\n");
}