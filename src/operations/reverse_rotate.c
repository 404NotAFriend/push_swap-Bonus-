/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:19:14 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 03:55:18 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}

void	rra(t_stack *stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}
