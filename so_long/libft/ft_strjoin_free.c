/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:39:45 by jmouaike          #+#    #+#             */
/*   Updated: 2023/02/02 07:25:43 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	unsigned int	len;
	unsigned int	i;
	char			*dst;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc (sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	dst[len] = '\0';
	free (s1);
	free (s2);
	return (dst);
}
