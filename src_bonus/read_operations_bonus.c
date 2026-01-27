/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:15:00 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/25 23:30:00 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	execute_operation(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(line, "\n") == 0)
		return (1);
	if (execute_swap_ops(line, stack_a, stack_b))
		return (1);
	if (execute_push_ops(line, stack_a, stack_b))
		return (1);
	if (execute_rotate_ops(line, stack_a, stack_b))
		return (1);
	return (0);
}

int	read_and_execute(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_operation(line, stack_a, stack_b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}
