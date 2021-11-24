/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:45:08 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/24 12:35:01 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "push_swap.h"

# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line, t_all *all);
char	*gnl_strjoin(char *s1, char *s2, t_all *all);
int		ft_len(const char *s);

#endif
