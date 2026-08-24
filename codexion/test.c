
#include <stdio.h>
#include <stdlib.h>

typedef struct s_coders {
	int index;
	int	value;
}		t_coders;

void print_coders(t_coders *coders, int size) {
	int i = 0;
	
	while (i < size) {
		printf("struct coder %d: {\n\tindex: %d;\n\tvalue: %d;\n}\n", i + 1, coders[i].index, coders[i].value);
		i++;
	}
	printf("\n--------------------------------\n\n");
}

t_coders *init_vals(int size) {
	t_coders *c = malloc(sizeof(t_coders) * size); // c'è da capire se in questo caso c è un array o una struct
	int i = 0;
	while (i < size) {
		c[i].index = i + 1;
		c[i].value = 1;
		i++;
	}
	return (c);
}

void modify_value_two(t_coders *coders, int value, int index) {
	coders[index].value = value;
}

// coders lo passi come ** perche e come se lo stessi passando per riferimento
// come quando hai da modificare una variabile int var, la funzione ti chiede un int * var
// e alla funzione passi &var
void modify_value_one(t_coders **coders, int value, int index) {
	coders[0][index].value = value;
}

int main(int ac, char **av) {
	if (ac < 2)
		return (printf("Passa come parametro al programma il numero di strutture che vuoi creare\n"), 1);
	t_coders *coders = init_vals(atoi(av[1]));
	print_coders(coders, atoi(av[1]));
	// modifica dei valori, tramite funzione o tramite array
	coders[0].value = 42;
	modify_value_one(&coders, 43, 1);
	modify_value_two(coders, 44, 2);
	print_coders(coders, atoi(av[1]));
}