/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:16:53 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/23 19:19:32 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_overflow(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	add_number(char *str, t_stack *stack_a)
{
	t_node	*new_node;
	int		value;

	if (!is_valid_number(str))
		return (0);
	if (is_overflow(str))
		return (0);
	value = ft_atoi(str);
	new_node = create_node(value);
	if (!new_node)
		return (0);
	add_bottom(stack_a, new_node);
	return (1);
}
