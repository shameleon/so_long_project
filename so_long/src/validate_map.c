/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:14:30 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/20 16:14:53 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int     wallproofing(t_map *map)
{
    int     y;

    y = 1;
    if ((ft_strnchr(map->tiles[0], WALL) == map->line_len)
        && (ft_strnchr(map->tiles[map->nb_lines - 1], '1') == map->line_len))
    {
        while (y < map->nb_lines - 1)
        {
            if (map->tiles[y][0] != WALL 
                || map->tiles[y][map->line_len - 1] != WALL)
                return(0);
            y++;
        }
    }
    else
        return (0);
    return (1);
}

int     validate_map(t_data *data)
{
    int     res;

    res = 1;
    res *= wallproofing(data->map);
    if (!res)
        printf ("Error\nmap is not surrounded by walls\n");
    return(res);
}
