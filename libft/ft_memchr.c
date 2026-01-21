/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:34:31 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 15:54:46 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*target;

	i = 0;
	target = (const unsigned char *)str;
	while (i < n)
	{
		if (target[i] == (unsigned char)c)
			return ((void *)(target + i));
		i++;
	}
	return (NULL);
}
