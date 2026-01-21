/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:33:12 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/18 16:09:02 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	target;

	target = (unsigned char)c;
	i = 0;
	while (str[i])
		i++;
	if (str[i] == target)
		return ((char *)&str[i]);
	i--;
	while (i >= 0)
	{
		if (str[i] == target)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
