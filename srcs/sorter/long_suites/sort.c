/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:34:24 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/24 13:26:45 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_mins(t_all *all, t_params *params)
{
	while (params->min_b > 0 && params->min_a > 0)
	{
		rr(all->a, all->b, 1, all);
		params->min_b--;
		params->min_a--;
	}
	while (params->min_a < 0 && params->min_b < 0)
	{
		rrr(all->a, all->b, 1, all);
		params->min_b++;
		params->min_a++;
	}
	return (SUCCESS);
}

/* executes all the actions stored in params */
int	sort(t_all *all, t_params *params)
{
	if ((params->min_b > 0 && params->min_a > 0)
		|| (params->min_b < 0 && params->min_a < 0))
		sort_mins(all, params);
	while (params->min_b > 0)
	{
		rb(all->b, 1, all);
		(params->min_b)--;
	}
	while (params->min_b < 0)
	{
		rrb(all->b, 1, all);
		params->min_b++;
	}
	while (params->min_a > 0)
	{
		ra(all->a, 1, all);
		(params->min_a)--;
	}
	while (params->min_a < 0)
	{
		rra(all->a, 1, all);
		params->min_a++;
	}
	pa(all->b, all->a, 1, all);
	return (SUCCESS);
}
