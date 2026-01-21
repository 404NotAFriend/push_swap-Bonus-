/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho <bramalho@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by bramalho          #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by bramalho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(unsigned long n, char *base, int fd)
{
	unsigned long	baselen;

	baselen = 0;
	while (base[baselen])
		baselen++;
	if (n >= baselen)
		ft_putnbr_base_fd(n / baselen, base, fd);
	ft_putchar_fd(base[n % baselen], fd);
}
