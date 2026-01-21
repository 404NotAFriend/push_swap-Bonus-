/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:33:33 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 15:54:16 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*bytestr;

	i = 0;
	bytestr = (char *)str;
	while (i < n)
	{
		bytestr[i] = c;
		i++;
	}
	return (str);
}
