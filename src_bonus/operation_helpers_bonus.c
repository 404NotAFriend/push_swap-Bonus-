/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_helpers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:00:00 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/25 14:00:00 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	execute_swap_ops(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa_bonus(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_bonus(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_bonus(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	execute_push_ops(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		pa_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb_bonus(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	execute_rotate_ops(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra_bonus(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_bonus(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra_bonus(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb_bonus(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_bonus(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
