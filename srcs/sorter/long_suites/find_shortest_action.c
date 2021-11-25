/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_action.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:35:09 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/25 15:50:13 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Determines the best number of actions to do */
int	optimize_actions(int c_a, int c_b)
{
	if (c_a > 0 && c_b > 0)
		return (abs_value(c_a) + abs_value(c_b) - min(c_a, c_b));
	else if (c_a < 0 && c_b < 0)
		return (abs_value(c_a) + abs_value(c_b) + max(c_a, c_b));
	else
		return (abs_value(c_a) + abs_value(c_b));
	return (SUCCESS);
}

void	init_variables(int *i, int *pos, bool *end)
{
	*i = 1;
	*pos = 0;
	*end = false;
}

/* Calculate number of actions to do to position element on A */
/* Need to recalculate for every elements after 1 element has been moved*/
int	where_to_insert(t_stack *sta, int x, t_node *tmp, t_node *prev)
{
	int			i;
	int			pos;
	bool		end;

	init_variables(&i, &pos, &end);
	while (prev && !end)
	{
		if (tmp == NULL)
		{
			tmp = sta->top;
			end = true;
		}
		if ((x > prev->i && x < tmp->i)
			|| (prev->i > tmp->i && (x < tmp->i || x > prev->i)))
			pos = i;
		i++;
		prev = tmp;
		tmp = tmp->next;
	}
	if (pos > stack_length(sta) / 2)
		pos -= stack_length(sta);
	return (pos);
}

/* Finds the smallest number of actions to sort the element */
t_node	*evaluate_actions(t_all *all, t_params *params)
{
	t_node	*tmp;
	t_node	*prev;

	params->c_for_b = 0;
	params->min_move = 0xFFFFFFF;
	while (params->elem)
	{
		tmp = all->a->top->next;
		prev = all->a->top;
		params->c_for_a = where_to_insert(all->a, params->elem->i, tmp, prev);
		params->action_b = params->c_for_b;
		if (params->c_for_b > stack_length(all->b) / 2)
			params->action_b -= stack_length(all->b);
		params->total = optimize_actions(params->c_for_a, params->action_b);
		if (params->total < params->min_move)
		{
			params->min_move = params->total;
			params->best = params->elem;
			params->min_a = params->c_for_a;
			params->min_b = params->action_b;
		}
		params->elem = params->elem->next;
		params->c_for_b++;
	}
	return (params->best);
}
