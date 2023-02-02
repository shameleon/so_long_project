/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:54:52 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/08 14:08:57 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
 * Paramètres 
 * 	s: La chaîne de caractères sur laquelle itérer.
 * 	f: La fonction à appliquer à chaque caractère.
 * Valeur de retour Aucune
 * Fonctions externes autorisées Aucune
 *
 * Description Applique la fonction ’f’ à chaque caractère de la
 * chaîne de caractères transmise comme argument,
 * et en passant son index comme premier argument.
 * Chaque caractère est transmis par adresse à ’f’
 * afin d’être modifié si nécessaire.
 */
