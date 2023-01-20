/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:49:09 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/20 10:48:52 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define WALL '1'
#define FLOOR '0'
#define WIN_W 1280
#define WIN_H 1024
#define TILE_Y 32
#define TILE_X 32

void	free_map(char **map, int k)
{
	while (k >= 0)
	{
		free(map[k]);
		k--;
	}
	free(map);
	map = NULL;
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
char	**ft_parse_file(int fd, int nb_lines, int line_len)
{
	char	**map;
	int		rb;
	int		i;

	i = 0;
	map = (char **)malloc (sizeof(*map) * (nb_lines + 1));
	if (!map)
		return (NULL);
	while (i < nb_lines)
	{
		map[i] = (char *)malloc (sizeof(*map) * (line_len + 1));
		if (!map[i])
			free_map(map, i);
		rb = read(fd, map[i], line_len + 1 );
		if (rb < line_len)
			free_map(map, i);
		map[i][line_len] = '\0';  // removes the '\n'
		printf ("map[%d]=%s\n", i, map[i]);
		i++;
	}
	map[nb_lines] = NULL;
	return (map);
}

/* count lines in a file :
will ignore a shorter last line 
will ignore additonal chars of a trailing last line*/
int		count_lines(int fd, int len)
{
	char	buff[len + 1];
	int		nb_lines;
	int		rb;
	int		reading;

	nb_lines = 1;
	reading = 1;
	while (reading)
	{
		rb = read (fd, buff, len + 1);
		if (rb >= len) 
		{
			nb_lines += 1;
			if (buff[len] != '\n')
				reading = 0;
		}
		else
			reading = 0;
	}
	if (nb_lines < 4 || nb_lines > (WIN_H / TILE_Y))
		return (0);
	return (nb_lines);
}

/* line length determination : pionner reading byte-by-byte  */
int		pioneer_read(int fd)
{
	char	buff[1];
	int		rb;
	int		line_len;

	line_len = 0;
	rb = 1;
	while (rb > 0)
	{
		rb = read (fd, buff, 1);
		if (rb != 1 || !*buff)
			return (0);
		if (buff[0] == '\n')
			break ;
		line_len += 1;
	}
	if (buff[0] == '\n')
	{
		if (line_len < 4 || line_len > (WIN_W / TILE_X))
			return (0);
	}
	return (line_len);
}

int	read_map(char *file)
{
	int		fd;
	int		line_len;
	int		nb_lines;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		line_len = pioneer_read(fd);
		if (line_len)
		{
			printf ("line length = %d\n", line_len);
			nb_lines = count_lines(fd, line_len);
			printf ("number of lines = %d\n", nb_lines);
			close (fd);
			fd = open(file, O_RDONLY);
			map = ft_parse_file(fd, nb_lines, line_len);
			print_map (map);
			free_map(map, nb_lines);
			return (0);
		}
	}
	printf ("cannot open file\n");
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf ("no file\n");
		return (1);
	}
	read_map(argv[1]);
	return (0);
}
