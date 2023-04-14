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

void	collect_item(t_data *d, int y, int x)
{
	d->map[y][x] = '0';
	if (d->nb_collect > 0)
	{
		d->nb_collect -= 1;
		put_labeled_int("remaining to collect : ", d->nb_collect, " eggs");
		if (d->nb_collect == 0)
		{
			d->open_exit = 1;
			mlx_put_image_to_window(d->mlx, d->win, d->img.exit1, d->exit_x * TILE, d->exit_y * TILE);
		}
	}
}

/* 
- eventual updates upon 'game_controls()' sent params
- checks if next move coords ( x and y ) and if needed tiggers adequate updates :
	- display update : places player sprite on new pos
		and replaces previous pos with floor or exit.
	- player position values update 
	- update value for number of moves 
		and writes it on terminal stdout         --> put_labeled_int()
	- collectible found                          --> collect_item()
- updates display according to player moves
*/
int		player_moves(t_data *d, int i, int j)
{
	int		y;
	int		x;

	y = d->player_y + i;
	x = d->player_x + j;
	if (d->map[y][x]  == '1')
		return (0);
	else if (d->map[y][x] != '1')
	{
		if (d->map[y - i][x - j] == 'E' && d->open_exit == 0)
			mlx_put_image_to_window(d->mlx, d->win, d->img.exit0, d->player_x * TILE, d->player_y * TILE);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->img.floor, d->player_x * TILE, d->player_y * TILE);
		if (d->map[y][x] != 'E')
			mlx_put_image_to_window(d->mlx, d->win, d->img.player, x * TILE, y * TILE);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->img.player_on_exit, x * TILE, y * TILE);
		d->player_y += i;
		d->player_x += j;
		d->player_moves += 1;
		put_labeled_int("plaver : ", d->player_moves, " moves");
		if (d->map[y][x] == 'C')
			collect_item(d, y, x);
		else if (d->map[y][x] == 'E' && d->open_exit == 1)
			end_game(d);
		return (1);
	}
	return (1);
}

/* 
- games control : 
- arrows and aswd keys to move   - q and esc to quit
*/
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
		outbound(d, "Premature exiting : game over", 2);
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
				mlx_put_image_to_window(d->mlx, d->win, d->img.exit0, x * TILE, y * TILE);
			else if(d->map[y][x] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->img.collect, x * TILE, y * TILE);
			else if(d->map[y][x] == 'P')
				mlx_put_image_to_window(d->mlx, d->win, d->img.player, x * TILE , y * TILE);
			x++;
		}
		y++;
	}
	return (0);
}
