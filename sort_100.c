/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:42:31 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/11 20:25:44 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_1_pb(int num1, int num2, t_stack *stack)
{
	t_node	*nd;

	nd = stack->head_a;
	if (nd->rank % 10 == num1 || nd->rank % 10 == num2)
	{
		pb(stack);
		if (nd->rank % 10 == num1)
			rb(stack);
	}
	else
		ra(stack);
}

void	digit_1(t_stack *stack)
{
	t_node	*nd;
	int		count;

	count = stack_a_size(stack);
	nd = stack->head_a;
	while (count-- > 0)
		digit_1_pb(4, 5, stack);
	count = stack_a_size(stack);
	while (count-- > 0)
		digit_1_pb(3, 6, stack);
	count = stack_a_size(stack);
	while (count-- > 0)
		digit_1_pb(2, 7, stack);
	count = stack_a_size(stack);
	while (count-- > 0)
		digit_1_pb(1, 8, stack);
	count = stack_a_size(stack);
	while (count-- > 0)
		digit_1_pb(0, 9, stack);
	//while (1)
	//{
	//	if (stack->head_a == NULL)
	//		break ;
	//	printf("🎁check node stack_a *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_a, stack->head_a->num, stack->head_a->rank, stack->head_a->prev, stack->head_a->next);
	//	stack->head_a = stack->head_a->next;
	//}
	//while (1)
	//{
	//	if (stack->head_b == NULL)
	//		break ;
	//	printf("💭check node stack_b *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_b, stack->head_b->num, stack->head_b->rank, stack->head_b->prev, stack->head_b->next);
	//	stack->head_b = stack->head_b->next;
	//}
}

//void	digit_10_pa(int num1, int num2, t_stack *stack)
//{
//	t_node *nd;

//	nd = stack->head_b;
//	if (nd->rank / 10 == num1 || nd->rank / 10 == num2)
//	{
//		pa(stack);
//		if (nd->rank / 10 == num2)
//			ra(stack);
//	}
//	else
//		rb(stack);
//}

void	digit_10_pa(int num, t_stack *stack)
{
	t_node	*nd;

	nd = stack->head_b;
	if (nd->rank / 10 == num)
		pa(stack);
	else
		rb(stack);
}

//void	digit_10_pa(int num, int num1, int num2, t_stack *stack)
//{
//	t_node	*nd;
//	int		i;

//	nd = stack->head_b;
//	//printf("num[%d]\n", nd->rank/10);
//	printf("num1 [%d], num2 [%d] nd->rank/10[%d]\n", num1, num2, nd->rank / 10);
//	i = 0;
//	//if (num2 == (num - 1))
//	if (num == 100)
//	{
//		while (stack->head_b != NULL)
//		{
//			pa(stack);
//			i++;
//		}
//		while (i > 0)
//		{
//			ra(stack);
//			i--;
//		}
//	}
//	else
//	{
//		if (nd->rank / 10 == num1 || nd->rank / 10 == num2)
//		{
//			pa(stack);
//			if (nd->rank / 10 == num2)
//				ra(stack);
//		}
//		else
//			rb(stack);
//	}
//}

void	digit_10(int arg_num, t_stack *stack)
{
	//t_node	*nd;
	int		count;
	int		num; //何種類の10の位が存在するのか
	//int		num1;
	//int		num2;

	num = arg_num / 10;
	while (num >= 0)
	{
		count = stack_b_size(stack);
		while (count > 0)
		{
			digit_10_pa(num, stack);
			count--;
		}
		num--;
	}
	//count = stack_b_size(stack);
	////nd = stack->head_b;
	//while (count-- > 0)
	//	digit_10_pa(4, 5, stack);
	//count = stack_b_size(stack);
	//while (count-- > 0)
	//	digit_10_pa(3, 6, stack);
	//count = stack_b_size(stack);
	//while (count-- > 0)
	//	digit_10_pa(2, 7, stack);
	//count = stack_b_size(stack);
	//while (count-- > 0)
	//	digit_10_pa(1, 8, stack);
	//count = stack_b_size(stack);
	//while (count-- > 0)
	//	digit_10_pa(0, 9, stack);
	//while (1)
	//{
	//	if (stack->head_a == NULL)
	//		break ;
	//	printf("🎁check node stack_a *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_a, stack->head_a->num, stack->head_a->rank, stack->head_a->prev, stack->head_a->next);
	//	stack->head_a = stack->head_a->next;
	//}
	//while (1)
	//{
	//	if (stack->head_b == NULL)
	//		break ;
	//	printf("💭check node stack_b *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_b, stack->head_b->num, stack->head_b->rank, stack->head_b->prev, stack->head_b->next);
	//	stack->head_b = stack->head_b->next;
	//}
}

//void	digit_10(int arg_num, t_stack *stack)
//{
//	//t_node	*nd;
//	int		count;
//	int		num; //何種類の10の位が存在するのか
//	int		num1;
//	int		num2;

//	num = arg_num / 10 + 1;
//	printf("💓digit_10 num[%d]\n", num);
//	if (num % 2 == 0)
//	{
//		num1 = (num / 2) - 1;
//		num2 = num / 2;
//	}
//	else
//	{
//		num1 = ((num - 1) / 2) - 1;
//		num2 = (num - 1) / 2;
//	}
//	printf("💓digit_10 num1[%d]\n", num1);
//	printf("💓digit_10 num2[%d]\n", num2);
//	while (num2 < num)
//	{
//		printf("💭digit_10 num[%d]\n", num);
//		printf("💭digit_10 num1[%d]\n", num1);
//		printf("💭digit_10 num2[%d]\n", num2);
//		count = stack_b_size(stack);
//		while (count > 0)
//		{
//			if (num1 == 0)
//				digit_10_pa(num, num1, 1, stack);
//			else
//				digit_10_pa(num, num1, num2, stack);
//			count--;
//		}
//		num1--;
//		num2++;
//	}
//	//count = stack_b_size(stack);
//	////nd = stack->head_b;
//	//while (count-- > 0)
//	//	digit_10_pa(4, 5, stack);
//	//count = stack_b_size(stack);
//	//while (count-- > 0)
//	//	digit_10_pa(3, 6, stack);
//	//count = stack_b_size(stack);
//	//while (count-- > 0)
//	//	digit_10_pa(2, 7, stack);
//	//count = stack_b_size(stack);
//	//while (count-- > 0)
//	//	digit_10_pa(1, 8, stack);
//	//count = stack_b_size(stack);
//	//while (count-- > 0)
//	//	digit_10_pa(0, 9, stack);
//	while (1)
//	{
//		if (stack->head_a == NULL)
//			break ;
//		printf("🎁check node stack_a *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_a, stack->head_a->num, stack->head_a->rank, stack->head_a->prev, stack->head_a->next);
//		stack->head_a = stack->head_a->next;
//	}
//	while (1)
//	{
//		if (stack->head_b == NULL)
//			break ;
//		printf("💭check node stack_b *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_b, stack->head_b->num, stack->head_b->rank, stack->head_b->prev, stack->head_b->next);
//		stack->head_b = stack->head_b->next;
//	}
//}

//void	digit_10_pa(int num, int num1, int num2, t_stack *stack)
//{
//	t_node	*nd;
//	int		i;

//	nd = stack->head_b;
//	//printf("num[%d]\n", nd->rank/10);
//	printf("num1 [%d], num2 [%d] nd->rank/10[%d]\n", num1, num2, nd->rank / 10);
//	i = 0;
//	//if (num2 == (num - 1))
//	if (num == 100)
//	{
//		while (stack->head_b != NULL)
//		{
//			pa(stack);
//			i++;
//		}
//		while (i > 0)
//		{
//			ra(stack);
//			i--;
//		}
//	}
//	else
//	{
//		if (nd->rank / 10 == num1 || nd->rank / 10 == num2)
//		{
//			pa(stack);
//			if (nd->rank / 10 == num2)
//				ra(stack);
//		}
//		else
//			rb(stack);
//	}
//}


void	sort_100(int arg_num, t_stack *stack)
{
	digit_1(stack);
	digit_10(arg_num, stack);
}