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
			put_img_to_window(d, d->img.exit1, d->exit_x, d->exit_y);
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
void	player_moves(t_data *d, int i, int j)
{
	int		y;
	int		x;

	y = d->player_y + i;
	x = d->player_x + j;
	if (d->map[y][x] != '1')
	{
		if (d->map[y - i][x - j] == 'E' && d->open_exit == 0)
			put_img_to_window(d, d->img.exit0, d->player_x, d->player_y);
		else
			put_img_to_window(d, d->img.floor, d->player_x, d->player_y);
		if (d->map[y][x] != 'E')
			put_img_to_window(d, d->img.player, x, y);
		else
			put_img_to_window(d, d->img.player_on_exit, x, y);
		d->player_y += i;
		d->player_x += j;
		d->player_moves += 1;
		put_labeled_int("plaver : ", d->player_moves, " moves");
		if (d->map[y][x] == 'C')
			collect_item(d, y, x);
		else if (d->map[y][x] == 'E' && d->open_exit == 1)
			end_game(d);
	}
}

/* 
- games control : 
- arrows and aswd keys to move   - q and esc to quit
*/
int	game_controls(int KeySym, t_data *d)
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
		outbound(d, "key [q] pressed for exiting : game over", 3);
	return (0);
}

int	display_map(t_data *d)
{
	int		y;
	int		x;

	y = 0;
	while (d->map[y])
	{
		x = 0;
		while (d->map[y][x] != '\0')
		{
			if (d->map[y][x] == '1')
				mlx_put_image_to_window(d, d->img.wall, x, y);
			else if (d->map[y][x] == '0')
				mlx_put_image_to_window(d, d->img.floor, x, y);
			else if (d->map[y][x] == 'E')
				mlx_put_image_to_window(d, d->img.exit0, x, y);
			else if (d->map[y][x] == 'C')
				mlx_put_image_to_window(d, d->img.collect, x, y);
			else if (d->map[y][x] == 'P')
				mlx_put_image_to_window(d, d->img.player, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
