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

static void	rotate_to_target(t_stack *stack_a, int target_pos)
{
	int	pos;

	pos = 0;
	if (target_pos <= stack_a->size / 2)
	{
		while (pos < target_pos)
		{
			ra(stack_a, 1);
			pos++;
		}
	}
	else
	{
		while (pos < (stack_a->size - target_pos))
		{
			rra(stack_a, 1);
			pos++;
		}
	}
}

void	push_back_optimized(t_stack *stack_a, t_stack *stack_b)
{
	int	target_pos;

	while (stack_b->size > 0)
	{
		target_pos = find_target_pos(stack_a, stack_b->top->index);
		rotate_to_target(stack_a, target_pos);
		pa(stack_a, stack_b, 1);
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
