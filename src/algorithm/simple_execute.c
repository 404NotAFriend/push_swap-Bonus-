/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:00:00 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/26 16:00:00 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_to_position(t_stack *stack, int pos, int size, char stack_name)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			if (stack_name == 'a')
				ra(stack, 1);
			else
				rb(stack, 1);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			if (stack_name == 'a')
				rra(stack, 1);
			else
				rrb(stack, 1);
			pos--;
		}
	}
}

void	simple_execute_move(t_stack *stack_a, t_stack *stack_b, t_node *cheapest)
{
	int	target_pos;
	int	b_pos;

	target_pos = cheapest->target_pos;
	b_pos = cheapest->pos;  // Use stored position instead of recalculating

	// Rotate both stacks to optimal positions
	rotate_to_position(stack_b, b_pos, stack_b->size, 'b');
	rotate_to_position(stack_a, target_pos, stack_a->size, 'a');

	// Push from B to A
	pa(stack_a, stack_b, 1);
}