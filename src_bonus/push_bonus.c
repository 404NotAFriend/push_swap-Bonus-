/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:30:00 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/25 16:30:00 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static t_node	*remove_top(t_stack *stack)
{
	t_node	*node;
	t_node	*last;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->top;
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		last = stack->top->prev;
		stack->top = stack->top->next;
		stack->top->prev = last;
		last->next = stack->top;
	}
	stack->size--;
	return (node);
}

static void	add_to_top(t_stack *stack, t_node *node)
{
	t_node	*last;

	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		last = stack->top->prev;
		node->next = stack->top;
		node->prev = last;
		last->next = node;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

static void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = remove_top(from);
	if (node)
		add_to_top(to, node);
}

void	pa_bonus(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
}

void	pb_bonus(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
}
