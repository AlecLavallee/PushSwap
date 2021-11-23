#include "pushSwap.h"

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