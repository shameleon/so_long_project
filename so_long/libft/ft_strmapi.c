/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:20:48 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/09 12:31:37 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const*s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*map;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	map = (char *)malloc (sizeof(*map) * (len +1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}

/*
 * Paramètres
 *      s: La chaîne de caractères sur laquelle itérer.
 *      f: La fonction à appliquer à chaque caractère.
 * Valeur de retour Aucune
 * Fonctions externes autorisées Aucune
 *
 * Description Applique la fonction ’f’ à chaque caractère de la
 * chaîne de caractères passée en argument pour créer
 * une nouvelle chaîne de caractères (avec malloc(3))
 * résultant des applications successives de ’f’.
 */
