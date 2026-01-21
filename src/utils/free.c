/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:21:39 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/21 22:11:29 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	int		count;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	count = stack->size;
	while (count > 0)
	{
		temp = current->next;
		free(current);
		current = temp;
		count --;
	}
	stack->top = NULL;
	stack->size = 0;
}
