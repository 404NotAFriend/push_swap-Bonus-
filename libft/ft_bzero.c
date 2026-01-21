/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:33:42 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 15:48:11 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*bytestr;

	i = 0;
	bytestr = (char *)str;
	while (i < n)
	{
		bytestr[i] = '\0';
		i++;
	}
}
