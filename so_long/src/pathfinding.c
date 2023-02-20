/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:42:47 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/30 14:16:43 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* returns the count related to the occurence of a charset in a 2D-map */
int     check_map_count(char **map, char *charset)
{
    int     y;
    int     i;
    int     count;

    y = 1;
    count = 0;
    while (map[y])
    {
        i = 0;
        while (charset[i])
        {
            count += ft_strcountchr(map[y], charset[i]);
            i++;
        }
        y++;
    }
    return (count);
}

int     floodfill(char **mirror, int y, int x)
{
    if (mirror[y][x] == '0' || mirror[y][x] == 'C' 
    || mirror[y][x] == 'P' || mirror[y][x] == 'E')
    {
        mirror[y][x] = '+';
        floodfill(mirror, y, x + 1);
        floodfill(mirror, y + 1, x);
        floodfill(mirror, y, x - 1);
        floodfill(mirror, y - 1, x );
    }
    return (0);
}

/* 
initiates pathfinding on d->map 
if pathfinding result is fine, copies linked-list data into an char ** array 
*/
int     pathfinder(t_data *d)
{
    floodfill(d->map, d->player_y, d->player_x);
    if (PRINT_PATHFINDER)
        print_map(d->map);
    if (check_map_count(d->map, "PCE") > 0)
        outbound(d, "all collectibles and exit might not be reachable", 2);
    d->map = ft_lst_split(d);
    return (0);
}
