/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:58:50 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/09 09:01:53 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	up;
	size_t	down;

	up = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[up] && ft_strchr(set, s1[up]))
		up++;
	down = ft_strlen(s1);
	while (down > up && ft_strchr(set, s1[down - 1]))
		down--;
	if (up > down)
		return (NULL);
	trim = ft_substr(s1, up, down - up);
	return (trim);
}

/* Paramètres:
 * s1:                                           ---=========-----0
 * 	La chaîne de caractères à trimmer.       |
 *                                               s1
 * set: 
 * 	Le set de référence de caractères à trimmer.
 * Valeur de retour
 * 	La chaîne de caractères trimmée.            =========0
 * 	NULL si l’allocation échoue.                |
 *                                                 trim
 * 	Fonctions externes autorisées : malloc
 *
 * Description:
 * 	 Alloue (avec malloc(3)) et retourne une copie de
 * 	 la chaîne ’s1’, sans les caractères spécifiés
 * 	 dans ’set’ au début et à la fin de la chaîne de
 * 	 caractères.
 */
