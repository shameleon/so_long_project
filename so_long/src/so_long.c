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

/* 
- initiates mlx 
*/
int	init_mlx(t_data *d)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		outbound(d, "MLX library initiation failure", 3);
	d->win = mlx_new_window(d->mlx, d->tile * d->line_len,
			d->tile * d->nb_lines, d->gameset.win_title);
	if (d->win == NULL)
		outbound(d, "MLX library could not open window", 3);
	return (0);
}

/* 
- load images that will be pointed by d->img structure elements
*/
void	load_sprites(t_data *d)
{
	d->img.wall = xpm_file_to_image(d, d->gameset.xpm_wall);
	if (d->img.wall == NULL)
		outbound(d, "wall image file could not be loaded", 3);
	d->img.floor = xpm_file_to_image(d, d->gameset.xpm_floor);
	if (d->img.floor == NULL)
		outbound(d, "floor image file could not be loaded", 3);
	d->img.player = xpm_file_to_image(d, d->gameset.xpm_player);
	if (d->img.player == NULL)
		outbound(d, "player image file could not be loaded", 3);
	d->img.collect = xpm_file_to_image(d, d->gameset.xpm_collect);
	if (d->img.collect == NULL)
		outbound(d, "collectible image file could not be loaded", 3);
	d->img.exit1 = xpm_file_to_image(d, d->gameset.xpm_exit1);
	if (d->img.exit1 == NULL)
		outbound(d, "exit1 image file could not be loaded", 3);
	d->img.exit0 = xpm_file_to_image(d, d->gameset.xpm_exit0);
	if (d->img.exit0 == NULL)
		outbound(d, "exit0 image file could not be loaded", 3);
	d->img.player_on_exit = xpm_file_to_image(d, d->gameset.xpm_player_on_exit);
	if (d->img.player_on_exit == NULL)
		outbound(d, "player_on_exit image file could not be loaded", 3);
}

/* 
- initializes game settings
*/
int	set_game(t_data	*d)
{
	d->gameset.win_title = "so_long jmouaike";
	d->gameset.xpm_wall = "./rss/wall.xpm";
	d->gameset.xpm_floor = "./rss/floor.xpm";
	d->gameset.xpm_player = "./rss/player.xpm";
	d->gameset.xpm_collect = "./rss/collect_chocolate_egg.xpm";
	d->gameset.xpm_exit0 = "./rss/exit_closed.xpm";
	d->gameset.xpm_exit1 = "./rss/exit_open.xpm";
	d->gameset.xpm_player_on_exit = "./rss/player_on_exit.xpm";
	d->gameset.print_pathfinding = 0;
	d->gameset.min_map_size = 4;
	d->gameset.max_w = 32;
	d->gameset.max_h = 17;
	d->tile = 80;
	return (0);
}

/* 
- initializes data set
*/
int	init_data(t_data *d)
{
	ft_memset(d, 0, sizeof(t_data));
	d->lst = NULL;
	d->line = NULL;
	d->nb_lines = 0;
	d->line_len = 0;
	d->map = NULL;
	d->nb_player = 0;
	d->nb_exit = 0;
	d->nb_collect = 0;
	d->player_x = 0;
	d->player_y = 0;
	d->player_moves = 0;
	d->open_exit = 0;
	return (0);
}

/* main */
int	main(int argc, char **argv)
{
	t_data	d;

	init_data(&d);
	set_game(&d);
	load_and_verify_map(&d, argc, argv);
	check_content(&d);
	pathfinder(&d);
	init_mlx(&d);
	load_sprites(&d);
	display_map(&d);
	mlx_hook(d.win, 2, 1L << 0, game_controls, &d);
	mlx_hook(d.win, 17, 1L << 0, at_mouse_exit, &d);
	mlx_loop(d.mlx);
	outbound(&d, "that error message should not be reached !", 0);
	return (0);
}

/*
issues :
valgrind --leak-check=full --show-leak-kinds=all -s


https://tronche.com/gui/x/xlib/events/keyboard-pointer/keyboard-pointer.html
*/