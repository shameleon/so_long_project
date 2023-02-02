/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:09:37 by jmouaike          #+#    #+#             */
/*   Updated: 2022/12/20 10:04:34 by jmouaike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	update_move(char *buff, char *eol)
{
	char	*src;
	char	*dst;

	src = buff + ft_strlen(buff);
	dst = buff;
	if (eol)
	{
		src = eol + 1;
		while (src && *src != '\0')
			*dst++ = *src++;
	}
	while (dst < src)
		*dst++ = '\0';
}

static char	*extract_to_eo(char *buff)
{
	char	*str;
	char	*eol;

	eol = ft_strchr(buff, '\n');
	if (eol)
		str = ft_substr(buff, 0, (unsigned int)((eol + 1) - buff));
	else
		str = ft_substr(buff, 0, ft_strlen(buff));
	update_move(buff, eol);
	return (str);
}

static int	read_until_eo(int fd, char *buff, char **line)
{
	char	*head;
	int		n;

	n = BUFFER_SIZE;
	while (ft_strchr(*line, '\n') == NULL && n == BUFFER_SIZE)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n <= 0)
			return (n);
		head = extract_to_eo(buff);
		*line = ft_strjoin_free(*line, head);
	}
	return (ft_strchr(*line, '\n') != NULL);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;
	int			res;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	line = extract_to_eo(buff);
	if (!(ft_strchr(line, '\n')))
	{
		res = read_until_eo(fd, buff, &line);
		if (res == -1 || (res == 0 && ft_strlen(line) == 0))
		{
			if (line)
				free(line);
			return (NULL);
		}
	}
	return (line);
}
/* 
 * EOL = End Of Line \n         EOF = End Of File
 * update_move : move substring to the head, fill buffer with '\0'.
 * extract_to_eo : extract chars from buff until EOL or EOB/EOF
 * 		buff could be either from previous read or current read.
 * read_until_eo : reads from file, until EOL or EOF, and appends to line 
 * get_next_line : provided conditions are met, 
 * 		gather chars from previous read until EOL or EOF
 * 		if line does not have a \n it starts reading file
 * 		until it will meet either EOL or EOF
 * 
 * */
