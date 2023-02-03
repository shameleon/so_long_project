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

/* checks that content is only 0, 1, E, P and C */
int     map_content(t_map *map)
{
    int     y;
    int     x;
    int     res;

    y = 1;
    res = 1;
    while (map->tiles[y])
    {
        x = 0;
        while (map->tiles[y][x] != '\0')
        {
            if (!ft_strchr("01PCE", map->tiles[y][x]))
                res *= 0; 
            x++;
        }
        y++;
    }
    return (res);
}

/* checks for rectangle shape and walls all around*/
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

/* writes error message on std out*/
int     put_error(char *str)
{
    ft_putendl("Error");
    write(1, "# ", 2);
    ft_putendl(str);
    return (0);
}

int     validate_map(t_data *data)
{
    int     res;

    res = 1;
    res *= wallproofing(data->map);
    if (!res)
        return (put_error ("map is not surrounded by walls"));
    res *= map_content(data->map);
    if (!res)
        return (put_error ("map content is not valid"));
    res *= pathfinder(data->map);
    if (!res)
        return (put_error ("map walls prevent player for reaching exit"));
    return (res);
}