/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:21:39 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 07:25:22 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	t_node	*original_top;
	int		count;

	if (!stack || !stack->top || stack->size == 0)
		return ;
	original_top = stack->top;
	current = stack->top;
	count = 0;
	while (current && count < stack->size)
	{
		next = current->next;
		free(current);
		count++;
		if (next == original_top)
			break ;
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}
