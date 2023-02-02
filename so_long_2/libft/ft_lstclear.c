/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:54:27 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/05 13:57:30 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;

	if (!lst || !del)
		return ;
	element = (*lst);
	while (*lst)
	{
		element = (*lst);
		del(element->content);
		(*lst) = element->next;
		free(element);
	}
}

/* clears linked-list
 * if element content relies on memory allocation: ft_lstclear(&lst, free);
 * */
