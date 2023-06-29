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

/* 
generates a substring if a GNL-produced line ends with a '\n'.
line length '*len' is also determined, without the final '\n'
and checked idf not too small
*/
char	*trim_eol(char *line, int *len)
{
	char	*pure_line;

	*len = 0;
	if (!line)
		return (NULL);
	while (line[*len] && line[*len] != '\n')
		*len += 1;
	if (line[*len] == '\n')
	{
		pure_line = ft_substr(line, 0, *len);
		free (line);
		if (!pure_line)
			return (NULL);
		return (pure_line);
	}
	return (line);
}

/* iterates through linked-list, check content 
- verify if line contains a trailing \n and removes it 
- checks line length and rectangular shape
 */
int	ft_lst_fixline(t_data *d)
{
	int		len;
	t_list	*node;

	len = 0;
	node = d->lst;
	while (node)
	{
		node->content = (void *)trim_eol((char *)(node->content), &len);
		if (!(node->content))
			outbound(d, "list memory allocation failed", 3);
		if (len < d->gameset.min_map_size || len > d->gameset.max_w)
			outbound(d, "input map size is out of bounds", 3);
		else if (len > d->gameset.max_w)
			outbound(d, "input map width is too small", 3);
		if (node == d->lst)
			d->line_len = len;
		else if (len != d->line_len)
			outbound(d, "map must be rectangular", 3);
		node = node->next;
	}
	return (1);
}

/* reads with get_next_line() and pushes lines into a linked-list
each node contains a string ending with an eventual trailing \n   */
int	ft_lst_readlines(t_data *d, int fd)
{
	t_list	*new;

	while (d->nb_lines == 0 || ft_strchr(d->line, '\n'))
	{
		d->line = get_next_line(fd);
		if (!(d->line))
			outbound(d, "file unreadable or has empty content", 1);
		else if ((int)ft_strlen(d->line) < d->gameset.min_map_size
			|| (int)ft_strlen(d->line) > d->gameset.max_w)
			outbound(d, "input map width is out of bounds", 2);
		else
		{
			new = ft_lstnew((void *)(d->line));
			if (!new)
				outbound(d, "linked list : memory allocation failed", 3);
			ft_lstadd_back(&d->lst, new);
		}
		d->nb_lines += 1;
	}
	if (d->nb_lines < d->gameset.min_map_size
		|| d->nb_lines > d->gameset.max_h)
		outbound(d, "input map height is out of bounds", 2);
	return (1);
}

/* verifies that filename has a .ber extension */
int	valid_filename(const char *file, char *pattern)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext)
		return (0);
	if (ft_strncmp(ext, pattern, 5))
		return (0);
	return (1);
}

/* loads map from .ber file */
int	load_and_verify_map(t_data *d, int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		outbound(d, "too many arguments, not exactly one file turned in", 1);
	if (!(valid_filename(argv[1], ".ber")))
		outbound(d, "input file must have a .ber extension", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		outbound(d, "input file could not be opened", 1);
	if (!ft_lst_readlines(d, fd))
		outbound(d, "file not readable, empty or memory allocated", 1);
	if (!ft_lst_fixline(d))
		outbound(d, "memory could not be allocated", 2);
	return (1);
}
