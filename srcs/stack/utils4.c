/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:18 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/23 16:27:46 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* Search duplicates value in stack a*/
void	check_duplicates(t_all *all)
{
	t_node	*elem1;
	t_node	*elem2;

	elem1 = all->a->top;
	elem2 = all->a->top;
	while (elem2)
	{
		elem1 = all->a->top;
		while (elem1)
		{
			if (elem1->value == elem2->value && elem1 != elem2)
				error(all, 1, NULL, NULL);
			elem1 = elem1->next;
		}
		elem2 = elem2->next;
	}
}

/* Return absolute value of int x */
int	abs_value(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/* Initialize the params structure */
t_params	init_params(t_all *all)
{
	t_params	params;

	params.c_for_a = 0;
	params.c_for_b = 0;
	params.elem = all->b->top;
	params.best = NULL;
	params.min_a = 0;
	params.min_b = 0;
	params.min_move = 0xFFFFFFF;
	params.action_b = 0;
	params.total = 0;
	return (params);
}
