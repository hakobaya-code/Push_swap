/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:21:50 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 22:12:19 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_pos(t_stack *stack, int unsorted, int percent)
{
	int		size;
	int		size_3;
	t_node	*nd;

	size = unsorted;
	nd = find_min_node(stack, 'a');
	size_3 = size * percent / 3;
	while (size_3 > 0)
	{
		nd = find_next_min_node(stack, 'a', nd);
		size_3--;
	}
	return (nd->rank);
}

void	divide_3(t_stack *stack, int big, int small)
{
	t_node	*nd;
	int		size;

	nd = stack->head_a;
	size = stack_size(stack, 'a');
	while (size-- > 0)
	{
		if (nd->rank / 20 == small)
		{
			push(stack, 'b');
			rotate(stack, 'b');
		}
		else if (nd->rank / 20 == big)
			push(stack, 'b');
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}

void	divide_group(int arg_num, t_stack *stack)
{
	int	group;
	int	big;
	int	small;

	group = arg_num / 20;
	big = (group / 2);
	small = (group / 2) - 1;
	while (big < group - 1)
	{
		divide_3(stack, big, small);
		big++;
		small--;
	}
}

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

void	sort_many(int arg_num, t_stack *stack)
{
	t_node	*nd;

	divide_group(arg_num, stack);
	if (stack->head_a != NULL && stack_size(stack, 'a') > 5)
		a_5_b_other(arg_num, stack);
	sort_mini(stack_size(stack, 'a'), stack);
	first_insert(stack);
	nd = stack->head_b;
	while (stack->head_b != NULL)
		insert(stack);
	check_sort(stack);
}
