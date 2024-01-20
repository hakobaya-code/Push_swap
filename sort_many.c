/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:21:50 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/20 19:05:43 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_mini(int arg_num, t_stack *stack)
{
	if (arg_num == 0 || arg_num == 1)
		return ;
	if (arg_num == 2)
		sort_2(stack, 'a');
	if (arg_num == 3)
		sort_3(stack, 'a');
	if (arg_num == 4)
		sort_4(stack, 'a');
	if (arg_num == 5)
		sort_5(5, stack, 'a');
}

void	rr_judge(t_stack *stack, t_node *nd, int upper)
{
	int	rank;

	rank = nd->next->rank;
	if (rank > upper)
	{
		push(stack, 'b');
		rr(stack);
	}
	else
	{
		push(stack, 'b');
		rotate(stack, 'b');
	}
}

void	divide(t_stack *stack, int group, int upper)
{
	t_node	*nd;
	int		count;
	int		upper_half;

	nd = stack->head_a;
	count = 0;
	upper_half = upper - (group / 2);
	while (stack_size(stack, 'a') > 5 && count != group)
	{
		if (nd->rank >= max_5(stack)->rank)
			rotate(stack, 'a');
		else if (nd->rank < upper_half)
		{
			rr_judge(stack, nd, upper);
			count++;
		}
		else if (nd->rank < upper)
		{
			push(stack, 'b');
			count++;
		}
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}

void	divide_group(int arg_num, t_stack *stack)
{
	int	group;
	int	count;
	int	upper;

	group = arg_num / 5;
	count = 1;
	upper = 0;
	while (stack_size(stack, 'a') >= 5)
	{
		upper = group * count;
		divide(stack, group, upper);
		count++;
		if (stack_size(stack, 'a') <= 5)
			return ;
	}
}

void	sort_many(int arg_num, t_stack *stack)
{
	t_node	*nd;

	divide_group(arg_num, stack);
	sort_mini(stack_size(stack, 'a'), stack);
	nd = stack->head_b;
	while (nd != NULL)
	{
		insert(stack);
		nd = stack->head_b;
	}
	check_sort(stack);
}
