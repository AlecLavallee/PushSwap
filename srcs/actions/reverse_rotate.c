/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:36:20 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/24 13:40:38 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *sta)
{
	t_node	*prev;
	t_node	*elem;

	if (!sta->top || !sta->top->next || !sta)
		return ;
	elem = sta->top;
	while (elem->next)
	{
		prev = elem;
		elem = elem->next;
	}
	elem->next = sta->top;
	sta->top = elem;
	prev->next = NULL;
}

void	rra(t_stack *a, int print, t_all *all)
{
	reverse_rotate(a);
	if (print == 1)
		write(1, "rra\n", 4);
	all->action_count++;
}

void	rrb(t_stack *b, int print, t_all *all)
{
	reverse_rotate(b);
	if (print == 1)
		write(1, "rrb\n", 4);
	all->action_count++;
}

void	rrr(t_stack *a, t_stack *b, int print, t_all *all)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print == 1)
		write(1, "rrr\n", 4);
	all->action_count--;
}
