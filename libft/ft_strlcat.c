/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:35:13 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 15:57:11 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	j = 0;
	if (n <= dest_len)
		return (n + src_len);
	while (dest[i] && i < n)
		i++;
	while (src[j] && i < n - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < n)
		dest[i] = '\0';
	return (dest_len + src_len);
}
