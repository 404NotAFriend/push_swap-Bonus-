/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:14:51 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/23 19:19:46 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	parse_single_string(char *str, t_stack *stack_a)
{
	char	**numbers;
	int		i;

	numbers = ft_split(str, ' ');
	if (!numbers || !numbers[0])
		return (free_split(numbers), 0);
	i = 0;
	while (numbers[i])
	{
		if (!add_number(numbers[i], stack_a))
			return (free_split(numbers), 0);
		i++;
	}
	free_split(numbers);
	return (1);
}

static int	parse_multiple_args(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!add_number(argv[i], stack_a))
			return (0);
		i++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	if (argc < 2)
		return (0);
	init_stack(stack_a);
	if (argc == 2)
	{
		if (!parse_single_string(argv[1], stack_a))
			return (0);
	}
	else
	{
		if (!parse_multiple_args(argc, argv, stack_a))
			return (0);
	}
	if (has_duplicates(stack_a))
		return (0);
	return (1);
}
