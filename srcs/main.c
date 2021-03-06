/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:53 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/25 19:29:24 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* main algorithm of the program */
void	algorithm(t_all *all)
{
	t_stack		*cpy;
	t_params	params;

	params = init_params(all);
	cpy = cpy_stack(all->a, all, &params);
	bubble_sort_cpy(cpy);
	set_target_index_cpy(cpy);
	set_target_index(cpy);
	free_stack(cpy);
	set_keep(all);
	push_keep_false_b(all);
	while (!is_empty_stack(all->b))
	{
		params.elem = all->b->top;
		evaluate_actions(all, &params);
		sort(all, &params);
	}
	if (!(is_on_top(all->a, smallest(all->a))))
		bring_to_top(all->a, smallest(all->a), all);
	if (is_empty_stack(all->a))
		error(all, 1, NULL, NULL);
	free_all(all, NULL, NULL);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	int		red_args;

	if (argc < 2)
		return (0);
	all = init_all();
	if (argc >= 2)
	{
		red_args = read_args(argc, argv, all);
		if (is_empty_stack(all->a))
			error(all, 1, NULL, NULL);
		if (is_sorted_stack(all->a))
			free_all(all, NULL, NULL);
		if (red_args <= 5)
			small_cases(all->a, all->b, all);
		else
			algorithm(all);
	}
	error(all, 0, NULL, NULL);
	return (0);
}
