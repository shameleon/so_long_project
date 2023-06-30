/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:49:21 by jmouaike          #+#    #+#             */
/*   Updated: 2023/06/30 10:11:57 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_set
{
	char	*win_title;
	char	*xpm_wall;
	char	*xpm_floor;
	char	*xpm_player;
	char	*xpm_collect;
	char	*xpm_exit0;
	char	*xpm_exit1;
	char	*xpm_player_on_exit;
	int		print_pathfinding;
	int		min_map_size;
	int		max_w;
	int		max_h;
}				t_set;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit1;
	void	*exit0;
	void	*player_on_exit;
	int		w;
	int		h;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*line;
	t_list	*lst;
	int		nb_lines;
	int		line_len;
	char	**map;
	int		nb_player;
	int		nb_exit;
	int		nb_collect;
	int		player_x;
	int		player_y;
	int		player_moves;
	int		open_exit;
	int		exit_x;
	int		exit_y;
	int		tile;
	t_img	img;
	t_set	gameset;
}				t_data;

/* so_long_utils.c  */
void	*xpm_file_to_image(t_data *d, char *xpm_file);
int		put_img_to_window(t_data *d, void *img, int x, int y);
int		put_error(char *str);
int		put_labeled_int(char *label, int nb_moves, char *end);
void	print_map(char **map);

/* outbound.c  */
void	end_game(t_data *d);
int		destruct_data(t_data *d);
int		outbound(t_data *d, char *mssg, int err_code);

/* pathfinding.c */
void	copy_lst_to_split(t_data *d);
int		check_map_count(char **map, char *charset);
int		floodfill(char **mirror, int y, int x);
int		pathfinder(t_data *d);

/* check_map.c */
char	**ft_lst_split(t_data *d);
void	charset_and_wallproofing(t_data *d, char *line, int y);
void	check_content(t_data *d);

/* load_map.c */
char	*trim_eol(char *line, int *len);
int		ft_lst_fixline(t_data *d);
int		ft_lst_readlines(t_data *d, int fd);
int		valid_filename(const char *file, char *pattern);
int		load_and_verify_map(t_data *d, int argc, char **argv);

/* update_display.c */
void	collect_item(t_data *d, int y, int x);
void	player_moves(t_data *d, int i, int j);
int		at_mouse_exit(t_data *d);
int		game_controls(int KeySym, t_data *d);
int		display_map(t_data *d);

/* so_long.c  */
int		init_mlx(t_data *d);
void	load_sprites(t_data *d);
int		set_game(t_data *d);
int		init_data(t_data *d);
int		main(int argc, char **argv);

#endif
