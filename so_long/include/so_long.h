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
# include <X11/X.h>
# include <X11/keysym.h>
# include "./minilibx/mlx.h"

//# define RSS_PATH "./maps/"

typedef struct	s_map
{
	char	**map;
	int     line_len;
    int     nb_lines;
}				t_map;

typedef struct	s_img
{
	void	*wall;
    void    *floor;
    void    *player;
    void    *collect;
    void    *exit;
    int     w;
    int     h;
}				t_img;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_map   *map;
    t_img   *img;
    int     pl_x;
    int     pl_y;
}				t_data;


int	main(int argc, char **argv);

#endif
