/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 07:35:15 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 16:06:54 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		pos;

	current = stack->top;
	min_index = current->index;
	min_pos = 0;
	pos = 0;
	while (pos < stack->size)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack *stack)
{
	int	min_pos;

	min_pos = find_min_index(stack);
	if (min_pos <= stack->size / 2)
	{
		while (min_pos-- > 0)
			ra(stack, 1);
	}
	else
	{
		min_pos = stack->size - min_pos;
		while (min_pos-- > 0)
			rra(stack, 1);
	}
}

static void	sort_four_optimized(t_stack *stack_a, t_stack *stack_b)
{
	move_min_to_top(stack_a);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
}

static void	sort_five_optimized(t_stack *stack_a, t_stack *stack_b)
{
	move_min_to_top(stack_a);
	pb(stack_a, stack_b, 1);
	move_min_to_top(stack_a);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 4)
		sort_four_optimized(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five_optimized(stack_a, stack_b);
}
