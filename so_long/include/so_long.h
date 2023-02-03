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

//# include "mlx.h"
//# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"

// X 11 x 2 and mlx

//# define RSS_PATH "./maps/"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_list	*lst;
	int		nb_lines;
	int		line_len;
}				t_data;

/* so_long_utils.c  */
int     put_error(char *str);
void	print_map(char **map);
void    print_list(t_list *lst, char *name);

/* outbound.c  */
int     destruct_data(t_data *d);
int     outbound(t_data *d, char *mssg, int err_code);

/* check_map.c */

/* load_map.c  */
char	*process_line(char *line, int *len);
int		ft_lst_fixline(t_data *d);
int		ft_lst_readlines(t_data *d, int fd);
int		valid_filename(const char *file, char *pattern);
int		load_and_verify_map(t_data *d, int argc, char **argv);

/*   so_long.c  */
int		init_data(t_data *d);
int     main(int argc, char **argv);

#endif
