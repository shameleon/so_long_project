/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:58:01 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/08 10:23:57 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const	*s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc (sizeof(*dst) * (len1 + len2 + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		dst[i] = s2[i - len1];
		i++;
	}
	dst[len1 + len2] = '\0';
	return (dst);
}

/* Paramètres :
 *         
 *      ----------0    ======0      
 *      |              |  
 *      s1             s2 
 *
 * s1: La chaîne de caractères préfixe.
 * s2: La chaîne de caractères suffixe.
 
 * Valeur de retour : La nouvelle chaîne de caractères.
 * NULL si l’allocation échoue.
 *
 *        ----------=====0
 *        |
 *       dst
 
 * Fonctions externes autorisées : malloc
 
 * Description : Alloue (avec malloc(3))
 * retourne une nouvelle chaîne, résultat
 * de la concaténation de s1 et s2. */
