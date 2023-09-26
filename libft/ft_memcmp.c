/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:16:57 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/09 12:36:00 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*m1 != *m2)
			return (*m1 - *m2);
		m1++;
		m2++;
		n--;
	}
	return (0);
}

/* DESCRIPTION The memcmp() function compares the first n bytes 
 * (each interpreted as unsigned char) of the memory areas s1 and s2.
 * RETURN VALUE
 * The memcmp() function returns an integer less than, equal to, 
 * or greater than  zero  if the  first  n  bytes  of  s1  is  found,
 * respectively, to be less than, to match, or be greater than the 
 * first n bytes of s2.
 * For a nonzero return value, the sign is determined by the sign of
 * the  difference  between the first pair of bytes 
 * (interpreted as unsigned char) that differ in s1 and s2.
 * If n is zero, the return value is zero.
*/
