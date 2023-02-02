/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:05:56 by jmouaike          #+#    #+#             */
/*   Updated: 2023/02/02 09:06:00 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* read with get_next_line into a linked-list
each node content us a char *str ending with a \n */
void	ft_lst_readlines(t_data *d, int fd)
{
	char	*line;
	t_list	*new;

	d->nb_lines = -1;
	while (d->nb_lines == -1 || line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			new = ft_lstnew((void *)line);
			ft_lstadd_back(&d->lst, new);
		}
		d->nb_lines += 1;
	}
	printf("%d\n", d->nb_lines);
}

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
int		load_and_verify_map(t_data *d, int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (put_error("too many arguments, not exactly one file turned in"));
	if (!(valid_filename(argv[1], ".ber")))
		return (put_error("input file need to have a .ber extension"));
    fd = open(argv[1], O_RDONLY);
	if (fd < 0)
        return (put_error("input file could not be opened"));
    ft_lst_readlines(d, fd);
    return (1);
}
