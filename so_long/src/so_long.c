/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:49:09 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/23 13:33:12 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* main */
int		main(int argc, char **argv)
{
	t_data	d;

	ft_memset(&d, 0, sizeof(t_data));
	load_and_verify_map(&d, argc, argv);
	print_list((d.lst), "map into a linked list");
	ft_lstclear(&(d.lst), free);
	return (0);
}

/* 
 gcc -Wall -Werror -Wextra ./src/so_long.c ./src/load_map.c 
 ./src/so_long_utils.c -I ./include/ -I ./libft/ -L ./libft/ -lft  -o so_long
*/