/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:36:13 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/23 16:36:14 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* Permet de pousser le premier élément de la stack a sur la stack b */
void	push_other_stack(t_stack *one, t_stack *two)
{
	t_node	*elem;

	if (is_empty_stack(one))
		return ;
	elem = one->top;
	if (stack_length(one) && stack_length(two))
	{
		one->top = one->top->next;
		elem->next = two->top;
		two->top = elem;
	}
	else if (!(stack_length(two)) && stack_length(one))
	{
		one->top = one->top->next;
		elem->next = NULL;
		two->top = elem;
	}
}

/* Fonction permettant d'ajouter un élément à la fin de la stack a */
void	push_end(t_stack *sta, int x, t_all *all)
{
	t_node	*elem;
	t_node	*temp;

	elem = (t_node *)malloc(sizeof(t_node));
	if (!elem)
		error(all, 1, NULL, NULL);
	elem->value = x;
	if (elem == NULL)
	{
		exit(EXIT_FAILURE);
		return ;
	}
	if (!sta->top)
	{
		elem->next = NULL;
		sta->top = elem;
		return ;
	}
	temp = sta->top;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	elem->next = NULL;
}

/* Ajoute un element a une liste en renseignant sa valeur et son origine */
void	push_end_plus_origin(t_stack *sta, int x, t_node *ori, t_all *m)
{
	t_node	*elem;
	t_node	*temp;

	elem = (t_node *)malloc(sizeof(t_node));
	if (!elem)
		error(m, 1, NULL, NULL);
	elem->value = x;
	elem->init_pos = ori;
	if (elem == NULL)
	{
		exit(EXIT_FAILURE);
		return ;
	}
	if (!sta->top)
	{
		elem->next = NULL;
		sta->top = elem;
		return ;
	}
	temp = sta->top;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	elem->next = NULL;
}

/* Action PA demandee dans le sujet */
void	pa(t_stack *one, t_stack *two, int print, t_all *all)
{
	if (is_empty_stack(one))
		return ;
	push_other_stack(one, two);
	if (print == 1)
		write(1, "pa\n", 3);
	all->action_count++;
}

/* Action PB demandee dans le sujet */
void	pb(t_stack *one, t_stack *two, int print, t_all *all)
{
	if (is_empty_stack(one))
		return ;
	push_other_stack(one, two);
	if (print == 1)
		write(1, "pb\n", 3);
	all->action_count++;
}
