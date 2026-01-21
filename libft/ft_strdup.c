/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:36:08 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 15:56:06 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, str, len + 1);
	return (dup);
}
