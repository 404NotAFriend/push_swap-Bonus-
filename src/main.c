/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:14:43 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/23 19:22:31 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

// Temporary test function - we'll remove this later
static void	print_stack(t_stack *stack)
{
	t_node	*current;
	int		count;

	if (!stack || !stack->top)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	current = stack->top;
	count = 0;
	ft_printf("Stack (size=%d): ", stack->size);
	while (count < stack->size)
	{
		ft_printf("%d ", current->value);
		current = current->next;
		count++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	if (!parse_arguments(argc, argv, &stack_a))
	{
		error_exit(&stack_a, NULL);
		return (1);
	}
	ft_printf("✅ Parsing successful!\n");
	print_stack(&stack_a);
	ft_printf("Sorted: %s\n", is_sorted(&stack_a) ? "YES" : "NO");
	free_stack(&stack_a);
	return (0);
}
