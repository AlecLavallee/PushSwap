#include "pushSwap.h"

/* Verifie doublons et sera appelée quand on insère un nouvel elem */
void	check_duplicates(t_all *all)
{
	t_node	*elem1;
	t_node	*elem2;

	elem1 = all->a->top;
	elem2 = all->a->top;
	while (elem2)
	{
		elem1 = all->a->top;
		while (elem1)
		{
			if (elem1->value == elem2->value && elem1 != elem2)
				error(all, 1, NULL, NULL);
			elem1 = elem1->next;
		}
		elem2 = elem2->next;
	}
}

/* Retourne la valeur absolue d'un élément */
int	abs_value(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/* Initialise la structure de params pour le calcul des actions */
t_params	init_params(t_all *all)
{
	t_params	params;

	params.c_for_a = 0;
	params.c_for_b = 0;
	params.elem = all->b->top;
	params.best = NULL;
	params.min_a = 0;
	params.min_b = 0;
	params.min_move = 0xFFFFFFF;
	params.action_b = 0;
	params.total = 0;
	return (params);
}