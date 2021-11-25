/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:32:48 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/25 19:13:50 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find a duplicate on a small stack */
int	find_duplicate_small(t_stack *a)
{
	int		i;
	t_node	*elem;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (tmp->next)
	{
		elem = tmp->next;
		while (elem)
		{
			if (tmp->value == elem->value)
			{
				i++;
				break ;
			}
			elem = elem->next;
		}
		tmp = tmp->next;
	}
	return (i);
}

/* Returns success if the stack is sorted */
int	is_sorted_stack(t_stack *a)
{
	t_node	*elem;

	elem = a->top;
	while (a->top && elem->next)
	{
		if (elem->next->value < elem->value)
			return (ERROR);
		elem = elem->next;
	}
	return (SUCCESS);
}
