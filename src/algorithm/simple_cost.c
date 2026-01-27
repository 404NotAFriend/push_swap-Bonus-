/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:42:00 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/26 16:30:00 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_node	*find_min_index_node(t_stack *stack_a)
{
	t_node	*current;
	t_node	*min_node;

	current = stack_a->top;
	min_node = current;
	while (current)
	{
		if (current->index < min_node->index)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

// Implementation following colleague's exact approach
static int	find_target_pos_colleague_style(t_stack *stack_a, int b_index)
{
	t_node	*a_node;
	t_node	*min_node;
	int		index_diff;
	int		best_diff;
	int		target_pos;
	int		pos;

	a_node = stack_a->top;
	best_diff = INT_MAX;
	target_pos = 0;
	pos = 0;
	min_node = find_min_index_node(stack_a);

	while (a_node)
	{
		if (b_index < a_node->index)
		{
			index_diff = a_node->index - b_index;
			if (index_diff < best_diff)
			{
				best_diff = index_diff;
				target_pos = pos;
			}
		}
		a_node = a_node->next;
		pos++;
	}

	// If no valid target found, use minimum index node position
	if (best_diff == INT_MAX)
	{
		a_node = stack_a->top;
		pos = 0;
		while (a_node && a_node != min_node)
		{
			a_node = a_node->next;
			pos++;
		}
		target_pos = pos;
	}
	return (target_pos);
}

void	simple_calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b_node;
	int		pos_b;

	b_node = stack_b->top;
	pos_b = 0;

	while (b_node && pos_b < stack_b->size)
	{
		// Find target using colleague's approach
		b_node->target_pos = find_target_pos_colleague_style(stack_a, b_node->index);

		// Store positions
		b_node->pos = pos_b;

		// Calculate costs (simpler approach like colleague)
		b_node->cost_b = (pos_b <= stack_b->size / 2) ? pos_b : (stack_b->size - pos_b);
		b_node->cost_a = (b_node->target_pos <= stack_a->size / 2) ?
			b_node->target_pos : (stack_a->size - b_node->target_pos);

		b_node = b_node->next;
		pos_b++;
	}
}

t_node	*simple_find_cheapest(t_stack *stack_b)
{
	t_node	*current;
	t_node	*cheapest;
	int		min_cost;
	int		current_cost;

	if (!stack_b->top)
		return (NULL);

	current = stack_b->top;
	cheapest = current;
	min_cost = current->cost_a + current->cost_b;

	while (current)
	{
		current_cost = current->cost_a + current->cost_b;
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}