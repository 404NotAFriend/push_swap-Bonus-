/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 06:51:20 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/27 03:38:44 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both(t_stack *a, t_stack *b, t_node *cheap)
{
	while (cheap->cost_a > 0 && cheap->cost_b > 0)
	{
		rr(a, b, 1);
		cheap->cost_a--;
		cheap->cost_b--;
	}
	while (cheap->cost_a < 0 && cheap->cost_b < 0)
	{
		rrr(a, b, 1);
		cheap->cost_a++;
		cheap->cost_b++;
	}
}

static void	rotate_a(t_stack *a, int cost)
{
	while (cost > 0)
	{
		ra(a, 1);
		cost--;
	}
	while (cost < 0)
	{
		rra(a, 1);
		cost++;
	}
}

static void	rotate_b(t_stack *b, int cost)
{
	while (cost > 0)
	{
		rb(b, 1);
		cost--;
	}
	while (cost < 0)
	{
		rrb(b, 1);
		cost++;
	}
}

void	execute_move(t_stack *a, t_stack *b, t_node *cheap)
{
	rotate_both(a, b, cheap);
	rotate_a(a, cheap->cost_a);
	rotate_b(b, cheap->cost_b);
	pa(a, b, 1);
}
