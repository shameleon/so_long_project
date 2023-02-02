/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:13:23 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/08 10:22:28 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lit_len;

	if (!big && !len)
		return (NULL);
	lit_len = ft_strlen(little);
	if (lit_len > 0)
	{
		while (*big != '\0' && len > 0)
		{
			if (*big == *little)
			{
				if (ft_strncmp(big, little, lit_len) == 0)
					return ((char *)big);
			}
			len--;
			big++;
			if ((len < lit_len) || *big == '\0')
				return (NULL);
		}
		return (NULL);
	}
	return ((char *)big);
}

/*DESCRIPTION
The strnstr() function locates the first occurrence of the null-terminated 
string little in the string big where not more than len characters are searched
Characters that appear after a ‘\0’ character are not searched.  Since the
strnstr() function is a FreeBSD specific API, it should only be used when
portability is not a concern.

RETURN VALUES
If little is an empty string, big is returned;
if little occurs nowhere in big, NULL is returned otherwise a pointer to
the first character of the first occurrence of little is returned.
*/
