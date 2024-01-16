/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_middle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:14:07 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 19:45:59 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min5_pb(t_stack *stack, int unsorted, int min5)
{
	t_node	*nd;
	int		r_count;
	int		pb_count;

	nd = stack->head_a;
	r_count = 0;
	pb_count = 0;
	while (unsorted-- > 0 && pb_count < 5)
	{
		if (nd->rank <= min5)
		{
			push(stack, 'b');
			pb_count++;
		}
		else
		{
			rotate(stack, 'a');
			r_count++;
		}
		nd = stack->head_a;
	}
	return (r_count);
}

int	unsorted_min5(t_stack *stack, int unsorted)
{
	t_node	*min5;
	int		size;
	int		count;

	size = unsorted;
	count = 4;
	min5 = find_min_node_until_rank0(stack);
	while (count > 0)
	{
		min5 = find_next_min_node_until_rank0(stack, min5);
		count--;
	}
	return (min5->rank);
}

void	sort_middle(t_stack *stack, int unsorted)
{
	int	r_count;
	int	min5;

	min5 = unsorted_min5(stack, unsorted);
	r_count = min5_pb(stack, unsorted, min5);
	while (r_count-- > 0)
		rev_rotate(stack, 'a');
	if (stack_size(stack, 'b') > 5)
		b_5_and_pa_ra(5, stack);
	else
		stack_b_under_5(stack);
}
