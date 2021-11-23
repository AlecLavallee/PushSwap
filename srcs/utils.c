/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:33:20 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/23 16:33:22 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
