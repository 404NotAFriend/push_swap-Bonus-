/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 06:51:20 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 06:51:32 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	reverse_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	rotate_a(t_stack *a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a, 1);
			(*cost)--;
		}
		else
		{
			rra(a, 1);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_stack *b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b, 1);
			(*cost)--;
		}
		else
		{
			rrb(b, 1);
			(*cost)++;
		}
	}
}

void	execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		reverse_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a, b, 1);
}
