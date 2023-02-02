/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 07:06:28 by jmouaike          #+#    #+#             */
/*   Updated: 2022/11/28 11:16:03 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new;

	map = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{	
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new);
		lst = lst->next;
	}
	return (map);
}

/* iterates through 'lst' list and applies function 'f' to the content of
 * each element.
 * creates a new list resulting from sequential applications of 'f'.
 * if necessary, 'del' function might erase an element.
 * returns the new list */
