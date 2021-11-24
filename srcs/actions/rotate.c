/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by alelaval          #+#    #+#             */
/*   Updated: 2021/11/24 13:39:50 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *sta)
{
	t_node	*last;
	t_node	*tmp;

	if (!sta)
		return ;
	last = last_element(sta);
	tmp = sta->top;
	sta->top = sta->top->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_stack *a, int print, t_all *all)
{
	if (!a || !all)
		return ;
	rotate_stack(a);
	if (print == 1)
		write(1, "ra\n", 3);
	all->action_count++;
}

void	rb(t_stack *b, int print, t_all *all)
{
	if (!b || !all)
		return ;
	rotate_stack(b);
	if (print == 1)
		write(1, "rb\n", 3);
	all->action_count++;
}

void	rr(t_stack *a, t_stack *b, int print, t_all *all)
{
	if (!b || !all || !a)
		return ;
	rotate_stack(a);
	rotate_stack(b);
	if (print == 1)
		write(1, "rr\n", 3);
	all->action_count++;
}

/* Returns last element of the stack */
t_node	*last_element(t_stack *sta)
{
	t_node	*elem;

	if (!sta || !sta->top)
		return (NULL);
	elem = sta->top;
	while (elem->next)
		elem = elem->next;
	return (elem);
}
