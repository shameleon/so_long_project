/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:30:16 by jmouaike          #+#    #+#             */
/*   Updated: 2023/02/20 16:30:26 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		player_moves(t_data *d, int i, int j)
{
	int		y;
	int		x;

	y = d->player_y + i;
	x = d->player_x + j;
	printf("%d, %d => %d, %d \n ", d->player_y, d->player_x, y, x);
	if (d->map[y][x]  == '1')
		return (0);
	else if (d->map[y][x] != '1')
	{
		mlx_put_image_to_window(d->mlx, d->win, d->img.floor, d->player_x * TILE, d->player_y * TILE);
		//d->map.map[d->pl_y][d->pl_x] = '0';
		mlx_put_image_to_window(d->mlx, d->win, d->img.player, x * TILE, y * TILE);
		//d->map.map[y][x] = 'P';
		d->player_y += i;
		d->player_x += j;
		//|| d->map.map[y][x] == 'C'
		mlx_string_put(d->mlx, d->win, 20, 20, 0x000000FF, "move");
		return (1);
	}
	return (1);
}

int		game_controls(int KeySym, t_data *d)
{
	if (KeySym == 'w' || KeySym == 65362)
		player_moves(d, -1, 0);
	else if (KeySym == 's' || KeySym == 65364)
		player_moves(d, 1, 0);
	else if (KeySym == 'a' || KeySym == 65361)
		player_moves(d, 0, -1);
	else if (KeySym == 'd' || KeySym == 65363)
		player_moves(d, 0, 1);
	else if (KeySym == 'q' || KeySym == 65307)
		printf ("exit game \n");
	return (0);
}

int		display_map(t_data *d)
{
	int		y;
	int		x;

	y = 0;
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x] != '\0')
		{
			if(d->map[y][x] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->img.wall, x * TILE, y * TILE);
			else if(d->map[y][x] == '0')
				mlx_put_image_to_window(d->mlx, d->win, d->img.floor, x * TILE, y * TILE);
			else if(d->map[y][x] == 'E')
				mlx_put_image_to_window(d->mlx, d->win, d->img.exit1, x * TILE, y * TILE);
			else if(d->map[y][x] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->img.collect, x * TILE, y * TILE);
			else if(d->map[y][x] == 'P')
			{
				mlx_put_image_to_window(d->mlx, d->win, d->img.player, x * TILE , y * TILE);
				d->player_x = x;
				d->player_y = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}
