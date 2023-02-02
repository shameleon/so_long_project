/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:16:06 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/09 12:31:13 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*m;

	m = (unsigned char *)s;
	while (n > 0)
	{
		if (*m == (unsigned char)c)
			return (m);
		m++;
		n--;
	}
	return (NULL);
}

/* DESCRIPTION : The memchr() function scans the initial n bytes 
 * of the memory area pointed to by s for the first instance of c.
 * Both c and the bytes of the memory area  pointed to by s are
 * interpreted as unsigned char.
 * RETURN VALUE
 * The memchr() and memrchr() functions return a pointer to the
 * matching  byte  or
 * NULL if the character does not occur in the given memory area.
*/
