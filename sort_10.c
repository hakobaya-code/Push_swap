/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:28 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 20:12:51 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_15(int arg_num, t_stack *stack)
{
	int	count;
	int	size;

	a_5_b_other(arg_num, stack);
	sort_5(5, stack, 'a');
	b_5_and_pa_ra(arg_num, stack);
	while ((arg_num - 10) > 0)
	{
		push(stack, 'b');
		rotate(stack, 'b');
		arg_num--;
	}
	count = 5;
	while (count-- > 0)
		push(stack, 'a');
	if (stack->head_b == NULL)
		return ;
	size = stack_size(stack, 'b');
	sort_rev(size, stack, 'b');
	while (size-- > 0)
		push(stack, 'a');
}

void	sort_10_6(t_stack *stack)
{
	t_node	*nd;
	int		count;

	nd = stack->head_a;
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
	return ;
}
