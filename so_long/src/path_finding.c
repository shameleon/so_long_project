/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:42:47 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/24 10:44:09 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int    floodfill(char **mirror, int y, int x)
{
    write(1, "\n", 1);
    print_map(mirror);
    if (mirror[y][x] == 'E')
        return (1);
    if (mirror[y][x] == '0' || mirror[y][x] == 'C' || mirror[y][x] == 'P')
    {
        // if (mirror [y][x] != 'F')
        mirror[y][x] = 'F';
        floodfill(mirror, y, x + 1);
        floodfill(mirror, y + 1, x);
        floodfill(mirror, y, x - 1);
        floodfill(mirror, y + 1, x );
    }
    return (0);
}

char    **dup_map(t_map *map)
{
    char    **mirror;
    int     y;
    int     x;

    y = 0;
    mirror = (char **)malloc(sizeof(*mirror) * (map->nb_lines + 1));
    if (!mirror)
    {
        put_error("memory allocation failed");
        return (NULL);
    }
    while(map->tiles[y])
    {
        mirror[y] = (char *)malloc(sizeof(*mirror));
        if (!mirror[y])
            return (free_map(mirror, y, 0));
        x = 0;
        while (x < map->line_len)
        {
            mirror[y][x] = map->tiles[y][x];
            x++;
        }
        y++;
    }
    mirror[map->nb_lines] = NULL;
    return (mirror);
}

int     pathfinder(t_map *map)
{
    char    **mirror;

    mirror = dup_map(map);
    // player y, x
    return (floodfill(mirror, 1, 5));
}