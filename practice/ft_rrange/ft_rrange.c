#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int *mem;
	int j = 0;
	if (start > end)
		mem = malloc((start - end) * sizeof(int));
	if (end > start)
		mem = malloc((end - start) * sizeof(int));
	else
		mem = malloc(sizeof(int));
	int tmp = end;
	if (start > end)
		while(start >= tmp)
			mem[j++] = tmp++;
	else if(end > start)
		while(tmp >= start)
			mem[j++] = tmp--;
	else
		mem[j] = tmp;
	return (mem);
}