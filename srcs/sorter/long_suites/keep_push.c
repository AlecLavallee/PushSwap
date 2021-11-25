/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:34:38 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/24 14:22:47 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds the longest suit of already sorted elements in target */
/* sets keep variable to true if define is set to true */
int	largest_keep_a(t_node *start, t_stack *stack, bool define)
{
	t_node	*elem;
	int		index_max;
	int		count;

	elem = start;
	index_max = 0;
	count = 0;
	while (elem)
	{
		if (elem->i >= index_max)
		{
			if (define)
				elem->keep = true;
			index_max = elem->i;
			++count;
		}
		else if (define)
			elem->keep = false;
		elem = elem->next;
		if (elem == NULL)
			elem = stack->top;
		if (elem == start)
			break ;
	}
	return (count);
}

/* Returns the address of the first element of the sorted suit to keep in A */
t_node	*get_max_keep(t_stack *stack)
{
	t_node	*elem;
	t_node	*max;
	int		max_keep;
	int		cur;

	max_keep = 0;
	elem = stack->top;
	while (elem)
	{
		cur = largest_keep_a(elem, stack, false);
		if (cur > max_keep)
		{
			max_keep = cur;
			max = elem;
		}
		elem = elem->next;
	}
	return (max);
}

/* Determines the longest suit of elements already sorted */
void	set_keep(t_all *all)
{
	t_node	*max;
	t_stack	*stack;

	stack = all->a;
	max = get_max_keep(stack);
	all->max_size = largest_keep_a(max, stack, true);
}

/* Push every elements of stack A to B if variable keep = false */
void	push_keep_false_b(t_all *all)
{
	int	size;

	size = stack_length(all->a) - all->max_size;
	while (size > 0)
	{
		if (all->a->top->keep == false)
		{
			pb(all->a, all->b, 1, all);
			size--;
		}
		else
			ra(all->a, 1, all);
	}
}
