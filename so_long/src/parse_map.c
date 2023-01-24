/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:33:42 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/23 13:33:48 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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
		put_error("memory allocation failed");
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
		printf ("map[%d]=%s\n", i, map[i]);
		i++;
	}
	map[nb_lines] = NULL;
	return (map);
}

int     parse_file(int fd, t_data (*data))
{
	int		len;
	int		lines;

    len = data->map->line_len;
    lines = data->map->nb_lines;
	printf ("%d x %d\n", len, lines);
	data->map->tiles = ft_split_file(fd, lines, len);
	if (!data->map->tiles)
	{
		printf ("Error\n# map could not be loaded\n");
		return (0);
	}
	return (1);
}
