/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho <bramalho@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:47:49 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/20 16:15:42 by bramalho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countdigits(int n)
{
	int		counter;
	long	tempn;

	counter = 0;
	tempn = (long)n;
	if (n < 0)
	{
		tempn = -tempn;
		counter++;
	}
	if (tempn == 0)
		return (1);
	while (tempn != 0)
	{
		counter++;
		tempn = tempn / 10;
	}
	return (counter);
}

long	handle_negative(int n, char *mem)
{
	if (n < 0)
	{
		mem[0] = '-';
		return (-(long)n);
	}
	return ((long)n);
}

char	*ft_itoa(int n)
{
	int		digitcount;
	int		i;
	char	*mem;
	long	num;

	digitcount = countdigits(n);
	i = digitcount - 1;
	mem = malloc(digitcount + 1);
	if (!mem)
		return (NULL);
	if (n == 0)
	{
		mem[0] = '0';
		mem[1] = '\0';
		return (mem);
	}
	num = handle_negative(n, mem);
	while (num > 0)
	{
		mem[i] = (num % 10) + '0';
		i--;
		num = num / 10;
	}
	mem[digitcount] = '\0';
	return (mem);
}
