/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:26:25 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/12 16:59:35 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

# define DEBUG_PRINTF() \
	printf("file : %s, line : %s, func : %d\n", __FILE__, __func__, __LINE__);

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head_a;
	t_node	*head_b;
}	t_stack;

void	error_notdigit(void);
int		error_argc(void);
int		check_argv(int argc, char **argv);
int		*make_array(int arg_num, char **argv);
t_node	*initialize_list(int num);
t_node	*initialize_stackb(void);
t_node	*last_node(t_node *node);
void	*add_node(t_node *node, int num);
void	error_overint(void);

// swap
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

// rotate
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

// push
void	pa(t_stack *stack);
void	pb(t_stack *stack);

//sort
void	sort(int arg_num, t_stack *stack);

#endif
