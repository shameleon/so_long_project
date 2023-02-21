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

int		init_mlx(t_data *d)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		outbound(d, "MLX library initiation failure", 2);
	d->win = mlx_new_window(d->mlx, TILE * d->line_len, TILE * d->nb_lines, WIN_TITLE);
	if (d->win == NULL)
		outbound(d, "MLX library could not open window", 2);
	return (0);
}

void	load_sprites(t_data *d)
{
	d->img.wall = mlx_xpm_file_to_image(d->mlx, XPM_WALL, &d->img.w, &d->img.h);
	if (d->img.wall == NULL)
		outbound(d, "wall image file could not be loaded", 2);
	d->img.floor = mlx_xpm_file_to_image(d->mlx, XPM_FLOOR, &d->img.w, &d->img.h);
	if (d->img.floor == NULL)
		outbound(d, "floor image file could not be loaded", 2);
	d->img.player = mlx_xpm_file_to_image(d->mlx, XPM_PLAYER, &d->img.w, &d->img.h);
	if (d->img.player == NULL)
		outbound(d, "player image file could not be loaded", 2);
	d->img.collect = mlx_xpm_file_to_image(d->mlx, XPM_COLLECT, &d->img.w, &d->img.h);
	if (d->img.collect == NULL)
		outbound(d, "collectible image file could not be loaded", 2);
	d->img.exit1 = mlx_xpm_file_to_image(d->mlx, XPM_EXIT1, &d->img.w, &d->img.h);
	if (d->img.exit1 == NULL)
		outbound(d, "exit1 image file could not be loaded", 2);
	d->img.exit0 = mlx_xpm_file_to_image(d->mlx, XPM_EXIT0, &d->img.w, &d->img.h);
	if (d->img.exit0 == NULL)
		outbound(d, "exit0 image file could not be loaded", 2);
}

int		init_data(t_data *d)
{
	ft_memset(d, 0, sizeof(t_data));
	d->lst = NULL;
	d->nb_lines = 0;
	d->line_len = 0;
	d->map = NULL;
	d->nb_player = 0;
	d->nb_exit = 0;
	d->nb_collect = 0;
	d->player_x = 0;
	d->player_y = 0;
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
	load_sprites(&d);
	init_mlx(&d);
	display_map(&d);
	mlx_hook(d.win, 2, 1L<<0, game_controls, &d);
	//mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_loop(d.mlx);
	outbound(&d, "EXIT after success", 0);
	return (0);
}

/* 
 gcc -Wall -Werror -Wextra ./src/so_long.c ./src/load_map.c 
 ./src/so_long_utils.c ./src/outbound.c -I ./include/ 
 -I ./libft/ -L ./libft/ -lft  -o so_long -g3 -fsanitize=address
*/