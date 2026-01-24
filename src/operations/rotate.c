/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:19:24 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 03:55:20 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->next;
}

void	ra(t_stack *stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack *stack_b, int print)
{
	rotate(stack_b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_printf("rr\n");
}
