/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:26:25 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 08:05:21 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DEBUG_PRINTF() \
	printf("file : %s, line : %s, func : %d\n", __FILE__, __func__, __LINE__);

typedef struct s_node
{
	int				num;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head_a;
	t_node			*head_b;
}					t_stack;

void	error_notdigit(void);
int		error_argc(void);
void	error_overint(void);
void	error_same_num(int *array);
int		check_argv(int argc, char **argv, int flag);
void	check_sorted(t_stack *stack);
int		*make_array(int arg_num, char **argv, int flag);
int		*make_split_array(int *argc, char **argv);
char	**split_array(char **argv);
t_node	*initialize_list(int num);
t_node	*initialize_stackb(void);
t_node	*last_node(t_node *node);
void	*add_node(t_node *node, int num);
int		*compaction(int *array, int len, t_node *node);

// util
int		count_words(char **argv);
t_node	*last_nd(t_stack *stack, char c);
void	top_push(int arg_num, int pos, t_stack *stack, char c);
int		node_position(t_stack *stack, t_node *node, char c);
t_node	*find_min_node(t_stack *stack, char c);
t_node	*find_next_min_node(t_stack *stack, char c, t_node *min);
t_node	*find_max_node(t_stack *stack, char c);
t_node	*find_next_max_node(t_stack *stack, char c, t_node *max);
int		calc_min(t_stack *stack);
int		calc_second_min(t_stack *stack, int min);
int		stack_size(t_stack *stack, char c);
void	free_stack(t_stack *stack);
void	free_node(t_node *nd);

// sort

// swap
void	swap(t_stack *stack, char c);
void	ss(t_stack *stack);
//static void			sa(t_stack *stack);
//static void			sb(t_stack *stack);

// rotate
void	rotate(t_stack *stack, char c);
void	rr(t_stack *stack);
//static void			ra(t_stack *stack);
//static void			rb(t_stack *stack);

// rev_rotate
void	rev_rotate(t_stack *stack, char c);
void	rrr(t_stack *stack);
//static void			rra(t_stack *stack);
//static void			rrb(t_stack *stack);

// push
void	push(t_stack *stack, char c);
//static void		pa(t_stack *stack);
//static void		pb(t_stack *stack);

//sort util
void	digit_1(t_stack *stack);
void	digit_1_pb(int num1, int num2, t_stack *stack);
void	digit_10(int arg_num, t_stack *stack);
void	digit_10_pa(int num, t_stack *stack);
void	a_5_b_other(int arg_num, t_stack *stack);
void	b_5_and_pa_ra(int arg_num, t_stack *stack);
void	b_3_and_pa_ra(t_stack *stack);

//sort_many util
int		half_pb(int unsorted, int half, t_stack *stack, int quarter);
t_node	*rank_0_pos(t_stack *stack);
int		unsorted_num(t_stack *stack);
t_node	*find_min_node_until_rank0(t_stack *stack);
t_node	*find_next_min_node_until_rank0(t_stack *stack, t_node *min);
int		unsorted_min5(t_stack *stack, int unsorted);
int		min5_pb(t_stack *stack, int unsorted, int min5);
void	stack_b_under_5(t_stack *stack);
void	sort_last_10(t_stack *stack);

//sort
void	s_r(t_stack *stack, char c);
void	r_s(t_stack *stack, char c);
void	sort(int arg_num, t_stack *stack);
void	sort_rev(int arg_num, t_stack *stack, char c);
void	sort_2(t_stack *stack, char c);
void	sort_2_rev(t_stack *stack, char c);
void	sort_3(t_stack *stack, char c);
void	sort_3_rev(t_stack *stack, char c);
void	sort_4(t_stack *stack, char c);
void	sort_4_rev(t_stack *stack, char c);
void	sort_5(int arg_num, t_stack *stack, char c);
void	sort_5_rev(t_stack *stack, char c);
void	sort_5b_rev(int arg_num, t_stack *stack);
void	sort_10(int arg_num, t_stack *stack, char c);
void	sort_15(int arg_num, t_stack *stack);
void	sort_many(int arg_num, t_stack *stack);
void	sort_middle(t_stack *stack, int unsorted);
void	first_insert(t_stack *stack);
void	insert(t_stack *stack);

#endif
