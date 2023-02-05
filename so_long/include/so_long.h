/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:49:21 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/10 07:53:39 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define READ_FILE  1
# define VALIDATE_MAP 1

# define MIN_MAP_SIZE 4
# define MAP_SET "01PCE"
# define WINMAX_W 4000
# define WINMAX_H 2000

/* texture size */
# define TILE 80

/* error messages */
# define ERR_MLX 1

/* window title */
# define WIN_TITLE "so_long"

/* textures relative path */
# define XPM_WALL "../rss/wall.xpm"
# define XPM_FLOOR "../rss/floor.xpm"
# define XPM_PLAYER "../rss/player.xpm"
# define XPM_COLLECT "../rss/collectible1.xpm"
# define XPM_EXIT0 "../rss/exit.xpm"
# define XPM_EXIT1 "../rss/exit_open2.xpm"

/* keyboard keys Linux */
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define KEY_ESC 65307

/* Colors */
# define BLUE 0x000000FF

/* librairies */
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "../minilibx/mlx.h"

//# define RSS_PATH "./maps/"

typedef struct  s_img
{
	void	*wall;
    void    *floor;
    void    *player;
    void    *collect;
	void    *exit1;
    void    *exit0;
    int     w;
    int     h;
}               t_img;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_list	*lst;
	int		nb_lines;
	int		line_len;
	char	**map;
	int		nb_player;
	int		nb_exit;
	int		nb_collect;
	int		player_x;
	int		player_y;
	t_img   img;
}				t_data;

/* so_long_utils.c  */
int     put_error(char *str);
void	print_map(char **map);
void    print_list(t_list *lst, char *name);

/* outbound.c  */
int     destruct_data(t_data *d);
int     outbound(t_data *d, char *mssg, int err_code);

/* pathfinding.c */
int     check_map_count(char **map, char *charset);
int		floodfill(char **mirror, int y, int x);
int		pathfinder(t_data *d);

/* check_map.c */
char	**ft_lst_split(t_data *d);
void	charset_and_wallproofing(t_data *d, char *line, int   y);
void    check_content(t_data *d);

/* load_map.c  */
char	*trim_eol(char *line, int *len);
int		ft_lst_fixline(t_data *d);
int		ft_lst_readlines(t_data *d, int fd);
int		valid_filename(const char *file, char *pattern);
int		load_and_verify_map(t_data *d, int argc, char **argv);

/* rendering.c */

/*   so_long.c  */
void	load_sprites(t_data *d);
int		init_data(t_data *d);
int     main(int argc, char **argv);

#endif
