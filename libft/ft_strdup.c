/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:02:23 by jmouaike          #+#    #+#             */
/*   Updated: 2022/11/21 08:01:49 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dup;
	int		n;

	n = ft_strlen(src);
	dup = (char *)malloc (sizeof(*dup) * (n + 1));
	if (!dup)
		return (NULL);
	dup[n] = '\0';
	n--;
	while (n >= 0)
	{
		dup[n] = src[n];
		n--;
	}
	return (dup);
}
