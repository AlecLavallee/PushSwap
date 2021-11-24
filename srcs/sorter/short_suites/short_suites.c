/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_suites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:33:42 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/24 13:30:49 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort two unsorted elements */
void	sort_two(t_stack *a, t_all *all)
{
	t_node	*elem;

	if (!a)
		return ;
	elem = a->top;
	if (elem->value > elem->next->value)
		sa(a, 1, all);
	free_all(all, NULL, NULL);
}

/* Manages sorting of suits of 3 elements */
void	sort_three(t_stack *a, t_all *all)
{
	int				one;
	int				two;
	int				three;

	if (!a || !all)
		error(all, 1, NULL, NULL);
	one = a->top->value;
	two = a->top->next->value;
	three = a->top->next->next->value;
	if (one > two && two < three && one < three)
		sa(a, 1, all);
	else if (one > two && two > three && one > three)
	{
		sa(a, 1, all);
		rra(a, 1, all);
	}
	else if (one > two && two < three && one > two)
		ra(a, 1, all);
	else if (one < two && two > three && one < three)
	{
		sa(a, 1, all);
		ra(a, 1, all);
	}
	else if (one < two && two > three && one > three)
		rra(a, 1, all);
}

void	prep_set(t_stack *a, t_stack *b, t_all *all)
{
	int	big;
	int	small;

	big = biggest(a);
	small = smallest(a);
	while (!is_on_top(a, small))
		bring_to_top(a, small, all);
	pb(a, b, 1, all);
	if (stack_length(a) > 3)
	{
		while (!is_on_top(a, big))
			bring_to_top(a, big, all);
		pb(a, b, 1, all);
	}
}

/* Manages sorting of 4 to 5 elements suites */
void	sort_more_three(t_stack *a, t_stack *b, t_all *all)
{
	int	stack_len;

	stack_len = stack_length(a);
	prep_set(a, b, all);
	sort_three(a, all);
	if (stack_len == 5)
	{
		pa(b, a, 1, all);
		ra(a, 1, all);
	}
	pa(b, a, 1, all);
	if (is_empty_stack(all->a))
		error(all, 1, NULL, NULL);
	free_all(all, NULL, NULL);
}

/* Manages all sorting of small suits */
int	small_cases(t_stack *a, t_stack *b, t_all *all)
{
	if (stack_length(a) == 1)
	{
		free_all(all, NULL, NULL);
	}
	else if (stack_length(a) == 2)
		sort_two(a, all);
	else if (stack_length(a) == 3)
	{
		sort_three(a, all);
		free_all(all, NULL, NULL);
	}
	else
		sort_more_three(a, b, all);
	if (is_empty_stack(all->a))
		error(all, 1, NULL, NULL);
	if (is_empty_stack(all->a))
		error(all, 1, NULL, NULL);
	free_all(all, NULL, NULL);
	return (SUCCESS);
}
