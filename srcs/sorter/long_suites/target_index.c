/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:33:55 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/25 16:45:46 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns a copy of the original stack */
t_stack	*cpy_stack(t_stack *sta, t_all *all, t_params *params)
{
	t_stack	*cpy;
	t_node	*read;

	if (!sta)
		return (NULL);
	cpy = (t_stack *)malloc(sizeof(t_stack));
	read = sta->top;
	if (!cpy)
		error(all, 1, &params->min_a, &params->min_b);
	read = sta->top;
	cpy->top = NULL;
	while (read)
	{
		push_end_plus_origin(cpy, read->value, read, all);
		read = read->next;
	}
	return (cpy);
}

/* Swap the value of 2 elements and marks the target in the original elements */
void	bubble_swap(t_node **ori, t_node **tmplst, t_node **elem, int *t)
{
	*t = (*elem)->value;
	*ori = (*elem)->init_pos;
	(*elem)->value = (*tmplst)->value;
	(*elem)->init_pos = (*tmplst)->init_pos;
	(*tmplst)->value = (*t);
	(*tmplst)->init_pos = *ori;
}

/* Applies bubble sort on the copied stack and returns it sorted */
t_stack	*bubble_sort_cpy(t_stack *cpy)
{
	int		temp;
	t_node	*origin;
	t_node	*tmplst;
	t_node	*elem;

	tmplst = cpy->top;
	elem = cpy->top;
	origin = cpy->top->init_pos;
	temp = cpy->top->value;
	while (elem)
	{
		while (tmplst)
		{
			if (elem->value > tmplst->value)
				bubble_swap(&origin, &tmplst, &elem, &temp);
			tmplst = tmplst->next;
		}
		elem = elem->next;
		tmplst = elem;
	}
	return (cpy);
}

/* Affects target index to elements of the copied stack */
void	set_target_index_cpy(t_stack *cpy)
{
	t_node	*elem;
	int		index;

	elem = cpy->top;
	index = 0;
	while (elem)
	{
		elem->i = index;
		elem = elem->next;
		index++;
	}
}

/* Affects target index to elements of the original stack A */
void	set_target_index(t_stack *sta)
{
	t_node	*elem;

	elem = sta->top;
	while (elem)
	{
		elem->init_pos->i = elem->i;
		elem = elem->next;
	}
}
