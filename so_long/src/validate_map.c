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

int     wallproofing(char **map, int nb_lines)
{
    int     y;
    int     nb_lines;

    y = 1;
    if ((ft_strnchr(map[0], WALL) == line_len)
        && (ft_strnchr(data->map->tiles[nb_lines - 1], '1') == line_len)
    {
        while (y < nb_lines - 1)
        {
            if (data->map)
        }
    }
    return (0);
}

int     validate_map(t_data data)
{
    int     res;

    res = 1;
    res *= wallproofing(data->map->tiles, data->map->nb_lines);
    return(res);
}
