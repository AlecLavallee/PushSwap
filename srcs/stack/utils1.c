/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:27:56 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/26 14:18:11 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns true if the stack is sorted or else false */
bool	is_empty_stack(t_stack *sta)
{
	if (sta->top == NULL)
		return (true);
	return (false);
}

/* Returns the length of the stack as int */
int	stack_length(t_stack *sta)
{
	int		length;
	t_node	*elem;

	if (!sta)
		return (0);
	length = 0;
	elem = sta->top;
	while (elem)
	{
		length++;
		elem = elem->next;
	}
	return (length);
}

/* Initialize structure */
t_all	*init_all(void)
{
	t_all	*all;
	t_stack	*a;
	t_stack	*b;

	all = (t_all *)malloc(sizeof(t_all));
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!all || !a || !b)
		exit (EXIT_FAILURE);
	a->top = NULL;
	b->top = NULL;
	all->action_count = 0;
	all->a = a;
	all->b = b;
	all->line = NULL;
	all->s = NULL;
	return (all);
}

/* parse the args */
int	push_args(char *string, t_all *all, int *args)
{
	long	x;
	bool	space;

	space = true;
	while (*string)
	{
		if (space && *string != ' ')
		{
			x = push_atoi(string, all);
			if (x > INT_MAX || x < INT_MIN)
				error(all, 1, NULL, NULL);
			push_end(all->a, x, all);
			(*args)++;
			check_duplicates(all);
		}
		space = *string == ' ';
		string++;
	}
	return (SUCCESS);
}

/* read the args passed in parameter */
int	read_args(int argc, char **argv, t_all *all)
{
	int		args;
	int		i;

	i = 1;
	args = 0;
	while (i < argc)
	{
		push_args(argv[i], all, &args);
		i++;
	}
	if (!(all->a->top))
		error(all, 0, NULL, NULL);
	return (args);
}
