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

/* copies linked-list contents into a char ** array*/
/*char	**ft_lst_split(t_data *d)
{

}
void	ft_lst_check_line()
*/

/* generates a substring if a GNL-produced line ends with a '\n'.
line length '*len' is also determined, without the final '\n'
and checked idf not too small */
char	*process_line(char *line, int *len)
{
	char	*pure_line;

	*len = 0; 
	if (!line)
		return (NULL);
	while (line[*len] && line[*len] != '\n')
		*len += 1;
	if (*len <= MIN_MAP_SIZE)
		return (NULL);      //map is to small
	if (line[*len] == '\n')
	{
		pure_line = ft_substr(line, 0, *len);
		free (line);
		if (!pure_line)
			return (NULL); // pure line : memory allocation failed
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

	d->line_len = 0;
	len = 0;
	node = d->lst;
	while (node)
	{
		node->content = (void *)process_line((char*)(node->content), &len);
		if (!(node->content))
			return (put_error("linked list line : memory allocation failed"));
		if (node == d->lst)
			d->line_len = len;
		else if (len != d->line_len)
			return (put_error("map must be rectangular"));
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

	d->nb_lines = -1;
	while (d->nb_lines == -1 || line != NULL)
	{
		line = get_next_line(fd);
		if (line && ft_strlen(line) > MIN_MAP_SIZE)
		{
			new = ft_lstnew((void *)line);
			if (!new)
				return (put_error("linked list : memory allocation failed"));
			ft_lstadd_back(&d->lst, new);
		}
		d->nb_lines += 1;
	}
	if (d->nb_lines < MIN_MAP_SIZE)
		return (0);
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
		return (put_error("too many arguments, \
									not exactly one file turned in"));
	if (!(valid_filename(argv[1], ".ber")))
		return (put_error("input file need to have a .ber extension"));
    fd = open(argv[1], O_RDONLY);
	if (fd < 0)
        return (put_error("input file could not be opened"));
    if (!ft_lst_readlines(d, fd))
		return (put_error("file is either not readable or empty content or memory could not be allocated"));
	if (!ft_lst_fixline(d))
		return (put_error("file lines too short. memory could not be allocated"));
    return (1);
}
