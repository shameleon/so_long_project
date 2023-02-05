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
reads from file -> load map into a linked-list -> trim trailing /n 
-> checks for rectangular shape.
*/
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
- checks if line length is the same which means rectangular shape
 */
int		ft_lst_fixline(t_data *d)
{
	int		len;
	t_list	*node;

	len = 0;
	node = d->lst;
	while (node)
	{
		node->content = (void *)trim_eol((char*)(node->content), &len);
		if (!(node->content))
			outbound(d, "FIX : list memory allocation failed", 2);
		if (len <= MIN_MAP_SIZE)
			outbound(d, "FIX : input map width is too small", 2);
		if (node == d->lst)
			d->line_len = len;
		else if (len != d->line_len)
			outbound(d, "FIX : map must be rectangular", 2);
		node = node->next;
	}
	return (1);
}

/* reads with get_next_line() into a linked-list
each node contains string ending with a \n */
int		ft_lst_readlines(t_data *d, int fd)
{
	char	*line;
	t_list	*new;

	while (d->nb_lines == 0 || ft_strchr(line, '\n'))
	{
		line = get_next_line(fd);
		if (!line)
			outbound(d, "GNL : file unreadable has empty content", 2);
		else if ( ft_strlen(line) <= MIN_MAP_SIZE)
			outbound(d, "GNL : file containing line width too small", 2);
		else
		{
			new = ft_lstnew((void *)line);
			if (!new)
				outbound(d, "linked list : memory allocation failed", 2);
			ft_lstadd_back(&d->lst, new);
		}
		d->nb_lines += 1;
	}
	if (d->nb_lines < MIN_MAP_SIZE)
		outbound(d, "GNL : map height is too small", 2);
	return (1);
}

/* verifies if filename has a .ber extension returns 1.
returns 0 otherwise*/
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

/* starting point to load map from .ber file */
int		load_and_verify_map(t_data *d, int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		outbound(d, "too many arguments, not exactly one file turned in", 1);
	if (!(valid_filename(argv[1], ".ber")))
		outbound(d, "input file must have a .ber extension", 1);
    fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		outbound(d, "LVM : input file could not be opened", 1);
    if (!ft_lst_readlines(d, fd))
		outbound(d, "LVM : file not readable, empty or memory allocated", 2);
	if (!ft_lst_fixline(d))
		outbound(d, "LVM : memory could not be allocated", 2);
    return (1);
}
