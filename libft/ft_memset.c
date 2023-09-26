/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:16:27 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/09 12:33:28 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*m;

	m = (unsigned char *)s;
	while (n > 0)
	{
		*m = (unsigned char)c;
		m++;
		n--;
	}
	return (s);
}

/* DESCRIPTION
 * The memset() function fills the first n bytes of the memory area pointed
 * to by s with the constant byte c.
 * RETURN VALUE
 * The memset() function returns a pointer to the memory area s.
*/
