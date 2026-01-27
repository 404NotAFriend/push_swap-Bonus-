/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helpers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:52:43 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/27 04:48:28 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	*create_lis_array(int max_len)
{
	int	*lis;

	lis = malloc(sizeof(int) * max_len);
	return (lis);
}

int	*reconstruct_lis(int *lengths, int *prev, int size, int *lis_len)
{
	int	*lis;
	int	max_len;
	int	max_idx;
	int	i;

	find_max_lis_position(lengths, size, &max_len, &max_idx);
	lis = create_lis_array(max_len);
	if (!lis)
		return (NULL);
	i = max_len - 1;
	while (max_idx != -1 && i >= 0)
	{
		lis[i] = max_idx;
		max_idx = prev[max_idx];
		i--;
	}
	*lis_len = max_len;
	return (lis);
}
