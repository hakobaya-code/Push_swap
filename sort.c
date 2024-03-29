/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:07 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/20 19:26:05 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack, char c)
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
	if (num1 < num2)
		return ;
	else
		swap(stack, c);
}

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

void	sort(int arg_num, t_stack *stack)
{
	check_sorted(stack);
	if (arg_num == 2)
		sort_2(stack, 'a');
	else if (arg_num == 3)
		sort_3(stack, 'a');
	else if (arg_num == 4)
		sort_4(stack, 'a');
	else if (arg_num == 5)
		sort_5(arg_num, stack, 'a');
	else
		sort_many(arg_num, stack);
}
