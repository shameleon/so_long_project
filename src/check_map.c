/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:39:18 by jmouaike          #+#    #+#             */
/*   Updated: 2023/06/30 10:08:26 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* auxiliar function to ft_lst_split */
char	*fill_word(char *s, unsigned int wlen)
{
	char	*word;

	word = (char *)malloc (sizeof(*word) * (wlen + 1));
	if (word == NULL)
		return (NULL);
	ft_memcpy(word, s, wlen);
	word[wlen] = '\0';
	return (word);
}

/* copies linked-list contents into a char ** array*/
char	**ft_lst_split(t_data *d)
{
	t_list	*node;
	char	**map;
	int		y;

	node = d->lst;
	map = (char **)malloc(sizeof(*map) * (d->nb_lines + 1));
	if (!map)
		outbound(d, "map memory allocation failed", 3);
	y = 0;
	while (y < d->nb_lines)
	{
		map[y] = fill_word(node->content, (unsigned int)d->line_len);
		if (!map[y])
			outbound(d, "map memory allocation failed", 3);
		y++;
		node = node->next;
	}
	map[d->nb_lines] = NULL;
	return (map);
}

/*
checks if map line content is compatible with MAP_SET "01PCE"
verifies Wallproofing
retrieves player and exit coordinates to t_data *d         */
void	charset_and_wallproofing(t_data *d, char *line, int y)
{
	int		x;

	x = 0;
	if (line[x] != '1' || line[d->line_len - 1] != '1')
		outbound(d, "map must be surrounded by walls", 3);
	while (line[x])
	{
		if (!ft_strchr("01PCE", line[x]))
			outbound(d, "map content not valid : only 01CPE chars please", 3);
		if ((y == 0 || y == d->nb_lines - 1) && line[x] != '1')
			outbound(d, "map must be surrounded by walls", 3);
		if (line[x] == 'P')
		{
			d->player_y = y;
			d->player_x = x;
		}
		if (line[x] == 'E')
		{
			d->exit_y = y;
			d->exit_x = x;
		}
		x++;
	}
}

/* checks map lines content and counts P, C, E to data struct */
void	check_content(t_data *d)
{
	t_list	*node;
	int		y;

	node = d->lst;
	y = 0;
	while (node)
	{
		charset_and_wallproofing(d, node->content, y);
		d->nb_player += ft_strcountchr(node->content, 'P');
		d->nb_collect += ft_strcountchr(node->content, 'C');
		d->nb_exit += ft_strcountchr(node->content, 'E');
		node = node->next;
		y++;
	}
	if (d->nb_player != 1)
		outbound(d, "map not valid : provide exactly 1 player P please", 3);
	if (d->nb_exit != 1)
		outbound(d, "map not valid, provide exactly 1 exit E please", 3);
	if (d->nb_collect < 1)
		outbound(d, "map not valid, no collectibles found", 3);
	d->map = ft_lst_split(d);
	if (!d->map)
		outbound(d, "map memory allocation failed", 3);
}
