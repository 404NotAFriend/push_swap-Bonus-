/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:50:07 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/25 00:08:45 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	fill_indices_array(t_stack *stack_a, int *indices, int *lengths,
	int *prev)
{
	t_node	*current;
	int		i;

	current = stack_a->top;
	i = 0;
	while (i < stack_a->size)
	{
		indices[i] = current->index;
		lengths[i] = 1;
		prev[i] = -1;
		current = current->next;
		i++;
	}
}

void	compute_lis_dp(int *indices, int *lengths, int *prev,
	int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (indices[j] < indices[i] && lengths[j] + 1 > lengths[i])
			{
				lengths[i] = lengths[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	push_non_lis_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	rotations;

	size = stack_a->size;
	rotations = 0;
	while (rotations < size)
	{
		if (stack_a->top->keep_in_a == 0)
		{
			pb(stack_a, stack_b, 1);
			rotations = 0;
		}
		else
		{
			ra(stack_a, 1);
			rotations++;
		}
		if (rotations >= size)
			break ;
	}
}

void	mark_single_element(t_stack *stack_a, int target_pos)
{
	t_node	*current;
	int		pos;

	current = stack_a->top;
	pos = 0;
	while (pos < stack_a->size)
	{
		if (pos == target_pos)
		{
			current->keep_in_a = 1;
			break ;
		}
		current = current->next;
		pos++;
	}
}
