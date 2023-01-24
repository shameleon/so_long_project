/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:49:09 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/23 13:33:12 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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

/* reads from file and counts line length and number of lines*/
int		read_file_content(char *file, t_data *data)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd > 0)
	{	
		data->map->line_len = pioneer_read(fd);
		data->map->nb_lines = count_lines(fd, data->map->line_len);
		printf("line_len=%d, nb_lines=%d\n", data->map->line_len, data->map->nb_lines);
		if (!data->map->line_len || !data->map->nb_lines)
		{
			printf("Error\n# file content is not valid\n");
			return (0);
		}
		close (fd);
		fd = open(file, O_RDONLY);
		printf ("file is open\n");
		if (fd > 0)
			return (fd);
	}
	printf ("Error\n#cannot open file\n");
	return (0);
}

/* checks for a .ber file extension
will allow multiple dots in file name
to exclude multiple dots : if (!ext || ft_strnchr(file, '.') > 1)
*/
int		valid_filename(const char *file, char *pattern)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if(!ext)
		return (0);
	if(ft_strncmp(ext, pattern, 5))
		return (0);
	return (1);
}

/* main */
int		main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if (argc != 2)
	{
		printf ("Error\n# not exactly one file turned in\n");
		return (1);
	}
	if (!valid_filename(argv[1], ".ber"))
	{
		printf ("Error\n# input file is not a .ber file\n");
		return (1);
	}
	data = (t_data *)malloc (sizeof(t_data *));
	data->map = (t_map *)malloc (sizeof(t_map *));
	fd = read_file_content(argv[1], data);
	if (fd > 0)
	{
		parse_file(fd, data);
		print_map(data->map->tiles);
		if (VALIDATE)
			validate_map(data);
	}
	free_map(data->map->tiles, data->map->nb_lines - 1);
	free (data->map);
	//data->map = NULL;
	free (data);
	//data = NULL;
	return (0);
}
