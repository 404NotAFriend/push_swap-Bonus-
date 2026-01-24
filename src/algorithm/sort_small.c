/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:17:34 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 06:48:34 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		count;

	current = stack->top;
	min_index = current->index;
	count = 0;
	while (count < stack->size)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
		count++;
	}
	return (min_index);
}

static void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int		min_index;
	t_node	*current;
	int		pos;
	int		count;

	min_index = find_min_index(stack_a);
	current = stack_a->top;
	pos = 0;
	count = 0;
	while (count < stack_a->size)
	{
		if (current->index == min_index)
			break ;
		pos++;
		current = current->next;
		count++;
	}
	if (pos <= stack_a->size / 2)
		while (stack_a->top->index != min_index)
			ra(stack_a, 1);
	else
		while (stack_a->top->index != min_index)
			rra(stack_a, 1);
	pb(stack_a, stack_b, 1);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a, 1);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
	{
		push_min_to_b(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b, 1);
	}
	else if (stack_a->size == 5)
	{
		push_min_to_b(stack_a, stack_b);
		push_min_to_b(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
}
