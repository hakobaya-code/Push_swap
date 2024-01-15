/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:55:33 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 00:11:29 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_rev(t_stack *stack, char c)
{
	t_node	*nd;
	int		num1;
	int		num2;

	if (c == 'a')
		nd = stack->head_a;
	else
		nd = stack->head_b;
	num1 = nd->num;
	num2 = nd->next->num;
	if (num1 > num2)
		return ;
	else
		swap(stack, c);
}

void	sort_3_rev(t_stack *stack, char c)
{
	t_node	*nd;
	int		num1;
	int		num2;
	int		num3;

	if (c == 'a')
		nd = stack->head_a->next;
	else
		nd = stack->head_b->next;
	num1 = nd->prev->rank;
	num2 = nd->rank;
	num3 = nd->next->rank;
	if (num1 < num2 && num2 < num3) // 123
		r_s(stack, c);
	else if (num1 < num3 && num2 > num3) // 132
		rotate(stack, c);
	else if (num2 < num1 && num1 < num3) // 213
		rev_rotate(stack, c);
	else if (num1 < num2 && num1 > num3) // 231
		swap(stack, c);
	else if (num1 > num2 && num2 < num3) // 312
		s_r(stack, c);
	else if (num1 > num2 && num2 > num3)
		return ; // 321
}

void	sort_4_rev(t_stack *stack, char c)
{
	t_node	*max_node;
	int		pos;

	max_node = find_max_node(stack, c);
	pos = node_position(stack, max_node, c);
	top_push(4, pos, stack, c);
	sort_3_rev(stack, c);
	push(stack, c);
	return ;
}

void	sort_5_rev(t_stack *stack, char c)
{
	t_node	*nd;

	if (c == 'a')
		ft_putstr_fd("🚨ERROR🚨:sort_5_rev not exit 'a'\n", 1);
	else
		sort_5b_rev(5, stack);
	sort_3_rev(stack, 'b');
	push(stack, 'b');
	push(stack, 'b');
	if (c == 'a')
		nd = stack->head_a;
	else
		nd = stack->head_b;
	if (nd->rank < nd->next->rank)
		swap(stack, 'b');
}

void	sort_rev(int arg_num, t_stack *stack, char c)
{
	if (arg_num == 1)
		return ;
	if (arg_num == 2)
		sort_2_rev(stack, c);
	if (arg_num == 3)
		sort_3_rev(stack, c);
	if (arg_num == 4)
		sort_4_rev(stack, c);
	if (arg_num == 5)
		sort_5_rev(stack, c);
	return ;
}