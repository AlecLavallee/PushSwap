/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:31:20 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/24 11:25:56 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Bring element to the top of the stack */
void	bring_to_top(t_stack *sta, int x, t_all *all)
{
	if (!sta)
		return ;
	if (is_on_top(sta, x))
		return ;
	if (where_middle(sta, x) == 1)
	{
		while (!is_on_top(sta, x))
			ra(sta, 1, all);
	}
	else
	{
		while (!is_on_top(sta, x))
			rra(sta, 1, all);
	}
}

/* Find in which half of the stack you're in*/
int	where_middle(t_stack *a, int value)
{
	t_node	*elem;
	float	i;

	if (!a)
		return (-1);
	elem = a->top;
	i = 1;
	while (elem)
	{
		if (elem->value == value)
		{
			if (i / (float)stack_length(a) <= 0.5)
				return (1);
			else
				return (2);
		}
		elem = elem->next;
		i++;
	}
	return (-1);
}

/* Indentify biggest element of the stack*/
int	biggest(t_stack *a)
{
	int		biggest;
	t_node	*elem;

	if (!a)
		return (0);
	elem = a->top;
	biggest = elem->value;
	while (elem)
	{
		if (elem->value > biggest)
			biggest = elem->value;
		elem = elem->next;
	}
	return (biggest);
}

/* Identify smallest element of the stack*/
int	smallest(t_stack *a)
{
	int		smallest;
	t_node	*elem;

	if (!a)
		return (0);
	elem = a->top;
	smallest = elem->value;
	while (elem)
	{
		if (elem->value < smallest)
			smallest = elem->value;
		elem = elem->next;
	}
	return (smallest);
}

/* Returns success if value x is at the top of the stack */
int	is_on_top(t_stack *a, int x)
{
	if (a->top->value == x)
		return (SUCCESS);
	return (ERROR);
}
