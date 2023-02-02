/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:16:29 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/08 10:21:05 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const*s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	sub_len;
	char			*sub;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	sub_len = len;
	if (start + len > src_len)
		sub_len = src_len - start;
	if (start > src_len)
		sub_len = 0;
	sub = (char *)malloc (sizeof(*sub) * (sub_len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}	
	sub[i] = '\0';
	return (sub);
}

/*Paramètres:
 * s:
 * 	La chaîne de laquelle extraire la nouvelle chaîne.
 * start:
 * 	L’index de début de la nouvelle chaîne dans la chaîne ’s’.
 * len:
 * 	La taille maximale de la nouvelle chaîne.
 *
 * Valeur de retour:
 * 	La nouvelle chaîne de caractères.
 * 	NULL si l’allocation échoue
 *
 * Fonctions externes autorisées : malloc
 *
 * Description:
 * 	Alloue (avec malloc(3)) et retourne une chaîne de caractères 
 * 	issue de la chaîne ’s’.
 * 	Cette nouvelle chaîne commence à l’index ’start’ et
 * 	a pour taille maximale ’len’. 
 *
 *                         len
 *                      ----------->
 *                      -------------------->
 *               s  ===================0
 *                      |
 *                    start
 * 	*/
