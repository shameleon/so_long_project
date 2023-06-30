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
#define ERR_MLX 1
#define XPM_WALL "../so_long/rss/wall.xpm"
#define XPM_FLOOR "../so_long/rss/floor.xpm"
#define TILE 32

typedef struct  s_map
{
    char    **map;
    int     line_len;
    int     nb_lines;
}               t_map;

typedef struct  s_img
{
	void	*wall;
    void    *floor;
    void    *player;
    void    *collect;
    void    *exit;
    int     w;
    int     h;
}               t_img;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
    t_map   map;
    t_img   img;
    int     pl_x;
    int     pl_y;
}               t_data;

int        init_mlx(t_data *d)
{
    d->mlx = mlx_init();
    if (d->mlx == NULL)
        return (ERR_MLX);
    d->win = mlx_new_window(d->mlx, TILE * d->map.line_len, TILE * d->map.nb_lines, WIN_TITLE);
    if (d->win == NULL)
    {
        free (d->win);
        return (ERR_MLX);
    }
    return (0);
}

int     load_map(t_data *d)
{
    d->map.nb_lines = 10;
    d->map.line_len = 18;
    d->map.map = (char **)malloc (sizeof(char *) * 11);
    d->map.map[0] = "111111111111111111";
    d->map.map[1] = "1000101000000001C1";
    d->map.map[2] = "1100101001000C0101";
    d->map.map[3] = "10C010110100010101";
    d->map.map[4] = "101010000100010001";
    d->map.map[5] = "101010000100010001";
    d->map.map[6] = "10101000010P010001";
    d->map.map[7] = "101010011111111001";
    d->map.map[8] = "1010C00E0100000001";
    d->map.map[9] = "111111111111111111";
    d->map.map[10] = NULL;
    return (0);
}

int     display_map(t_data *d)
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
                mlx_put_image_to_window(d->mlx, d->win, d->img.wall, x * TILE, y * TILE);
            else if(d->map.map[y][x] == '0')
                mlx_put_image_to_window(d->mlx, d->win, d->img.floor, x * TILE, y * TILE);
            else if(d->map.map[y][x] == 'E')
                mlx_put_image_to_window(d->mlx, d->win, d->img.exit, x * TILE, y * TILE);
            else if(d->map.map[y][x] == 'C')
                mlx_put_image_to_window(d->mlx, d->win, d->img.collect, x * TILE, y * TILE);
            else if(d->map.map[y][x] == 'P')
            {
                mlx_put_image_to_window(d->mlx, d->win, d->img.player, x * TILE , y * TILE);
                d->pl_x = x;
                d->pl_y = y;
            }
            x++;
        }
        y++;
    }
    return (0);
}

int main(void)
{
    t_data  *d;

    d = malloc (sizeof(t_data));
    load_map(d);
    init_mlx(d);
    d->img.wall = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/wall.xpm", &d->img.w, &d->img.h);
    d->img.floor = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/floor.xpm", &d->img.w, &d->img.h);
    d->img.player = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/player.xpm", &d->img.w, &d->img.h);
    d->img.collect = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/collectible1.xpm", &d->img.w, &d->img.h);
    d->img.exit = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/exit.xpm", &d->img.w, &d->img.h);
    display_map(d);
    mlx_loop(d->mlx);
    //mlx_destroy_image(d->mlx, d->img.wall);
    free (d->map.map);
    mlx_destroy_window(d->mlx, d->win);
    mlx_destroy_display(d->mlx);
    free(d->mlx);
    free(d);
    return (0);
}

