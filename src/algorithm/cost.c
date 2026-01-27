/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 08:42:45 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 06:46:55 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_cost_rotate(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

static int	find_target_pos_fast(t_stack *stack_a, int b_index)
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
			target_pos = count;
		}
		current = current->next;
		count++;
	}
	if (target_index == INT_MAX)
	{
		current = stack_a->top;
		target_index = INT_MAX;
		count = 0;
		while (count < stack_a->size)
		{
			if (current->index < target_index)
			{
				target_index = current->index;
				target_pos = count;
			}
			current = current->next;
			count++;
		}
	}
	return (target_pos);
}

void	calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		count;
	int		pos_b;

	assign_positions(stack_a);
	current = stack_b->top;
	count = 0;
	pos_b = 0;
	while (count < stack_b->size)
	{
		current->target_pos = find_target_pos_fast(stack_a, current->index);
		current->cost_b = get_cost_rotate(pos_b, stack_b->size);
		if (pos_b > stack_b->size / 2)
			current->cost_b *= -1;
		current->cost_a = get_cost_rotate(current->target_pos, stack_a->size);
		if (current->target_pos > stack_a->size / 2)
			current->cost_a *= -1;
		current = current->next;
		count++;
		pos_b++;
	}
}

static int	abs_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_node	*find_cheapest(t_stack *stack_b)
{
	t_node	*current;
	t_node	*cheapest;
	int		min_cost;
	int		total_cost;
	int		count;

	current = stack_b->top;
	cheapest = current;
	min_cost = INT_MAX;
	count = 0;
	while (count < stack_b->size)
	{
		total_cost = abs_value(current->cost_a) + abs_value(current->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
		count++;
	}
	return (cheapest);
}
