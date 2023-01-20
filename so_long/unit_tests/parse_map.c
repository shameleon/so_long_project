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

/* count lines in a file : */
int		count_lines(int fd, int len)
{
	char	buff[len + 1];
	int		nb_lines;
	int		rb;

	nb_lines = 1;
	rb = 1;
	while (rb)
	{
		rb = read (fd, buff, len + 1);
		if (rb >= len && (buff[len] == '\n' || buff[len] == '\0'))
				nb_lines += 1;
		else
			return (0);
	}
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

	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		line_len = pioneer_read(fd);
		if (line_len)
		{
			printf ("line length : %d\n\n", line_len);
			nb_lines = count_lines(fd, line_len);
			printf ("number of lines = %d\n", nb_lines);
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
