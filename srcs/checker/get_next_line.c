/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:43:19 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/23 17:06:02 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*init_stock(char **stock, int fd, void *tmp, int i)
{
	stock = malloc(sizeof(char));
	if ((read(fd, tmp, 0) == -1) || !line || !stock)
		return (NULL);
	stock[0] = '\0';
	return (stock);
}

int	ft_secure(char **stock, char **line, int i)
{
	if (i == 1)
	{
		if (!stock || !line)
		{
			if (*stock)
			{
				free(*stock);
				*stock = NULL;
			}
			if (*line)
			{
				free(*line);
				*line = NULL;
			}
		}
		return (1);
	}
	if (*stock && i == 2)
	{
		free(*stock);
		*stock = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int				i;
	static char		*stock = NULL;
	char			tmp[BUFFER_SIZE + 1];

	if (!stock || init_stock(stock, fd, tmp, i) == NULL)
		return (-1);
	while (ft_strclen(stock, '\n') == -1)
	{
		i = read(fd, tmp, BUFFER_SIZE));
		if (i < 0)
			break ;
		tmp[i] = '\0';
		stock = ft_strcat(stock, tmp);
	}
	if (ft_strclen(stock, '\n') != -1)
	{
		*line = ft_strncpy(*line, stock, ft_strclen(stock, '\n'));
		stock = ft_strtrim_left(stock, ft_strclen(stock, '\n') + 1);
		return (ft_secure(&stock, line, 1));
	}
	*line = ft_strncpy(*line, stock, ft_strclen(stock, '\0'));
	return (ft_secure(&stock, line, 2));
}
