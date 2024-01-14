/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:21:50 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/14 18:41:31 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	half(int arg_num, t_stack *stack)
{
	t_node	*nd;
	int		half_num;

	nd = stack->head_a;
	if (arg_num % 2 == 1)
		half_num = (arg_num + 1) / 2;
	else
		half_num = arg_num / 2;
	if (nd->rank >= half_num)
		return (1);
	else
		return (0);
}

//void	start_half(int arg_num, t_stack *stack)
//{
//	t_node	*nd;
//	t_node	*end;
//	int		i;

//	i = 0;
//	nd = stack->head_a;
//	end = last_nd(stack);
//	while (i < arg_num)
//	{
//		if (half(arg_num, stack) == 1)
//			pb(stack);
//		else
//			ra(stack);
//		i++;
//	}
//}



void	stack_b_under_5(t_stack *stack)
{
	int	size;

	size = stack_size(stack, 'b');
	if (size > 5)
		return ;
	if (size == 5)
		sort_5(5, stack, 'b');
	else if (size == 4)
		sort_4(stack, 'b');
	else if (size == 3)
		sort_3(stack, 'b');
	if (size == 2)
		sort_2(stack, 'b');
	while (size-- > 0)
	{
		push(stack, 'a');
		rotate(stack, 'a');
	}
}

//void	sort_100(int arg_num, t_stack *stack)
//{
//	return ;
//}

int	half_rank(t_stack *stack, char c, int unsorted)
{
	int		size;
	int		half_size;
	t_node	*half_nd;

	size = unsorted;
	half_nd = find_min_node(stack, c);
	//printf("min_nd[%d]\n", half_nd->rank);
	if (size % 2 == 1)
		half_size = (size - 1) / 2;
	else
		half_size = size / 2;
	while (half_size > 0)
	{
		half_nd = find_next_min_node(stack, c, half_nd);
		unsorted--;
		half_size--;
		//printf("size [%d], half [%d]\n", size, half_nd->rank);
	}
	//printf("half_nd[%d]\n", half_nd->rank);
	return (half_nd->rank);
}

//int	half_rank_unsorted(t_stack *stack, int unsorted)
//{
//	int		size;
//	int		half_size;
//	t_node	*half_nd;

//	size = unsorted;
//	half_nd = find_min_node_until_rank0(stack);
//	if (size % 2 == 1)
//		half_size = (size - 1) / 2;
//	else
//		half_size = size / 2;
//	while (half_size > 0)
//	{
//		half_nd = find_next_min_node_until_rank0(stack, half_nd);
//		half_size--;
//		//printf("size [%d], half [%d]\n", size, half_nd->rank);
//	}
//	return (half_nd->rank);
//}

int	unsorted_min5(t_stack *stack, int unsorted)
{
	t_node	*min5;
	int		size;
	int		count;

	size = unsorted;
	count = 4;
	min5 = find_min_node_until_rank0(stack);
	while (count > 0)
	{
		min5 = find_next_min_node_until_rank0(stack, min5);
		count--;
	}
	return (min5->rank);
}

t_node	*rank_0_pos(t_stack *stack)
{
	t_node	*nd;

	nd = stack->head_a;
	while (nd->next != NULL)
	{
		if (nd->rank == 0)
			return (nd);
		nd = nd->next;
	}
	exit(1);
}

void	sort_last_10(t_stack *stack)
{
	t_node	*nd;
	t_node	*rank_0;
	int		unsorted;

	nd = stack->head_a;
	rank_0 = rank_0_pos(stack);
	unsorted = unsorted_num(stack);
	while (unsorted-- > 0)
		push(stack, 'b');
	b_5_and_pa_ra(stack);
}

int	half_pb(int unsorted, int half, t_stack *stack, int quarter)
{
	t_node	*nd;
	int		r_count;

	nd = stack->head_a;
	//printf("unsorted [%d] half [%d] quarter [%d]\n", unsorted, half, quarter);
	r_count = 0;
	while (unsorted-- > 0)
	{
		if (nd->rank < quarter)
		{
			push(stack, 'b');
			rotate(stack, 'b');
		}
		else if (nd->rank < half)
		{
			push(stack, 'b');
		}
		else
		{
			rotate(stack, 'a');
			r_count++;
		}
		nd = stack->head_a;
	}
	return (r_count);
}

int	min5_pb(t_stack *stack, int unsorted, int min5)
{
	t_node	*nd;
	int		r_count;
	int		pb_count;

	nd = stack->head_a;
	r_count = 0;
	pb_count = 0;
	while (unsorted-- > 0 && pb_count < 5)
	{
		if (nd->rank <= min5)
		{
			push(stack, 'b');
			pb_count++;
		}
		else
		{
			rotate(stack, 'a');
			r_count++;
		}
		nd = stack->head_a;
	}
	return (r_count);
}

void	sort_middle(t_stack *stack, int unsorted)
{
	int	r_count;
	int	min5;

	min5 = unsorted_min5(stack, unsorted);
	r_count = min5_pb(stack, unsorted, min5);
	while (r_count-- > 0)
		rev_rotate(stack, 'a');
	if (stack_size(stack, 'b') > 5)
		b_5_and_pa_ra(stack);
	else
		stack_b_under_5(stack);
}

//void	sort_middle(t_stack *stack, int unsorted)
//{
//	int	r_count;
//	int	half;
//	int	quarter;

//	half = half_rank_unsorted(stack, unsorted);
//	quarter = half_rank_unsorted(stack, half);
//	r_count = half_pb(unsorted, half, stack, quarter);
//	while (r_count-- > 0)
//		rev_rotate(stack, 'a');
//	if (stack_size(stack, 'b') > 5)
//		b_5_and_pa_ra(stack);
//	else
//		stack_b_under_5(stack);
//}
void	sort_many(int arg_num, t_stack *stack, char c)
{
	int	half;
	int	quarter;
	int	unsorted;
	int	r_count;

	unsorted = arg_num;
	half = half_rank(stack, c, unsorted);
	quarter = half_rank(stack, c, unsorted);
	//printf("half_rank[%d]\n", half);
	r_count = half_pb(unsorted, half, stack, quarter);
	b_5_and_pa_ra(stack);
	unsorted = unsorted_num(stack);
	while (unsorted > 10)
	{
		sort_middle(stack, unsorted);
		unsorted = unsorted_num(stack);
	}
	if (unsorted > 5)
		sort_last_10(stack);
	unsorted = unsorted_num(stack);
	if (unsorted <= 5)
	{
		while (unsorted-- > 0)
			push(stack, 'b');
		stack_b_under_5(stack);
	}
	//while (1)
	//{
	//	if (stack->head_a == NULL)
	//		break ;
	//	printf("💓check node stack_a *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_a, stack->head_a->num, stack->head_a->rank, stack->head_a->prev, stack->head_a->next);
	//	stack->head_a = stack->head_a->next;
	//}
	//while (1)
	//{
	//	if (stack->head_b == NULL)
	//		break ;
	//	printf("💭check node stack_b *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_b, stack->head_b->num, stack->head_b->rank, stack->head_b->prev, stack->head_b->next);
	//	stack->head_b = stack->head_b->next;
	//}
	return ;
}
