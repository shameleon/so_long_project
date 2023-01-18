/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explo01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:50:03 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/29 10:47:03 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

# define WIN_W 800
# define WIN_H 600
# define MLX_ERROR 1

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		endian;
	int		bpp;
	int		line_len;
} t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	canvas;
}	t_vars;

/* index = line_len * y + x * (bpp / 8) */
void	put_color(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_background(t_vars *vars)
{
	int		x;
	int		y;
	int		color;

	color = 0x00ffd700; // mlx_rgb("gold1")
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			//mlx_pixel_put(vars->mlx, vars->win, j, i, 0xFF000);
			put_color(&vars->canvas, x, y, color);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "Coucou je suis d humeur jaune");
	if (vars.win == NULL)
	{
		free (vars.win);
		return (MLX_ERROR);
	}
	vars.canvas.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	vars.canvas.addr = mlx_get_data_addr(vars.canvas.img, &vars.canvas.bpp, &vars.canvas.line_len, &vars.canvas.endian);
	draw_background(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.canvas.img, 0, 0);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.canvas.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}

