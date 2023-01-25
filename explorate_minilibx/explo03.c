/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explo03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:53:32 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/25 13:06:21 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

#define WIN_W 1024
#define WIN_H 514
#define WIN_TITLE "explore mlx 03"
#define ERR_MLX 0
#define WALL "../so_long/rss/wall.xpm"
#define FLOOR "../so_long/rss/floor.xpm"
#define TILE_SIZE 32

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
    char    *floor;
    char    *wall;
    int     img_w;
    int     img_h;
}               t_img;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
    char    **map;
    t_img   img;
}               t_data;


void    display_background(t_data d)
{
    int     y;
    int     x;

    y = 0;
    d.img.img = mlx_new_image(d.mlx, TILE_SIZE , TILE_SIZE);
    d.img.floor = FLOOR;
    d.img.wall = WALL;
    d.img.img_w = TILE_SIZE;
    d.img.img_h = TILE_SIZE;
    while (d.map[y])
    {
        x = 0;
        while(d.map[y][x] != '\0')
        {
            if(d.map[y][x] == '1')
                d.img.img = mlx_xpm_file_to_image(d.mlx, d.img.wall, &d.img.img_w, &d.img.img_h);
            else if (d.map[y][x] == '0')
                d.img.img = mlx_xpm_file_to_image(d.mlx, d.img.floor, &d.img.img_w, &d.img.img_h);
            mlx_put_image_to_window(d.mlx, d.win, d.img.img, x * TILE_SIZE + 64, y * TILE_SIZE + 64);
            x++;
        }
        y++;
    }
    //d.img.img = mlx_xpm_file_to_image(d.mlx, d.img.wall, &d.img.img_w, &d.img.img_h);
    //mlx_put_image_to_window(d.mlx, d.win, d.img.img, 0, 0);
    //d.img->img = mlx_xpm_file_to_image(d.mlx, d.img->floor, &d.img->img_w, &d.img->img_h);
    //mlx_put_image_to_window(d.mlx, d.win, d.img->img, 32, 32);
}

char    **load_map(t_data d)
{
    char    **map;
    int     i;

    map = (char **)malloc (sizeof(*map) * 10);
    map[0] = "111111111111111111";
    map[1] = "100010100000000101";
    map[2] = "110010100100000101";
    map[3] = "100010110100010101";
    map[4] = "101010000100010001";
    map[5] = "101010000100010001";
    map[6] = "10101000010E010001";
    map[7] = "101010011111111001";
    map[8] = "101000000100000001";
    map[9] = "111111111111111111";
    map[10] = NULL;
    return (map);
}

int main(void)
{
    t_data  d;

    d.mlx = mlx_init();
    if (d.mlx == NULL)
        return (ERR_MLX);
    d.win = mlx_new_window(d.mlx, WIN_W, WIN_H, WIN_TITLE);
    if (d.win == NULL)
    {
        free (d.win);
        return (ERR_MLX);
    }
    d.map = load_map(d);
    display_background(d);
    mlx_loop(d.mlx);
    mlx_destroy_image(d.mlx, d.img.img);
    mlx_destroy_window(d.mlx, d.win);
    mlx_destroy_display(d.mlx);
    free(d.mlx);
    free(d.map);
    return (0);
}
