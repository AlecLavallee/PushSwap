/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:38:45 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/26 14:08:06 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				value;
	bool			keep;
	struct s_node	*init_pos;
	int				i;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	struct s_node		*top;
}				t_stack;

typedef struct s_all
{
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_node	*first_a;
	struct s_node	*first_b;
	int				size_a;
	int				size_b;
	int				max;
	int				max_size;
	int				action_count;
	char			*line;
	char			*s;
}				t_all;

typedef struct s_params
{
	t_node	*elem;
	t_node	*best;
	int		c_for_a;
	int		c_for_b;
	int		min_move;
	int		total;
	int		action_b;
	int		min_a;
	int		min_b;
}				t_params;

int		check_list(char **list);

t_node	*ft_lstnew(void);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **alst, t_node *new);
void	ft_lstadd_front(t_node **alst, t_node *new);
void	*ft_allset(void *b, int c, size_t len);
void	*ft_allcpy(void *dst, const void *src, size_t n);
void	ft_lstclear(t_node **lst);
void	ft_lstdelone(t_node *lst);

#endif