/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 07:32:15 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/27 04:14:17 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	identify_lis_and_mark(t_stack *stack_a)
{
	int	*indices;
	int	*lengths;
	int	*prev;
	int	*lis_val;
	int	lis_len;

	indices = malloc(sizeof(int) * stack_a->size);
	lengths = malloc(sizeof(int) * stack_a->size);
	prev = malloc(sizeof(int) * stack_a->size);
	if (!indices || !lengths || !prev)
		return ;
	fill_indices_array(stack_a, indices, lengths, prev);
	compute_lis_dp(indices, lengths, prev, stack_a->size);
	lis_val = reconstruct_lis(lengths, prev, stack_a->size, &lis_len);
	lis_len = -1;
	while (lis_val[++lis_len] != -1)
		mark_single_element(stack_a, lis_val[lis_len]);
	free(indices);
	free(lengths);
	free(prev);
	free(lis_val);
}

static void	rotate_to_min(t_stack *stack_a)
{
	t_node	*min_node;
	int		min_val;
	int		min_pos;

	min_val = 2147483647;
	min_node = stack_a->top;
	assign_positions(stack_a);
	while (1)
	{
		if (min_node->index < min_val)
		{
			min_val = min_node->index;
			min_pos = min_node->pos;
		}
		min_node = min_node->next;
		if (min_node == stack_a->top)
			break ;
	}
	if (min_pos > stack_a->size / 2)
		while (stack_a->top->index != min_val)
			rra(stack_a, 1);
	else
		while (stack_a->top->index != min_val)
			ra(stack_a, 1);
}

void	push_back_optimized(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	while (stack_b->size > 0)
	{
		calculate_cost(stack_a, stack_b);
		cheapest = find_cheapest(stack_b);
		execute_move(stack_a, stack_b, cheapest);
	}
	rotate_to_min(stack_a);
}

void	lis_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	identify_lis_and_mark(stack_a);
	push_non_lis_to_b(stack_a, stack_b);
	push_back_optimized(stack_a, stack_b);
}
