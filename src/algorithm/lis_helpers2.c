/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helpers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:52:43 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 23:51:15 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_up_to_min(t_stack *stack_a, int min_index)
{
	while (stack_a->top->index != min_index)
		ra(stack_a, 1);
}

static void	rotate_down_to_min(t_stack *stack_a, int min_index)
{
	while (stack_a->top->index != min_index)
		rra(stack_a, 1);
}

void	rotate_to_min(t_stack *stack_a)
{
	t_node	*current;
	int		min_pos;
	int		min_index;
	int		pos;

	assign_positions(stack_a);
	current = stack_a->top;
	min_pos = 0;
	min_index = current->index;
	pos = 0;
	while (pos < stack_a->size)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (min_pos <= stack_a->size / 2)
		rotate_up_to_min(stack_a, min_index);
	else
		rotate_down_to_min(stack_a, min_index);
}

static int	*create_lis_array(int max_len)
{
	int	*lis;

	lis = malloc(sizeof(int) * max_len);
	return (lis);
}

int	*reconstruct_lis(int *lengths, int *prev, int size,
	int *lis_len)
{
	int	*lis;
	int	max_len;
	int	max_idx;
	int	i;

	find_max_lis_position(lengths, size, &max_len, &max_idx);
	lis = create_lis_array(max_len);
	if (!lis)
		return (NULL);
	i = max_len - 1;
	while (max_idx != -1)
	{
		lis[i] = max_idx;
		max_idx = prev[max_idx];
		i--;
	}
	*lis_len = max_len;
	return (lis);
}
