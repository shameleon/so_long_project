/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outbound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:42:35 by jmouaike          #+#    #+#             */
/*   Updated: 2023/02/03 13:48:17 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* 
- cleans game before quiting
*/
int     destruct_data(t_data *d)
{
    if (d->lst)
        ft_lstclear(&(d->lst), free);
    return (1);
}

/* 
- print errors
*/


/* handles game exit : cleans free and destroy 
- returns 1 if error
- returns 0 if exit is end of game
err_code = 0 : destruct data and exit (0)
err_code = 1 : no destruct and exit (1)
err_code = 2 : destruct and exit (1)
*/
int     outbound(t_data *d, char *mssg, int err_code)
{
    if (err_code == 0)
    {
        destruct_data(d);
        exit (0);
    }
    else if (err_code >= 2)
        destruct_data(d);
    put_error(mssg);
    exit (1);
}