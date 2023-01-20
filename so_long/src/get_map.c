/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 07:26:56 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/20 07:28:02 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int     pioneer_read(int fd)
{
    char    buff[1];
    int     rb;
    int     line_len;

    line_len = 0;
    rb = 1;
    while (buff[0] == 1 )
    {
        rb = read (fd, buff, 1);
        if (rb != 1 )
            return(0)
        line_len += rb;
    }
    if (buff[0] == '/n')
    {
        if ( line_len > 3 && line_len < )
        while ()
        {

        }   
    }
    return (1);
}

int    read_map(t_data data, char *file)
{
    int     fd;
    int 

    // check .ber with ft_strnstr
    fd = open(file, O_RDONLY);
    if (fd > 0)
    {
        pioneer_read(fd);
        return (1);
    }
    error_message ("cannot open file");
    return (0);
}