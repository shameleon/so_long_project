/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:33:11 by jmouaike          #+#    #+#             */
/*   Updated: 2022/11/24 15:36:08 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc (sizeof(*new) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* Parameters:  content of the new element
 * Returns: the new element
 * 
 * Description: creates a 'new' t_list element.
 * allocates heap memory with malloc(3)
 * initializes content variables : with the value of content parameter 
 * and pointing to NULL 
 * */
