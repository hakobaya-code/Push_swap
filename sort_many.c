/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:21:50 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 17:33:02 by hakobaya         ###   ########.fr       */
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
	if (size == 5)
		sort_5_rev(5, stack, 'b');
	else if (size == 4)
		sort_4_rev(stack, 'b');
	else if (size == 3)
		sort_3_rev(stack, 'b');
	if (size == 2)
		sort_2_rev(stack, 'b');
	else if (size == 1)
		;
	else
		return ;
	while (size-- > 0)
		push(stack, 'a');
}

//void	sort_100(int arg_num, t_stack *stack)
//{
//	return ;
//}

void	sort_many(int arg_num, t_stack *stack, char c)
{
	int	size;

	size = stack_size(stack, c);
	a_5_b_other(arg_num, stack);
	sort_5(arg_num, stack, c);
	while (1)
	{
		if (stack->head_a == NULL)
			break ;
		printf("💓check node stack_a *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_a, stack->head_a->num, stack->head_a->rank, stack->head_a->prev, stack->head_a->next);
		stack->head_a = stack->head_a->next;
	}
	while (1)
	{
		if (stack->head_b == NULL)
			break ;
		printf("💭check node stack_b *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_b, stack->head_b->num, stack->head_b->rank, stack->head_b->prev, stack->head_b->next);
		stack->head_b = stack->head_b->next;
	}
	if (stack_size(stack, 'b') <= 5)
		stack_b_under_5(stack);
	//printf("size[%d]\n", size);
	//printf("arg_num[%d]\n", arg_num);
	//if (arg_num <= 10)
	//	sort_10(arg_num, stack, c);
	//if (arg_num <= 100)
	//	sort_100(arg_num, stack, c);
	return ;
}
