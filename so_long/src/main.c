/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:46:43 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/10 07:49:07 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(char *s)
{
	printf ("Error : %s !\n", s);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		error_message ("please entre a valid file name");
		return (1);
	}
	if (!read_map(&data, argv[1]))
		error_message ("map is invalid");
	return (0);
}
