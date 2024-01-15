/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:21:50 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 03:50:52 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_b_under_5(t_stack *stack)
{
	int	size;

	if (stack->head_b == NULL)
		return ;
	size = stack_size(stack, 'b');
	if (size > 5 || size == 0)
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

int	divide_pos(t_stack *stack, int unsorted, int percent)
{
	int		size;
	int		size_3;
	t_node	*nd;

	size = unsorted;
	nd = find_min_node(stack, 'a');
	size_3 = size * percent / 3;
	while (size_3 > 0)
	{
		nd = find_next_min_node(stack, 'a', nd);
		size_3--;
	}
	return (nd->rank);
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
	b_5_and_pa_ra(5, stack);
}

//int	divide_3(int unsorted, int middle, t_stack *stack, int small)
//{
//	t_node	*nd;
//	int		r_count;

//	nd = stack->head_a;
//	r_count = 0;
//	while (unsorted-- > 0)
//	{
//		if (nd->rank < small)
//		{
//			push(stack, 'b');
//			rotate(stack, 'b');
//		}
//		else if (nd->rank < middle)
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

int	divide_3(int unsorted, int middle, t_stack *stack, int small)
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

void	check_sort(t_stack *stack)
{
	t_node	*nd;

	nd = find_max_node(stack, 'a');
	if (nd->rank == last_nd(stack, 'a')->rank)
		return ;
	else
	{
		while (nd->rank != last_nd(stack, 'a')->rank)
			rev_rotate(stack, 'a');
	}
}

void	sort_many(int arg_num, t_stack *stack)
{
	int	middle;
	int	small;
	int	unsorted;
	int	r_count;
	t_node	*nd;

	unsorted = arg_num;
	middle = divide_pos(stack, unsorted, 2);
	small = divide_pos(stack, unsorted, 1);
	r_count = divide_3(unsorted, middle, stack, small);
	a_5_b_other(stack);
	sort_5(5, stack, 'a');
	first_insert(stack);
	nd = stack->head_b;
	while (stack->head_b != NULL)
	{
		insert(stack);
		//printf("arg_num[%d], stack_a_size[%d], head_a[%d], head_b[%d]\n", arg_num, stack_size(stack, 'a'), stack->head_a->rank, stack->head_b->rank);
	}
	check_sort(stack);
	//printf("fin\n");
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
	//unsorted = unsorted_num(stack);
	//while (unsorted > 10)
	//{
	//	sort_middle(stack, unsorted);
	//	unsorted = unsorted_num(stack);
	//}
	//if (unsorted > 5)
	//	sort_last_10(stack);
	//unsorted = unsorted_num(stack);
	////printf("c unsorted[%d]\n", unsorted);
	//if (unsorted <= 5)
	//{
	//	while (unsorted-- > 0)
	//		push(stack, 'b');
	//	stack_b_under_5(stack);
		//printf("d\n");
	//}
}
//void	sort_many(int arg_num, t_stack *stack)
//{
//	int	middle;
//	int	small;
//	int	unsorted;
//	int	r_count;

//	//printf("a\n");
//	unsorted = arg_num;
//	middle = divide_pos(stack, unsorted, 2);
//	small = divide_pos(stack, unsorted, 1);
//	r_count = divide_3(unsorted, middle, stack, small);
//	b_5_and_pa_ra(stack);
//	unsorted = unsorted_num(stack);
//	while (unsorted > 10)
//	{
//		sort_middle(stack, unsorted);
//		unsorted = unsorted_num(stack);
//	}
//	if (unsorted > 5)
//		sort_last_10(stack);
//	unsorted = unsorted_num(stack);
//	//printf("c unsorted[%d]\n", unsorted);
//	if (unsorted <= 5)
//	{
//		while (unsorted-- > 0)
//			push(stack, 'b');
//		stack_b_under_5(stack);
//		//printf("d\n");
//	}
