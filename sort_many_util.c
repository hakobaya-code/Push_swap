/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:26:48 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 20:17:27 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_5_b_other(int arg_num, t_stack *stack)
{
	t_node	*nd;
	t_node	*rank_5;
	int		count;

	nd = stack->head_a;
	rank_5 = find_max_node(stack, 'a');
	count = 4;
	while (count-- > 0)
		rank_5 = find_next_max_node(stack, 'a', rank_5);
	while (stack_size(stack, 'a') > 5)
	{
		if (nd->rank < rank_5->rank)
		{
			push(stack, 'b');
			if (nd->rank < (arg_num / 2))
				rotate(stack, 'b');
		}
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}

void	b_5_and_pa_ra(int arg_num, t_stack *stack)
{
	t_node	*nd;
	t_node	*rank_5;
	int		count;

	nd = stack->head_b;
	rank_5 = find_max_node(stack, 'b');
	count = 4;
	while (count-- > 0)
		rank_5 = find_next_max_node(stack, 'b', rank_5);
	while (stack_size(stack, 'b') > 5)
	{
		if (nd->rank < rank_5->rank)
			push(stack, 'a');
		else
			rotate(stack, 'b');
		nd = stack->head_b;
	}
	sort_5_rev(stack, 'b');
	arg_num = 1;
}

int	unsorted_num(t_stack *stack)
{
	t_node	*nd;
	int		count;

	nd = stack->head_a;
	count = 0;
	while (nd->rank != 0)
	{
		count++;
		nd = nd->next;
	}
	return (count);
}

t_node	*rank_0_pos(t_stack *stack)
{
	t_node	*nd;

	nd = stack->head_a;
	while (nd->next != NULL)
	{
		if (nd->rank == 0)
			return (nd);
		nd = nd->next;
	}
	exit(1);
}

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
