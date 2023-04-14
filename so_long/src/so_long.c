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
https://tronche.com/gui/x/xlib/events/types.html
https://qst0.github.io/ft_libgfx/man_mlx_loop.html
https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx
*/

/* 
- exit upon mouse click on window corner
*/
int		at_mouse_exit(t_data *d)
{
	outbound(d, "Window closed : game over", 3);
	return (0);
}

/* 
- initiates mlx 
*/
int		init_mlx(t_data *d)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		outbound(d, "MLX library initiation failure", 3);
	d->win = mlx_new_window(d->mlx, TILE * d->line_len, TILE * d->nb_lines, WIN_TITLE);
	if (d->win == NULL)
		outbound(d, "MLX library could not open window", 3);
	return (0);
}

/* 
- load images that will be pointed by d->img structure elements
*/
void	load_sprites(t_data *d)
{
	d->img.wall = mlx_xpm_file_to_image(d->mlx, XPM_WALL, &d->img.w, &d->img.h);
	if (d->img.wall == NULL)
		outbound(d, "wall image file could not be loaded", 3);
	d->img.floor = mlx_xpm_file_to_image(d->mlx, XPM_FLOOR, &d->img.w, &d->img.h);
	if (d->img.floor == NULL)
		outbound(d, "floor image file could not be loaded", 3);
	d->img.player = mlx_xpm_file_to_image(d->mlx, XPM_PLAYER, &d->img.w, &d->img.h);
	if (d->img.player == NULL)
		outbound(d, "player image file could not be loaded", 3);
	d->img.collect = mlx_xpm_file_to_image(d->mlx, XPM_COLLECT, &d->img.w, &d->img.h);
	if (d->img.collect == NULL)
		outbound(d, "collectible image file could not be loaded", 3);
	d->img.exit1 = mlx_xpm_file_to_image(d->mlx, XPM_EXIT1, &d->img.w, &d->img.h);
	if (d->img.exit1 == NULL)
		outbound(d, "exit1 image file could not be loaded", 3);
	d->img.exit0 = mlx_xpm_file_to_image(d->mlx, XPM_EXIT0, &d->img.w, &d->img.h);
	if (d->img.exit0 == NULL)
		outbound(d, "exit0 image file could not be loaded", 3);
	d->img.player_on_exit = mlx_xpm_file_to_image(d->mlx, XPM_PLAYER_ON_EXIT, &d->img.w, &d->img.h);
	if (d->img.player_on_exit == NULL)
		outbound(d, "player_on_exit image file could not be loaded", 3);
}

int		init_data(t_data *d)
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
	return(0);
}

/* main */
int		main(int argc, char **argv)
{
	t_data	d;

	init_data(&d);
	load_and_verify_map(&d, argc, argv);
	check_content(&d);
	pathfinder(&d);
	init_mlx(&d);
	load_sprites(&d);
	display_map(&d);
	mlx_hook(d.win, 2, 1L<<0, game_controls, &d);
	mlx_hook(d.win, 17, 1L<<0, at_mouse_exit, &d);
	mlx_loop(d.mlx);
	outbound(&d, "EXIT after success", 0);
	return (0);
}


/*
issues :
valgrind --leak-check=full --show-leak-kinds=all -s
1- still reachable main->load_sprites->mlx_xpam_file_to_image-
	XShmCreateImage -> calloc
	===> free textures in outbound / destruct_data()

https://tronche.com/gui/x/xlib/events/keyboard-pointer/keyboard-pointer.html
*/