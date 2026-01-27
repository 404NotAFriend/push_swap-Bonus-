/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 08:42:45 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/27 04:24:29 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	calc_combined_cost(int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	if (cost_a < 0 && cost_b < 0)
	{
		if (-cost_a > -cost_b)
			return (-cost_a);
		return (-cost_b);
	}
	if (cost_a < 0)
		cost_a = -cost_a;
	if (cost_b < 0)
		cost_b = -cost_b;
	return (cost_a + cost_b);
}

void	calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*curr_b;
	int		target_pos;

	assign_positions(stack_a);
	assign_positions(stack_b);
	curr_b = stack_b->top;
	while (curr_b)
	{
		target_pos = find_target_pos(stack_a, curr_b->index);
		curr_b->cost_b = curr_b->pos;
		if (curr_b->pos > stack_b->size / 2)
			curr_b->cost_b = (stack_b->size - curr_b->pos) * -1;
		curr_b->cost_a = target_pos;
		if (target_pos > stack_a->size / 2)
			curr_b->cost_a = (stack_a->size - target_pos) * -1;
		curr_b = curr_b->next;
		if (curr_b == stack_b->top)
			break ;
	}
}

t_node	*find_cheapest(t_stack *stack_b)
{
	t_node	*current;
	t_node	*cheapest;
	int		min_cost;
	int		cur_cost;
	int		i;

	if (!stack_b || !stack_b->top)
		return (NULL);
	current = stack_b->top;
	cheapest = current;
	min_cost = INT_MAX;
	i = 0;
	while (i < stack_b->size)
	{
		cur_cost = calc_combined_cost(current->cost_a, current->cost_b);
		if (cur_cost < min_cost)
		{
			min_cost = cur_cost;
			cheapest = current;
		}
		current = current->next;
		i++;
	}
	return (cheapest);
}
