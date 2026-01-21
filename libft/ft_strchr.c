/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:32:45 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 16:09:22 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	target;

	target = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == target)
			return ((char *)&str[i]);
		i++;
	}
	if (target == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
