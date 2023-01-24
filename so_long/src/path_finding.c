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

// floofill()


char    **dup_map(t_map *map)
{
    char    **mirror;
    int     y;
    int     x;

    y = 0;
    mirror = (char **)malloc(sizeof(*mirror) * (map->nb_lines + 1));
    if (!mirror)
        return (put_error("memory allocation failed"));
    while(map->tiles[y])
    {
        mirror[y] = (char *)malloc(sizeof(*mirror))
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
