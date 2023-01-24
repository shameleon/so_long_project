/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:04:45 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/23 08:06:30 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define VALIDATE 1
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECT '0'
# define WIN_W 1280
# define WIN_H 1024
# define TILE_Y 32
# define TILE_X 32

typedef struct  s_map
{
    char    **tiles;
    int     line_len;
    int     nb_lines;
}               t_map;

typedef struct  s_data
{
    t_map   *map;
}               t_data;

/* libft_utils*/
size_t  ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strchr(const char *s, int c);
int     ft_strnchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
void    ft_putendl(char *s);

/* read_file.c */
int		count_lines(int fd, int len);
int		pioneer_read(int fd);
int     read_file_content(char *file, t_data *data);
int		valid_filename(const char *file, char *extension);
int     main(int argc, char **argv);

/* parse_map.c*/
void	free_map(char **map, int line);
void	print_map(char **map);
char	**ft_split_file(int fd, int nb_lines, int line_len);
int     parse_file(int fd, t_data *data);

/* validate_map.c*/
int     map_content(t_map *map);
int     wallproofing(t_map *map);
int     puterror(char *str);
int     validate_map(t_data *data);

#endif
