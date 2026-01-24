/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 04:18:39 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 04:19:24 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_node	*find_min_unindexed(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;
	int		count;

	current = stack->top;
	min_node = NULL;
	count = 0;
	while (count < stack->size)
	{
		if (current->index == -1)
		{
			if (!min_node || current->value < min_node->value)
				min_node = current;
		}
		current = current->next;
		count++;
	}
	return (min_node);
}

void	assign_index(t_stack *stack)
{
	t_node	*min_node;
	int		index;

	index = 0;
	while (index < stack->size)
	{
		min_node = find_min_unindexed(stack);
		if (min_node)
			min_node->index = index;
		index++;
	}
}
