/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 07:32:15 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 23:51:29 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	*create_lis_array(t_stack *stack_a, int *lis_len)
{
	int	*indices;
	int	*lengths;
	int	*prev;
	int	*lis;

	indices = malloc(sizeof(int) * stack_a->size);
	lengths = malloc(sizeof(int) * stack_a->size);
	prev = malloc(sizeof(int) * stack_a->size);
	if (!indices || !lengths || !prev)
		return (NULL);
	fill_indices_array(stack_a, indices, lengths, prev);
	compute_lis_dp(indices, lengths, prev, stack_a->size);
	lis = reconstruct_lis(lengths, prev, stack_a->size, lis_len);
	free(indices);
	free(lengths);
	free(prev);
	return (lis);
}

void	mark_lis_elements(t_stack *stack_a)
{
	int		*positions;
	int		lis_len;
	int		i;

	positions = create_lis_array(stack_a, &lis_len);
	if (!positions)
		return ;
	i = 0;
	while (i < lis_len)
	{
		mark_single_element(stack_a, positions[i]);
		i++;
	}
	free(positions);
}


void	push_back_optimized(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	while (stack_b->size > 0)
	{
		calculate_cost(stack_a, stack_b);
		cheapest = find_cheapest(stack_b);
		execute_move(stack_a, stack_b, cheapest->cost_a, cheapest->cost_b);
	}
	rotate_to_min(stack_a);
}

void	lis_sort(t_stack *stack_a, t_stack *stack_b)
{
	mark_lis_elements(stack_a);
	push_non_lis_to_b(stack_a, stack_b);
	if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 2)
	{
		if (stack_a->top->index > stack_a->top->next->index)
			sa(stack_a, 1);
	}
	push_back_optimized(stack_a, stack_b);
}
