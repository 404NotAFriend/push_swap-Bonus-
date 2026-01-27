/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 06:50:29 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 06:59:18 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	pushed;

	size = stack_a->size;
	pushed = 0;
	while (pushed < size - 3)
	{
		pb(stack_a, stack_b, 1);
		pushed++;
		if (stack_b->size == 2)
		{
			if (stack_b->top->index < stack_b->top->next->index)
				sb(stack_b, 1);
		}
	}
}
