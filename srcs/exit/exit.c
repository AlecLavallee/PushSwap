#include "pushSwap.h"

void	free_stack(t_stack *sta)
{
	t_node	*elem;

	elem = sta->top;
	while (elem)
	{
		sta->top = sta->top->next;
		free(elem);
		elem = NULL;
		elem = sta->top;
	}
	free(sta);
	sta = NULL;
}

void	free_all(t_all *all, int *min_a, int *min_b)
{
	free_stack(all->a);
	free_stack(all->b);
	free(all);
	all = NULL;
	if (!min_a)
	{
		free(min_a);
		min_a = NULL;
	}
	if (!min_b)
	{
		free(min_b);
		min_b = NULL;
	}
	exit (EXIT_SUCCESS);
}

void	error(t_all *all, int print, int *min_a, int *min_b)
{
	if (print == 1)
		write(2, "Error\n", 6);
	free_all(all, min_a, min_b);
	exit (EXIT_FAILURE);
}