/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:25:04 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 17:30:33 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_5a(int arg_num, t_stack *stack)
{
	t_node	*nd;
	t_node	*min;
	t_node	*second;
	int		count;

	count = 0;
	nd = stack->head_a;
	min = find_min_node(stack, 'a');
	second = find_second_min_node(stack, 'a', min);
	while (arg_num > 0 && count < 2)
	{
		if (nd->rank == min->rank || nd->rank == second->rank)
		{
			push(stack, 'b');
			count++;
		}
		else
			rotate(stack, 'a');
		nd = stack->head_a;
		arg_num--;
	}
}

static void	sort_5b(int arg_num, t_stack *stack)
{
	t_node	*nd;
	t_node	*min;
	t_node	*second;
	int		count;

	count = 0;
	nd = stack->head_b;
	min = find_min_node(stack, 'b');
	second = find_second_min_node(stack, 'b', min);
	while (arg_num > 0 && count < 2)
	{
		if (nd->rank == min->rank || nd->rank == second->rank)
		{
			push(stack, 'a');
			count++;
		}
		else
			rotate(stack, 'b');
		nd = stack->head_b;
		arg_num--;
	}
}

static void	sort_5b_rev(int arg_num, t_stack *stack)
{
	t_node	*nd;
	t_node	*max;
	t_node	*second;
	int		count;

	count = 0;
	nd = stack->head_b;
	max = find_max_node(stack, 'b');
	second = find_second_max_node(stack, 'b', max);
	while (arg_num > 0 && count < 2)
	{
		if (nd->rank == max->rank || nd->rank == second->rank)
		{
			push(stack, 'a');
			count++;
		}
		else
			rotate(stack, 'b');
		nd = stack->head_b;
		arg_num--;
	}
}

void	sort_5(int arg_num, t_stack *stack, char c)
{
	t_node	*nd;

	arg_num = 5;
	if (c == 'a')
		sort_5a(5, stack);
	else
		sort_5b(5, stack);
	sort_3(stack, c);
	push(stack, c);
	push(stack, c);
	nd = stack->head_a;
	if (nd->rank > nd->next->rank)
		swap(stack, c);
}

void	sort_5_rev(int arg_num, t_stack *stack, char c)
{
	t_node	*nd;

	arg_num = 5;
	if (c == 'a')
		ft_putstr_fd("🚨ERROR🚨:sort_5_rev not exit 'a'\n", 1);
	else
		sort_5b_rev(5, stack);
	sort_3_rev(stack, 'b');
	push(stack, 'b');
	push(stack, 'b');
	nd = stack->head_b;
	if (nd->rank > nd->next->rank)
		swap(stack, 'b');
}

//void	sort_5a_rev(int arg_num, t_stack *stack)
//{
//	t_node	*nd;
//	int		count;

//	count = 0;
//	nd = stack->head_a;
//	while (arg_num > 0 && count < 2)
//	{
//		if (nd->rank == 3 || nd->rank == 4)
//		{
//			push(stack, 'b');
//			count++;
//		}
//		else
//			rotate(stack, 'a');
//		nd = stack->head_a;
//		arg_num--;
//	}
//	sort_3_rev(stack, 'a');
//	push(stack, 'a');
//	push(stack, 'a');
//	nd = stack->head_a;
//	if (nd->rank < nd->next->rank)
//		swap(stack, 'a');
//	return ;
//}