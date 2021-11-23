#include "pushSwap.h"

/* Fonction de reverse rotate utile pour les différentes actions */
void	reverse_rotate(t_stack *sta)
{
	t_node	*prev;
	t_node	*elem;

	if (!sta->top || !sta->top->next || !sta)
		return ;
	elem = sta->top;
	while (elem->next)
	{
		prev = elem;
		elem = elem->next;
	}
	elem->next = sta->top;
	sta->top = elem;
	prev->next = NULL;
}

/* Action RRA demandée dans le sujet */
void	rra(t_stack *a, int print, t_all *all)
{
	reverse_rotate(a);
	if (print == 1)
		write(1, "rra\n", 4);
	all->action_count++;
}

/* Action RRB demandée dans le sujet*/
void	rrb(t_stack *b, int print, t_all *all)
{
	reverse_rotate(b);
	if (print == 1)
		write(1, "rrb\n", 4);
	all->action_count++;
}

/* Action RRR demandée dans le sujet */
void	rrr(t_stack *a, t_stack *b, int print, t_all *all)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print == 1)
		write(1, "rrr\n", 4);
	all->action_count--;
}