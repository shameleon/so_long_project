/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:50:05 by jmouaike          #+#    #+#             */
/*   Updated: 2023/02/02 08:50:13 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* writes error message on std out, returns a (0)*/
int     put_error(char *str)
{
    ft_putendl_fd("Error", 1);
    write(1, "# ", 2);
    ft_putendl_fd(str, 1);
    return (0);
}

void    print_list(t_list *lst, char *name)
{
        printf ("%s :\n", name);
        if (!lst)
                printf("linked list is empty\n");
        while (lst != NULL)
        {
                printf ("%s|-->", (char *)(lst->content));
                lst = lst->next;
        }
        printf ("%p\n", lst);     // last element pointing to ...
        printf ("\n");
}

void	print_map(char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			write (1, &map[y][x], 1);
			x++;
		}
		write (1, "\n", 1);
		y++;
	}
}


