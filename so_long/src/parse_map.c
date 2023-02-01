/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:33:42 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/30 14:15:17 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* frees the map char **map */
char	**free_map(char **map, int line, int all)
{
	while (line >= 0)
	{
		free(map[line]);
		line--;
	}
	free(map);
	map = NULL;
	if (!all)
		put_error("memory allocation failed : map cannot be loaded");
	return (NULL);
}

void	print_map(char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			write (1, &map[y][x], 1);
			x++;
		}
		write (1, "\n", 1);
		y++;
	}
}

/*Parse file into a char ** array of strings */
char	**ft_split_file(int fd, int nb_lines, int line_len)
{
	char	**map;
	int		rb;
	int		i;

	i = 0;
	map = (char **)malloc (sizeof(* map) * (nb_lines + 1));
	if (!map)
		return (NULL);
	while (i < nb_lines)
	{
		map[i] = (char *)malloc (sizeof(*map) * (line_len + 1));
		if (!map[i])
			free_map(map, i, 0);
		rb = read(fd, map[i], line_len + 1 );
		if (rb < line_len)
			free_map(map, i, 0);
		map[i][line_len] = '\0';
		i++;
	}
	map[nb_lines] = NULL;
	return (map);
}

int     parse_file(int fd, t_data *d)
{
	int		len;
	int		lines;

    len = d->map->line_len;
    lines = d->map->nb_lines;
	d->map->map = ft_split_file(fd, lines, len);
	if (!d->map->map)
		return (put_error("map could not be loaded"));
	return (1);
}
