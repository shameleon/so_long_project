/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:39:18 by jmouaike          #+#    #+#             */
/*   Updated: 2023/02/03 14:39:42 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* 
checks map contents. at this stage map must be rectangular, minimum sized
*/

/* copies linked-list contents into a char ** array*/
char	**ft_lst_split(t_data *d)
{
    t_list  *node;
    char    **map;
    int     y;
    int     x;

    node = d->lst;
    map = (char **)malloc(sizeof(*map) * (d->nb_lines + 1));
    if (!map)
        outbound(d, "map memory allocation failed", 2);
    y = 0;
    while (y < d->nb_lines)
    {
        x = 0;
        while(x < line_len)
        {
            map[y][x] = node->content[i];
            x++;
        }
        map[y][d->line_len] = '\0';
        y++;
        node = node->next;
    }
    map[d->nb_lines] = NULL;
    return(map)
}

/*
checks if map line content is compatible with MAP_SET "01PCE"
verifies Wallproofing
retrieves player coordinates to t_data"
*/
void	charset_and_wallproofing(t_data *d, char *line, int   y)
{
    int     x;

    x = 0;
    if (line[x] != '1' || line[x->line_len - 1] != '1')
        outbound(d, "map must be surrounded by walls", 2);
    while(line[x])
    { 
        if (!ft_strchr(MAP_SET, line[x]))
            outbound(d, "map content not valid : only 01CPE chars please", 2);
        if ((y == 0 || y == d->nb_lines - 1 ) && line[x] != '1')
            outbound(d, "map must be surrounded by walls", 2);
        if (line[x] == 'P')
        {
            d->player_y = y;
            d->player_x = x;
        }
        x++;
    }
}

/* 
checks map lines content and count P, C, E to data struct"
*/
void    check_content(t_data *d)
{
    t_list	*node;
    int     y;

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
    if (d->nb_player != 1 )
        outbound(d, "map not valid : provide exactly 1 player P please", 2);
    if (d->nb_exit != 1)
        outbound(d, "map not valid, provide exactly 1 exit E please", 2);
    if (d->nb_collect < 1)
        outbound(d, "map not valid, no collectibles found", 2);
    d->map = ft_lst_split(d);
    if (!d->map)
        outbound(d, "map memory allocation failed", 2);
    print_map(d->map);
    //res *= pathfinder(d);
}
