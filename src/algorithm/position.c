/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 07:23:31 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 16:06:47 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_positions(t_stack *stack)
{
	t_node	*current;
	int		pos;

	current = stack->top;
	pos = 0;
	while (pos < stack->size)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

static int	find_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		count;

	current = stack->top;
	min_index = INT_MAX;
	min_pos = 0;
	count = 0;
	while (count < stack->size)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = current->pos;
		}
		current = current->next;
		count++;
	}
	return (min_pos);
}

int	find_target_pos(t_stack *stack_a, int b_index)
{
	t_node	*current;
	int		target_pos;
	int		target_index;
	int		count;

	target_index = INT_MAX;
	target_pos = 0;
	current = stack_a->top;
	count = 0;
	while (count < stack_a->size)
	{
		if (current->index > b_index && current->index < target_index)
		{
			target_index = current->index;
			target_pos = current->pos;
		}
		current = current->next;
		count++;
	}
	if (target_index == INT_MAX)
		return (find_min_pos(stack_a));
	return (target_pos);
}
