/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:34:16 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 15:54:12 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destcpy;
	char	*srccpy;

	destcpy = (char *)dest;
	srccpy = (char *)src;
	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			destcpy[i] = srccpy[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
