/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:17:27 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 06:55:33 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	while (stack_b->size > 0)
	{
		simple_calculate_cost(stack_a, stack_b);
		cheapest = simple_find_cheapest(stack_b);
		simple_execute_move(stack_a, stack_b, cheapest);
	}
}

static void	final_rotation(t_stack *stack_a)
{
	t_node	*current;
	int		min_pos;
	int		count;

	assign_positions(stack_a);
	current = stack_a->top;
	min_pos = 0;
	count = 0;
	while (count < stack_a->size)
	{
		if (current->index == 0)
		{
			min_pos = current->pos;
			break ;
		}
		current = current->next;
		count++;
	}
	if (min_pos <= stack_a->size / 2)
		while (stack_a->top->index != 0)
			ra(stack_a, 1);
	else
		while (stack_a->top->index != 0)
			rra(stack_a, 1);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	push_back_to_a(stack_a, stack_b);
	final_rotation(stack_a);
}
