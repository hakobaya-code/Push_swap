/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:26:48 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/14 19:16:22 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_5_b_other(t_stack *stack)
{
	t_node	*nd;
	t_node	*rank_5;
	int		count;

	nd = stack->head_a;
	rank_5 = find_max_node(stack, 'a');
	//printf("rank[%d]\n", rank_5->rank);
	count = 4;
	while (count-- > 0)
		rank_5 = find_next_max_node(stack, 'a', rank_5);
	while (stack_size(stack, 'a') > 5)
	{
		if (nd->rank < rank_5->rank)
			push(stack, 'b');
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}

void	b_5_and_pa_ra(t_stack *stack)
{
	t_node	*nd;
	t_node	*rank_5;
	int		count;

	nd = stack->head_b;
	rank_5 = find_min_node(stack, 'b');
	//printf("rank[%d]\n", rank_5->rank);
	count = 4;
	while (count-- > 0)
	{
		rank_5 = find_next_min_node(stack, 'b', rank_5);
		//printf("rank[%d]\n", rank_5->rank);
	}
	while (stack_size(stack, 'b') > 5)
	{
		if (nd->rank > rank_5->rank)
			push(stack, 'a');
		else
			rotate(stack, 'b');
		nd = stack->head_b;
	}
	sort_5(5, stack, 'b');
	count = 5;
	while (count-- > 0)
	{
		push(stack, 'a');
		rotate(stack, 'a');
	}
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
