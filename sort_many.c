/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:21:50 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 20:15:13 by hakobaya         ###   ########.fr       */
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
		sort_5_rev(5, stack, 'b');
	else if (size == 4)
		sort_4_rev(stack, 'b');
	else if (size == 3)
		sort_3_rev(stack, 'b');
	if (size == 2)
		sort_2_rev(stack, 'b');
	while (size-- > 0)
		push(stack, 'a');
}

//void	sort_100(int arg_num, t_stack *stack)
//{
//	return ;
//}

void	half_pb(int arg_num, int half, t_stack *stack)
{
	t_node	*nd;
	int		quarter;

	nd = stack->head_a;
	if (half % 2 == 1)
		quarter = (half + 1) / 2;
	else
		quarter = half / 2;
	//printf("half[%d]\n", half);
	//printf("quarter[%d]\n", quarter);
	//if (quarter < 5)
	//	quarter = 5;
	if (half <= 5)
	{
		while (arg_num-- > 0)
		{
			push(stack, 'b');
			nd = stack->head_a;
		}
		return ;
	}
	while (arg_num-- > 0)
	{
		if (nd->rank < quarter)
		{
			push(stack, 'b');
			rotate(stack, 'b');
		}
		else if (nd->rank < half)
			push(stack, 'b');
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}

//void	min_sort_5(t_stack *stack)
//{
//	return ;
//}

void	sort_many(int arg_num, t_stack *stack, char c)
{
	int	size;
	int	half_rank;
	int	unsorted;

	size = stack_size(stack, c);
	unsorted = arg_num;
	while (unsorted > 10)
	{
		if (unsorted % 2 == 1)
			half_rank = (unsorted - 1) / 2;
		else
			half_rank = unsorted / 2;
		//printf("half_rank[%d]\n", half_rank);
		half_pb(unsorted, half_rank, stack);
		//printf("half_pb done\n");
		b_5_and_pa_ra(stack);
		//printf("b_5_and_pa_ra done\n");
		unsorted = unsorted_num(stack);
		//printf("unsorted[%d]\n", unsorted);
	}
	if (unsorted > 5)
	{
		a_5_b_other(stack);
		sort_5(5, stack, 'a');
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
	if (unsorted <= 5)
	{
		while (unsorted-- > 0)
			push(stack, 'b');
		stack_b_under_5(stack);
		//return ;
	}
	return ;
}
