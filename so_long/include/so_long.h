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

# define VALIDATE_MAP 1

# define WINMAX_W 1800
# define WINMAX_H 1200

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

//# include "mlx.h"
//# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
// X 11 x 2 and mlx

//# define RSS_PATH "./maps/"
typedef struct s_vect
{
    int     x;
    int     y;
    int     items_collected;
}               t_vect;

typedef struct	s_map
{
	char	**map;
	int     line_len;
    int     nb_lines;
    int     nb_collect;
    int     nb_player;
    int     nb_exit;
}				t_map;

typedef struct	s_img
{
	void	*wall;
    void    *floor;
    void    *player;
    void    *collect;
    void    *exit;
    int     w;
    int     h;
}				t_img;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_map   *map;
    t_img   *img;
    t_vect  player;
}				t_data;

/* libft_utils*/
size_t  ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strchr(const char *s, int c);
int     ft_strnchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
void    ft_putendl(char *s);

/* path_finding.c*/
int     floodfill(char **mirror, int y, int x);
char    **dup_map(t_map *map);
int     pathfinder(t_map *map);

/* validate_map.c*/
int     map_content(t_map *map);
int     wallproofing(t_map *map);
int     put_error(char *str);
int     validate_map(t_data *data);

/* parse_map.c*/
char	**free_map(char **map, int line, int all);
void	print_map(char **map);
char	**ft_split_file(int fd, int nb_lines, int line_len);
int     parse_file(int fd, t_data *data);

/*   read_file.c   */
int		count_lines(int fd, int len);
int		pioneer_read(int fd);
int     read_file_content(char *file, t_data *data);
int		valid_filename(const char *file, char *extension);
int		load_and_verify_map(t_data *d, int argc, char **argv);

/*   so_long.c     */
int	main(int argc, char **argv);

#endif
