/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:29:04 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/23 16:29:06 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	push_atoi(char *str, t_all *all)
{
	long	i;
	long	max;
	long	sign;
	long	result;

	i = 0;
	max = 0;
	sign = 1;
	result = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (ft_isalpha(str[i]) || max >= 1)
			error(all, 1, NULL, NULL);
		if (str[i] == '-')
			sign = -sign;
		max++;
		i++;
	}
	if (!str[i] || !ft_isdigit(str[i]))
		error(all, 1, NULL, NULL);
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (str[i] && !(ft_isdigit(str[i])) && str[i] != ' ')
		error(all, 1, NULL, NULL);
	return (result * sign);
}
