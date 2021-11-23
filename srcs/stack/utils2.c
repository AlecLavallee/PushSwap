#include "pushSwap.h"

/* Cherche un doublon sur les petites suites */
int	find_duplicate_small(t_stack *a)
{
	int			i;
	t_node	*elem;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (tmp->next)
	{
		elem = tmp->next;
		while (elem)
		{
			if (tmp->value == elem->value)
			{
				i++;
				break ;
			}
			elem = elem->next;
		}
		tmp = tmp->next;
	}
	return (i);
}

/* Détermine si la stack est triée ou pas */
int	is_sorted_stack(t_stack *a)
{
	t_node	*elem;

	elem = a->top;
	while (elem->next)
	{
		if (elem->next->value < elem->value)
			return (ERROR);
		elem = elem->next;
	}
	return (SUCCESS);
}