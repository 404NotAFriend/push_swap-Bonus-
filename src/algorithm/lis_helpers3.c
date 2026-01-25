/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helpers3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:55:00 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 23:51:20 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_max_lis_position(int *lengths, int size, int *max_len,
	int *max_idx)
{
	int	i;

	*max_len = 0;
	*max_idx = 0;
	i = 0;
	while (i < size)
	{
		if (lengths[i] > *max_len)
		{
			*max_len = lengths[i];
			*max_idx = i;
		}
		i++;
	}
}
