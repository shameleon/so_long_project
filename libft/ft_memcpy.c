/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:02:44 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/09 12:34:26 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

/* DESCRIPTION The  memcpy()  function copies n bytes from memory area src
 * to memory area dest. The memory areas must not overlap.  
 * Use memmove(3) if the memory areas do  overlap.
 * RETURN VALUE
 * The memcpy() function returns a pointer to dest.
*/
