/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 07:04:04 by jmouaike          #+#    #+#             */
/*   Updated: 2023/02/05 08:45:02 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcountchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s && *s != '\0')
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}
