/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:14:58 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/26 01:00:43 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}

t_node	*get_bottom(t_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->prev);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;
	int		count;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	count = stack->size - 1;
	while (count > 0)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		count--;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		i;
	int		j;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		compare = current->next;
		j = i + 1;
		while (j < stack->size)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return (0);
}
