#include "pushSwap.h"

/* Calcule de façon optimiséele nombre d'actions a faire */
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

/* Calcule le nombre d'actions a faire pour positionner au bon index sur A */
/* Pour tous les elements, a recalculer apres avoir deplacé 1 élément */
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

/* Calcule le plus petit nombre d'actions a faire pour trier un element */
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