/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:17:58 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/09 12:32:43 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest <= src)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	return (dest);
}

/* DESCRIPTION The  memmove() function copies n bytes from memory area src
 * to memory area dest.
 * The memory areas may overlap: copying takes place as though the bytes
 * in src are first  copied  into a temporary array that does not overlap 
 * src or dest, and the ytes are then copied from the temporary array to dest.
 * RETURN VALUE
 * The memmove() function returns a pointer to dest.
*/
