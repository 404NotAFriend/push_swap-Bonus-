/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:34:11 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 15:54:25 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destcpy;
	char	*srccpy;

	i = 0;
	destcpy = (char *)dest;
	srccpy = (char *)src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		i++;
	}
	return (dest);
}
