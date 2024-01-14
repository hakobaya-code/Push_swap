/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:21:50 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/14 18:53:30 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	half_rank(t_stack *stack, int unsorted, int percent)
{
	int		size;
	int		size_3;
	t_node	*nd;

	size = unsorted;
	nd = find_min_node(stack, 'a');
	size_3 = size * percent / 3;
	//if (size % 2 == 1)
	//	half_size = (size - 1) / 2;
	//else
	//	half_size = size / 2;
	while (size_3 > 0)
	{
		nd = find_next_min_node(stack, 'a', nd);
		size_3--;
	}
	return (nd->rank);
}

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

int	half_pb(int unsorted, int middle, t_stack *stack, int small)
{
	t_node	*nd;
	int		r_count;

	nd = stack->head_a;
	r_count = 0;
	while (unsorted-- > 0)
	{
		if (nd->rank < small)
		{
			push(stack, 'b');
			rotate(stack, 'b');
		}
		else if (nd->rank < middle)
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

//int	half_pb(int unsorted, int half, t_stack *stack, int quarter)
//{
//	t_node	*nd;
//	int		r_count;

//	nd = stack->head_a;
//	r_count = 0;
//	while (unsorted-- > 0)
//	{
//		if (nd->rank < quarter)
//		{
//			push(stack, 'b');
//			rotate(stack, 'b');
//		}
//		else if (nd->rank < half)
//		{
//			push(stack, 'b');
//		}
//		else
//		{
//			rotate(stack, 'a');
//			r_count++;
//		}
//		nd = stack->head_a;
//	}
//	return (r_count);
//}
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

void	sort_many(int arg_num, t_stack *stack, char c)
{
	int	middle;
	int	small;
	int	unsorted;
	int	r_count;

	unsorted = arg_num;
	middle = half_rank(stack, unsorted, 2);
	small = half_rank(stack, c, 1);
	r_count = half_pb(unsorted, middle, stack, small);
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
