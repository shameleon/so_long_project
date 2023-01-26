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
#define WIN_TITLE "so_long / explore mlx 03"
#define ERR_MLX 0
#define TILE_SIZE 32
#define XPM_WALL "../so_long/rss/wall.xpm"
#define XPM_FLOOR "../so_long/rss/floor.xpm"

typedef struct  s_map
{
    char    **map;
    int     line_len;
    int     nb_lines;
}               t_map;

typedef struct  s_img
{
	void	*img;
    char    *path;
    int     w;
    int     h;
}               t_img;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
    t_map   map;
    t_img   *wall;
    t_img   *floor;
    t_img   *player;
}               t_data;

int     display_map(t_data *d)
{
    // mlx_put_image_to_window(d->mlx, d->win, d->wall.img, 1 * TILE, 1 * TILE);
    return (0);
}

/*
{
    int     y;
    int     x;

    y = 0;
    while (d->map.map[y])
    {
        x = 0;
        while (d->map.map[y][x] != '\0')
        {
            if(d->map.map[y][x] == '1')
                mlx_put_image_to_window(d->mlx, d->win, d->wall.img, x * TILE, y * TILE);
            else if(d->map.map[y][x] == '0')
                mlx_put_image_to_window(d->mlx, d->win, d->floor.img, x * TILE, y * TILE);
            else if(d->map.map[y][x] == 'P')
                mlx_put_image_to_window(d->mlx, d->win, d->player.img, x * TILE , y * TILE);
            x++;
        }
        y++;
    }
    return (0);
}
*/
/*
void    display_background(t_data *d)
{
    int     y;
    int     x;

    y = 0;
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
*/

t_img   *load_images(t_data *d, char   c)
{
    t_img   *tile;

    tile.w = TILE_SIZE;
    tile.h = TILE_SIZE;
    if (c == '1')
        tile.path = XPM_WALL;
    tile.img = mlx_xpm_file_to_image(d->mlx, tile.path , &tile.w, &tile->h);
    return (tile);
}

/*
    d->wall.h = TILE;
    d->wall.path = XPM_WALL;
    d->wall.img = mlx_xpm_file_to_image(d->mlx, d->wall.path , &d->wall.w, &d->wall.h);
    //d->floor = load_xpm(d ,"../so_long/rss/floor.xpm");
    //d->player = load_xpm(d ,"../so_long/rss/player.xpm");
    return (0);
} */

int     load_map(t_data *d)
{
    d->map.nb_lines = 10;
    d->map.line_len = 18;
    d->map.map = (char **)malloc (sizeof(char *) * 11);
    d->map.map[0] = "111111111111111111";
    d->map.map[1] = "100010100000000101";
    d->map.map[2] = "110010100100000101";
    d->map.map[3] = "100010110100010101";
    d->map.map[4] = "101010000100010001";
    d->map.map[5] = "101010000100010001";
    d->map.map[6] = "10101000010P010001";
    d->map.map[7] = "101010011111111001";
    d->map.map[8] = "101000000100000001";
    d->map.map[9] = "111111111111111111";
    d->map.map[10] = NULL;
    return (0);
}

int        init_mlx(t_data *d)
{
    d->mlx = mlx_init();
    if (d->mlx == NULL)
        return (ERR_MLX);
    d->win = mlx_new_window(d->mlx, WIN_W, WIN_H, WIN_TITLE);
    if (d->win == NULL)
    {
        free (d->win);
        return (ERR_MLX);
    }
    return (0);
}

int main(void)
{
    t_data  *d;

    d = malloc(sizeof(t_data));
    load_map(d);
    d->wall = load_image(d, '1');
    init_mlx(d);
    //display_map(d);
    mlx_loop(d->mlx);
    mlx_destroy_image(d->mlx, d->wall->img);
    //mlx_destroy_image(d->mlx, d->floor.img);
    //mlx_destroy_image(d->mlx, d->player.img);
    free (d->map.map);
    mlx_destroy_window(d->mlx, d->win);
    mlx_destroy_display(d->mlx);
    free(d->mlx);
    free(d);
    return (0);
}
