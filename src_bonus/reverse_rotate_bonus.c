/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:32:00 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/25 16:32:00 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}

void	rra_bonus(t_stack *stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb_bonus(t_stack *stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr_bonus(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
