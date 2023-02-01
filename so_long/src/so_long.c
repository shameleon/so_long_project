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
int		init_game_data(t_data *d)
{
	d->map = (t_map *)malloc (sizeof(t_map *) * 2);
	if (!(d->map))
		return (put_error("t_map dynamic memory allocation failed"));
	d->player = (t_play *)malloc (sizeof(t_play *));
	if (!(d->player))
		return (put_error("t_player dynamic memory allocation failed"));
	d->map->nb_collect = 0;
	d->map->nb_player = 0;
	d->map->nb_exit = 0;
	return (1);
}

/* main */
int		main(int argc, char **argv)
{
	t_data	*d;

	d = (t_data *)malloc (sizeof(t_data *));
	if (!d)
		return (put_error("t_data dynamic memory allocation failed"));
	if (!(init_game_data(d)))
		return (1);
	if (load_and_verify_map(d, argc, argv))
		write (1, "map was successfully loaded and verified : [OK]\n", 48);
	// free only if map exists
	if (d->map->nb_lines > 1)
		free_map(d->map->map, d->map->nb_lines - 1, 1);
	free(d->player);
	free (d->map);
	//d->map = NULL;
	free (d);
	//data = NULL;
	return (0);
}
