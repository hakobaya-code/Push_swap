/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:28 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/15 21:19:13 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	sort_3a2(t_stack *stack)
//{
//	t_node	*nd;
//	int		num1;
//	int		num2;
//	int		num3;

//	nd = stack->head_a->next;
//	num1 = nd->prev->num;
//	num2 = nd->num;
//	num3 = nd->next->num;
//	if (num1 < num2 && num2 < num3) // 123
//	{
//		ra(stack);
//		sb(stack);
//	}
//	else if (num1 < num3 && num2 > num3) // 132
//		ra(stack);
//	else if (num2 < num1 && num1 < num3) // 213
//		rra(stack);
//	else if (num1 < num2 && num1 > num3) // 231
//		sa(stack);
//	else if (num1 > num2 && num2 < num3) // 312
//	{
//		rra(stack);
//		sa(stack);
//	}
//}

//void	sort_3b2(t_stack *stack)
//{
//	t_node	*nd;
//	int		num1;
//	int		num2;
//	int		num3;

//	nd = stack->head_b->next;
//	num1 = nd->prev->num;
//	num2 = nd->num;
//	num3 = nd->next->num;
//	if (num1 < num3 && num2 > num3) // 132
//	{
//		rrb(stack);
//		sb(stack);
//	}
//	else if (num2 < num1 && num1 < num3) // 213
//		sb(stack);
//	else if (num1 < num2 && num1 > num3) // 231
//		rrb(stack);
//	else if (num1 > num2 && num2 < num3) // 312
//		rb(stack);
//	else if (num1 > num2 && num2 > num3)
//	{
//		rb(stack);
//		sb(stack);
//	}
//}

//void	up_push(int a_size, int upper, t_stack *stack)
//{
//	//int	size;
//	//int	count;
//	t_node	*nd;

//	nd = stack->head_a;
//	printf("up_push\n");
//	//size = stack_a_size(stack);
//	//printf("size[%d]\n", size);
//	while (a_size > 0)
//	{
//		printf("a_size[%d]\n", a_size);
//		//printf("nd->rank[%d]\n", nd->rank);
//		if (nd->rank >= upper)
//			pb(stack);
//		else
//			ra(stack);
//		//size = stack_a_size(stack);
//		nd = nd->next;
//		a_size--;
//	}
//}

void	sort_10_6(t_stack *stack)
{
	t_node	*nd;
	int		count;

	nd = stack->head_a;
	//up_push(6, 4, stack);
	count = 6;
	while (count > 0 && stack_size(stack, 'a') > 4)
	{
		if (nd->rank >= 4)
			push(stack, 'b');
		else
			rotate(stack, 'a');
		count--;
		nd = stack->head_a;
	}
	sort_4(stack, 'a');
	push(stack, 'a');
	push(stack, 'a');
	nd = stack->head_a;
	if (nd->rank > nd->next->rank)
		swap(stack, 'a');
	rotate(stack, 'a');
	rotate(stack, 'a');
	return ;
}

void	sort_10(int arg_num, t_stack *stack, char c)
{
	t_node	*nd;
	int		count;

	if (c == 'a')
		nd = stack->head_a;
	else
		nd = stack->head_b;
	count = arg_num;
	//up_push(arg_num, 6, stack);
	while (count > 0 && stack_size(stack, 'a') > 6)
	{
		if (nd->rank >= 6)
			push(stack, 'b');
		else
			rotate(stack, 'a');
		count--;
		nd = stack->head_a;
	}
	if (arg_num == 10)
		sort_4(stack, 'b');
	if (arg_num == 9)
		sort_3(stack, 'b');
	if (arg_num == 8)
		sort_2(stack, 'b');
	sort_10_6(stack);
	//printf("🌟🌟🌟\n");
	return ;
}

//void	sort_10(int arg_num, t_stack *stack, char c)
//{
//	t_node	*nd;
//	int		count;

//	if (c == 'a')
//		nd = stack->head_a;
//	else
//		nd = stack->head_b;
//	count = arg_num;
//	//up_push(arg_num, 6, stack);
//	while (count > 0 && stack_a_size(stack) > 6)
//	{
//		if (nd->rank >= 6)
//			pb(stack);
//		else
//			ra(stack);
//		count--;
//		nd = stack->head_a;
//	}
//	if (arg_num == 10)
//		sort_4b(stack);
//	if (arg_num == 9)
//		sort_3b2(stack);
//	if (arg_num == 8)
//		sort_2b(stack);
//	sort_10_6(stack);
//	//printf("🌟🌟🌟\n");
//	return ;
//}