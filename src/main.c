/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:14:43 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/29 05:09:27 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	execute_sorting_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->top->index > stack_a->top->next->index)
			sa(stack_a, 1);
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_small(stack_a, stack_b);
	else
		lis_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 2 && !argv[1][0])
		return (0);
	if (!parse_arguments(argc, argv, &stack_a))
	{
		error_exit(&stack_a, NULL);
		return (1);
	}
	init_stack(&stack_b);
	assign_index(&stack_a);
	if (!is_sorted(&stack_a))
		execute_sorting_algorithm(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
