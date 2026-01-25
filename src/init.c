/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:14:35 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/21 22:13:57 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->pos = 0;
	new_node->target_pos = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->keep_in_a = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	add_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*bottom;

	if (!stack->top)
	{
		stack->top = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		bottom = stack->top->prev;
		bottom->next = new_node;
		new_node->prev = bottom;
		new_node->next = stack->top;
		stack->top->prev = new_node;
	}
	stack->size++;
}
