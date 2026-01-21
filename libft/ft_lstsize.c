/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho <bramalho@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:08:00 by bramalho          #+#    #+#             */
/*   Updated: 2025/10/20 17:31:09 by bramalho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	if (!lst)
		return (0);
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}
