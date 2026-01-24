/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 06:25:39 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 06:31:25 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;
	int	max_num;

	max_num = size - 1;
	bits = 0;
	while (max_num > 0)
	{
		max_num >>= 1;
		bits++;
	}
	return (bits);
}

static int	get_bit(int num, int bit_pos)
{
	return ((num >> bit_pos) & 1);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	max_bits = get_max_bits(stack_a->size);
	bit = 0;
	while (bit < max_bits)
	{
		size = stack_a->size;
		i = 0;
		while (i < size)
		{
			if (get_bit(stack_a->top->index, bit) == 0)
				pb(stack_a, stack_b, 1);
			else
				ra(stack_a, 1);
			i++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b, 1);
		bit++;
	}
}
