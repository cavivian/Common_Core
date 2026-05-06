/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavivian <cavivian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:32:04 by cavivian          #+#    #+#             */
/*   Updated: 2026/05/06 09:12:51 by cavivian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//funzione che serve per capire quanti caratteri dovra' contenere 
//la stringa
static int	count_intlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)//se il num e' negativo ci serve uno spazio per il -
	//se e' 0 va contato lo stesso
		len++;//motivo per cui non facciamo il return ma si va avanti
	while (num != 0)
	{
		num /= 10;// si divide per sapere da quanti numeri e' composta
		len++;// a questo punto len combacera' con la divisione precedente
	}
	return (len);
}

char	*ft_itoa(long num)
{
	char	*s;
	int		i;
	int		len;

	len = count_intlen(num);// si passa il risultato del conteggio
	s = malloc(len + 1);//si alloca la lunghezza + 1 per aggiungere il \0
	if (!s) //cotrollo se la malloc non esiste
		return (NULL);
	s[len] = '\0';//partiamo direttamente dal fondo
	i = len - 1;// indice parte dall'ultimo senza contare il \0
	if (num < 0)//quando e' negativo
	{
		s[0] = '-';//il primo carattere e' un -
		num *= -1;//lo trasformiamo in positivo per estrarre le cifre facilmente
	}
	if (num == 0)
		s[i] = '0';//si assegna direttamente zero
	while (num > 0)
	{
		s[i] = num % 10 + 48;// e' il modo piu' veloce per trovare l'ultimo numero e convertirlo in char
		num /= 10;//togliamo l'ultima cifra e passiamo alla successiva
		i--;//si scorre dalla fine all'inizio
	}
	return (s);
}

/*int	main(void)
{
	int		num = -42;

	printf("%s\n", ft_itoa(num));
	return (0);
}*/