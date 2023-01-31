/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:49:09 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/23 13:33:12 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* main */
int		main(int argc, char **argv)
{
	t_data	*d;

	d = malloc (sizeof(t_data));
	if (!d)
		return (put_error("dynamic memory allocation failed"));
	if (load_and_verify_map(d, argc, argv))
		write (1, "map was successfully loaded and verified : [OK]\n", 48);
	// data->map = (t_map *)malloc (sizeof(t_map *));
	free_map(d->map->map, d->map->nb_lines - 1, 1);
	free (d->map);
	d->map = NULL;
	free (d);
	//data = NULL;
	return (0);
}
