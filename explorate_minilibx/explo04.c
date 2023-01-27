#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"

#define WIN_W 1024
#define WIN_H 514
#define WIN_TITLE "so_long / explore mlx 03"
#define ERR_MLX 1
#define XPM_WALL "../so_long/rss/wall.xpm"
#define XPM_FLOOR "../so_long/rss/floor.xpm"
#define TILE 80
#define KEY_W 119

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
    d->map.map[4] = "1010100001C0010001";
    d->map.map[5] = "101010000100010001";
    d->map.map[6] = "10101000010P010001";
    d->map.map[7] = "101010011111111001";
    d->map.map[8] = "1010C000E100000001";
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

int    player_moves(t_data *d, int i, int j)
{
    int     y;
    int     x;

    y = d->pl_y + i;
    x = d->pl_x + j;
    printf("%d, %d => %d, %d \n ", d->pl_y, d->pl_x, y, x);
    if (d->map.map[y][x]  == '1')
        return (0);
    else if (d->map.map[y][x] != '1')
    {
        mlx_put_image_to_window(d->mlx, d->win, d->img.floor, d->pl_x * TILE, d->pl_y * TILE);
        //d->map.map[d->pl_y][d->pl_x] = '0';
        mlx_put_image_to_window(d->mlx, d->win, d->img.player, x * TILE, y * TILE);
        //d->map.map[y][x] = 'P';
        d->pl_y += i;
        d->pl_x += j;
        //|| d->map.map[y][x] == 'C'
        return (1);
    }
    return (1);
}

int     game_controls(int KeySym, t_data *d)
{
    if (KeySym == 'w')
        player_moves(d, -1, 0);
    else if (KeySym == 's')
        player_moves(d, 1, 0);
    else if (KeySym == 'a')
        player_moves(d, 0, -1);
    else if (KeySym == 'd')
        player_moves(d, 0, 1);
    else if (KeySym == 'q' || KeySym == 65307)
        printf ("exit game \n");
    // player_move(d, 1, 0);
    return (0);
}

void     free_game(t_data *d)
{
    printf ("exit game \n");
    free (d->map.map);
    mlx_destroy_window(d->mlx, d->win);
    mlx_destroy_display(d->mlx);
    free(d->mlx);
    free(d);
}

int     main(void)
{
    t_data  *d;

    d = malloc (sizeof(t_data));
    load_map(d);
    init_mlx(d);
    // issue : put in a function and protect
    d->img.wall = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/wall.xpm", &d->img.w, &d->img.h);
    d->img.floor = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/floor.xpm", &d->img.w, &d->img.h);
    d->img.player = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/player.xpm", &d->img.w, &d->img.h);
    d->img.collect = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/collectible1.xpm", &d->img.w, &d->img.h);
    d->img.exit = mlx_xpm_file_to_image(d->mlx, "../so_long/rss/exit_open2.xpm", &d->img.w, &d->img.h);
    display_map(d);
    mlx_hook(d->win, 2, 1L<<0, game_controls, d);
    mlx_loop(d->mlx);
    //mlx_destroy_image(d->mlx, d->img.wall);
    free_game(d);
    return (0);
}
