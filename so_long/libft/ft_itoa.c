/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:26:35 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/01 16:03:33 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_size(long int nb, long int sign)
{
	long int	size;

	size = 0;
	if (sign < 0)
		size++;
	while (nb > 9)
	{
		nb = nb / 10;
		size++;
	}
	size++;
	return (size);
}

static char	*fill_str_with_digits(long int nb, long int sign, long int size)
{
	long int	i;
	char		*str;

	str = (char *)malloc (sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (size > 0)
	{
		i = size - 1;
		while (i > 0)
		{
			str[i] = nb % 10 + '0';
			if (nb > 9)
				nb = nb / 10;
			i--;
		}
		if (sign < 0)
			str[0] = '-';
		else
			str[0] = nb % 10 + '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	sign;
	long int	nb;
	long int	size;
	char		*str;

	sign = 1;
	if (n < 0)
		sign = -1;
	nb = (long int)(sign * n);
	size = get_nb_size(nb, sign);
	str = fill_str_with_digits(nb, sign, size);
	return (str);
}
