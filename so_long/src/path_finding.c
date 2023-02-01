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

/* counts E, P and C */
int     check_map_count(char **map)
{
    int     y;
    int     nb_player;
    int     nb_nb_collect;
    int     nb_exit;

    y = 1;
    nb = 0;
    while (map[y])
    {
        nb_player += ft_strnchr(map[y], 'P');
        nb_collect += ft_strnchr(map[y], 'C');
        nb_exit += ft_strnchr(map[y], 'E');
        y++;
    }
    if (nb_player != 0 || nb_collect != 0 || nb_exit != 0 )
        return (0);
    return (1);
}

int    floodfill(char **mirror, int y, int x)
{
    // if (mirror[y][x] == 'E')
    //    return (1);
    if (mirror[y][x] == '0' || mirror[y][x] == 'C' 
    || mirror[y][x] == 'P' || mirror[y][x] == 'E')
    {
        // if (mirror [y][x] != 'F')
        mirror[y][x] = '+';
        floodfill(mirror, y, x + 1);
        floodfill(mirror, y + 1, x);
        floodfill(mirror, y, x - 1);
        floodfill(mirror, y - 1, x );
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
        put_error("pathfinding : memory allocation failed");
        return (NULL);
    }
    while(map->map[y])
    {
        mirror[y] = (char *)malloc(sizeof(*mirror));
        if (!mirror[y])
            return (free_map(mirror, y, 0));
        x = 0;
        while (x < map->line_len)
        {
            mirror[y][x] = map->map[y][x];
            x++;
        }
        y++;
    }
    mirror[map->nb_lines] = NULL;
    return (mirror);
}

int     pathfinder(t_data *d)
{
    char    **mirror;
    int     res;

    res = 1;
    mirror = dup_map(d->map);
    write(1, "\n", 1);
    floodfill(mirror, d->player->y, d->player->x);
    print_map(mirror);
    if (!check_map_count(char **mirror))
        res = put_error("pathfinding : at least one collectible or exit is not reachable");
    // free (mirror)
    free_map(mirror, d->map->nb_lines - 1, 1);
    return (res);
}
