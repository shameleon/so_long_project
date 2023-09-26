/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 07:10:52 by jmouaike          #+#    #+#             */
/*   Updated: 2023/02/02 07:23:20 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* frees a char ** content */
char	**ft_free_split(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free (strs[i]);
		i++;
	}
	free (strs);
	return (NULL);
}
