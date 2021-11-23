#include "pushSwap.h"

/* Fonction rotate utile pour toutes les actions */
void	rotate_stack(t_stack *sta)
{
	t_node	*last;
	t_node	*tmp;

	if (!sta)
		return ;
	last = last_element(sta);
	tmp = sta->top;
	sta->top = sta->top->next;
	tmp->next = NULL;
	last->next = tmp;
}

/* Action RA demandée dans le sujet */
void	ra(t_stack *a, int print, t_all *all)
{
	if (!a || !all)
		return ;
	rotate_stack(a);
	if (print == 1)
		write(1, "ra\n", 3);
	all->action_count++;
}

/* Action RB demandée dans le sujet */
void	rb(t_stack *b, int print, t_all *all)
{
	if (!b || !all)
		return ;
	rotate_stack(b);
	if (print == 1)
		write(1, "rb\n", 3);
	all->action_count++;
}

/* Action RR demandée dans le sujet */
void	rr(t_stack *a, t_stack *b, int print, t_all *all)
{
	if (!b || !all || !a)
		return ;
	rotate_stack(a);
	rotate_stack(b);
	if (print == 1)
		write(1, "rr\n", 3);
	all->action_count++;
}

t_node	*last_element(t_stack *sta)
{
	t_node	*elem;

	if (!sta || !sta->top)
		return (NULL);
	elem = sta->top;
	while (elem->next)
		elem = elem->next;
	return (elem);
}