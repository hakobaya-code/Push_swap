/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:26:25 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/04 22:11:44 by hakobaya         ###   ########.fr       */
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
	int				rank;
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
void	error_overint(void);
void	error_same_num(int *array);
int		check_argv(int argc, char **argv);
int		*make_array(int arg_num, char **argv);
t_node	*initialize_list(int num);
t_node	*initialize_stackb(void);
t_node	*last_node(t_node *node);
void	*add_node(t_node *node, int num);
int		*compaction(int *array, int len, t_node *node);

// util
t_node	*last_nd(t_stack *stack);
void	top_push(int arg_num, int pos, t_stack *stack);
int		node_position(t_stack *stack, t_node *node);
t_node	*find_min_node(t_stack *stack);
int		calc_min(t_stack *stack);
int		calc_second_min(t_stack *stack, int min);

// sort

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
void	sort_2(t_stack *stack);
void	sort_2b(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_3b(t_stack *stack);
void	sort_4(int arg_num, t_stack *stack);
void	sort_5(int arg_num, t_stack *stack);
void	sort_5_2(t_stack *stack, int min, int min2);
void	sort_u6(int arg_num, t_stack *stack);
void	sort_6(int arg_num, t_stack *stack);


#endif
