/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:36:15 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 16:02:15 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	strlen;
	size_t	validlen;
	char	*allocmem;
	char	*empty;

	strlen = ft_strlen(str);
	if (start >= strlen || len == 0)
	{
		empty = malloc(1);
		if (!empty)
			return (NULL);
		empty[0] = '\0';
		return (empty);
	}
	validlen = strlen - start;
	if (len < validlen)
		validlen = len;
	allocmem = malloc(validlen + 1);
	if (!allocmem)
		return (NULL);
	ft_memcpy(allocmem, str + start, validlen);
	allocmem[validlen] = '\0';
	return (allocmem);
}
