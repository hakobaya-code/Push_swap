/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:25:04 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 14:35:43 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_stack *stack, char c)
{
	t_node	*min_node;
	int		pos;

	min_node = find_min_node(stack, c);
	pos = node_position(stack, min_node, c);
	top_push(4, pos, stack, c);
	sort_3(stack, c);
	push(stack, c);
	return ;
}

void	sort_5a(int arg_num, t_stack *stack)
{
	t_node	*nd;
	int		count;

	count = 0;
	nd = stack->head_a;
	while (arg_num > 0 && count < 2)
	{
		if (nd->rank == 0 || nd->rank == 1)
		{
			push(stack, 'b');
			count++;
		}
		else
			rotate(stack, 'a');
		nd = stack->head_a;
		arg_num--;
	}
	sort_3(stack, 'a');
	push(stack, 'a');
	push(stack, 'a');
	nd = stack->head_a;
	if (nd->rank > nd->next->rank)
		swap(stack, 'a');
	return ;
}

void	sort_5b(int arg_num, t_stack *stack)
{
	t_node	*nd;
	int		count;

	count = 0;
	nd = stack->head_b;
	while (arg_num > 0 && count < 2)
	{
		if (nd->rank == 0 || nd->rank == 1)
		{
			push(stack, 'a');
			count++;
		}
		else
			rotate(stack, 'b');
		nd = stack->head_b;
		arg_num--;
	}
	sort_3(stack, 'b');
	push(stack, 'b');
	push(stack, 'b');
	nd = stack->head_b;
	if (nd->rank > nd->next->rank)
		swap(stack, 'b');
	return ;
}

void	sort_5(int arg_num, t_stack *stack, char c)
{
	if (c == 'a')
		sort_5a(arg_num, stack);
	else
		sort_5b(arg_num, stack);
}



//void	sort_5_2(t_stack *stack, int min, int min2)
//{
//	t_node	*nd;
//	t_node	*ld;

//	nd = stack->head_a;
//	ld = last_nd(stack);
//	if (nd->next->rank == min || nd->next->rank == min2)
//		ra(stack);
//	else if (nd->next->next->rank == min || nd->next->next->rank == min2)
//	{
//		ra(stack);
//		ra(stack);
//	}
//	else if (ld->rank == min || ld->rank == min2)
//		rra(stack);
//	else if (ld->prev->rank == min || ld->prev->rank == min2)
//	{
//		rra(stack);
//		rra(stack);
//	}
//	return ;
//}

//void	sort_5(int arg_num, t_stack *stack)
//{
//	int		min;
//	int		min2;

//	min = calc_min(stack);
//	min2 = calc_second_min(stack, min);
//	sort_5_2(stack, min, min2);
//	pb(stack);
//	sort_4(arg_num, stack);
//	pa(stack);
//	return ;
//}

//void	sort_6(int arg_num, t_stack *stack, char c)
//{
//	t_node	*nd;
//	int		count;

//	if (c == 'a')
//		nd = stack->head_a;
//	else
//		nd = stack->head_b;
//	count = 0;
//	while (arg_num > 0 && count < 3)
//	{
//		if (nd->rank == 0 || nd->rank == 1 || nd->rank == 2)
//		{
//			pb(stack);
//			count++;
//		}
//		ra(stack);
//		arg_num--;
//		nd = stack->head_a;
//	}
//	sort_3_rev(stack, c);
//	sort_3(stack, c);
//	pa(stack);
//	pa(stack);
//	pa(stack);
//	return ;
//}

//void	sort_6(int arg_num, t_stack *stack)
//{
//	t_node	*nd;
//	t_node	*ld;

//	nd = stack->head_a->next;
//	ld = last_nd(stack);
//	if (nd->rank == 0 || nd->rank == 1 || nd->rank == 2)
//		ra(stack);
//	else if (nd->next->rank == 0 || nd->next->rank == 1 || nd->next->rank == 2)
//	{
//		ra(stack);
//		ra(stack);
//	}
//	else if (ld->rank == 0 || ld->rank == 1 || ld->rank == 2)
//		rra(stack);
//	else if (ld->prev->rank == 0 || ld->prev->rank == 1 || ld->prev->rank == 2)
//	{
//		rra(stack);
//		rra(stack);
//	}
//	pb(stack);
//	sort_5(arg_num, stack);
//	pa(stack);
//	return ;
//}

//void	sort_u6(int arg_num, t_stack *stack, char c)
//{
//	if (arg_num == 4)
//		sort_4(stack, c);
//	else if (arg_num == 5)
//		sort_5(5, stack, c);
//	else if (arg_num == 6)
//		sort_6(6, stack, c);
//	return ;
//}
