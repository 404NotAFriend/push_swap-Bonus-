/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:14:43 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/24 06:32:41 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	print_with_index(t_stack *stack)
{
	t_node	*current;
	int		count;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	count = 0;
	ft_printf("Values and indices:\n");
	while (count < stack->size)
	{
		ft_printf("  value=%d, index=%d\n", current->value, current->index);
		current = current->next;
		count++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (!parse_arguments(argc, argv, &stack_a))
	{
		error_exit(&stack_a, NULL);
		return (1);
	}
	init_stack(&stack_b);

	ft_printf("✅ Parsing successful!\n");
	print_stack(&stack_a);
	ft_printf("Sorted: %s\n\n", is_sorted(&stack_a) ? "YES" : "NO");

	// Assign indices
	assign_index(&stack_a);

	// Sort based on size
	if (stack_a.size == 2)
		sa(&stack_a, 1);
	else if (stack_a.size == 3)
		sort_three(&stack_a);
	else
		radix_sort(&stack_a, &stack_b);

	ft_printf("\n--- After Sorting ---\n");
	print_stack(&stack_a);
	ft_printf("Sorted: %s\n", is_sorted(&stack_a) ? "YES" : "NO");

	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
