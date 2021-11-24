/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:36:33 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/24 13:43:12 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap first two elements of the specified stack */
void	swap_ab(t_stack *sta)
{
	t_node	*elem;
	t_node	*second;

	if (!sta)
		return ;
	if (stack_length(sta) >= 2)
	{
		elem = sta->top;
		second = sta->top->next->next;
		sta->top = sta->top->next;
		sta->top->next = elem;
		elem->next = second;
	}
}

void	sa(t_stack *a, int print, t_all *all)
{
	if (!a || !all)
		return ;
	swap_ab(a);
	if (print == 1)
		write(1, "sa\n", 3);
	all->action_count++;
}

void	sb(t_stack *b, int print, t_all *all)
{
	if (!b || !all)
		return ;
	swap_ab(b);
	if (print == 1)
		write(1, "sb\n", 3);
	all->action_count++;
}

void	ss(t_stack *a, t_stack *b, int print, t_all *all)
{
	if (!a || !b || !all)
		return ;
	swap_ab(a);
	swap_ab(b);
	if (print == 1)
		write(1, "ss\n", 3);
	all->action_count++;
}
