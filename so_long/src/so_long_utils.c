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

/* writes error message on std_err, returns a (0)*/
int		put_error(char *str)
{
	ft_putendl_fd("Error", 2);
	write(2, "# ", 2);
	ft_putendl_fd(str, 2);
	return (0);
}

/* writes error message on std_err, returns a (0)*/
int		put_labeled_int(char *label, int nb_moves, char *end)
{
	char	*str_moves;

	ft_putstr_fd(label, 1);
	str_moves = ft_itoa(nb_moves);
	ft_putstr_fd(str_moves, 1);
	ft_putendl_fd(end, 1);
	free (str_moves);
	return (0);
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
