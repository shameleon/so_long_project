/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:11:14 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/08 10:17:47 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	slen = ft_strlen(src);
	if ((!dst || !src) && !size)
		return (slen);
	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (size + slen);
	i = 0;
	while (src[i] != '\0' && dlen + i + 1 < size)
	{
		dst[dlen + i] = src [i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
