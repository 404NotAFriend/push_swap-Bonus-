/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:30:00 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/25 18:45:00 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	check_result(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 0 && is_sorted(stack_a))
	{
		ft_printf("OK\n");
		return (1);
	}
	else
	{
		ft_printf("KO\n");
		return (0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	if (!parse_arguments(argc, argv, &stack_a))
	{
		error_exit(&stack_a, NULL);
		return (1);
	}
	init_stack(&stack_b);
	if (!read_and_execute(&stack_a, &stack_b))
	{
		error_exit(&stack_a, &stack_b);
		return (1);
	}
	check_result(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
