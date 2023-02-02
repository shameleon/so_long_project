/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:42:51 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/05 11:32:43 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* Parameters: 
 * 	lst : pointer address to the first element of the list
 * 	new : pointer address to the element to be added to the list
 * Returns: none
 * Description:
 * 	adds 'new' element to the beginning og the list 'lst'
 * */
