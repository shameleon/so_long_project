/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explo02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:53:32 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/12 07:57:07 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

#define WIN_W 1800
#define WIN_H 800
#define WIN_TITLE "explore mlx 02"
#define ERR_MLX 1
#define WALL "../so_long/rss/wall.xpm"
#define FLOOR "../so_long/rss/floor.xpm"
#define TILE_SIZE 80

typedef struct  s_map
{
    char    **map;
}               t_map;

typedef struct  s_img
{
	void	*img;
	char	*addr;
	int		endian;
	int		bpp;
	int		line_len;
    char    *path;
    int     img_w;
    int     img_h;
}               t_img;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
    t_img   *img;
}               t_data;

int main(void)
{
    t_data  d;

    d.mlx = mlx_init();
    if (d.mlx == NULL)
        return (ERR_MLX);
    d.win = mlx_new_window(d.mlx, WIN_H, WIN_H, WIN_TITLE);
    if (d.win == NULL)
    {
        free (d.win);
        return (ERR_MLX);
    }
    d.img->path = FLOOR;
    d.img->img_w = TILE_SIZE;
    d.img->img_h = TILE_SIZE;
    d.img->img = mlx_xpm_file_to_image(d.mlx, d.img->path, &d.img->img_w, &d.img->img_h);
    mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
    mlx_loop(d.mlx);
    mlx_destroy_image(d.mlx, d.img);
    mlx_destroy_window(d.mlx, d.win);
    mlx_destroy_display(d.mlx);
    free(d.mlx);
    return (0);
}