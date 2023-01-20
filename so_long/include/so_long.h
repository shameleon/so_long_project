/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:49:21 by jmouaike          #+#    #+#             */
/*   Updated: 2023/01/10 07:53:39 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "mlx.h"
//# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

//# define RSS_PATH "./maps/"

typedef struct	s_map
{
	char	**map;
}				t_map;

typedef struct	s_img
{
	
}				t_img;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		win_h;
	int		win_w;
	t_map	*map;
}				t_data;


int main(int argc, char **argv);

#endif
