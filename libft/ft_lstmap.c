/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho <bramalho@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:50:13 by bramalho          #+#    #+#             */
/*   Updated: 2025/10/20 19:19:55 by bramalho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho <bramalho@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:00:00 by bramalho          #+#    #+#             */
/*   Updated: 2025/10/20 18:00:00 by bramalho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*createandadd(t_list **newlist, void *content
		, void (*del)(void *))
{
	t_list	*newnode;

	newnode = ft_lstnew(content);
	if (!newnode)
	{
		del(content);
		ft_lstclear(newlist, del);
		return (NULL);
	}
	ft_lstadd_back(newlist, newnode);
	return (newnode);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	void	*newcontent;

	newlist = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		newcontent = f(lst->content);
		if (!newcontent)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		if (!createandadd(&newlist, newcontent, del))
			return (NULL);
		lst = lst->next;
	}
	return (newlist);
}
