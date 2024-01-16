/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:02:35 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 20:04:31 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min_node_until_rank0(t_stack *stack)
{
	t_node	*nd;
	t_node	*min_nd;

	min_nd = stack->head_a;
	nd = stack->head_a;
	while (nd->next->rank != 0)
	{
		if (min_nd->rank > nd->next->rank)
			min_nd = nd->next;
		nd = nd->next;
	}
	return (min_nd);
}

t_node	*find_next_min_node_until_rank0(t_stack *stack, t_node *min)
{
	t_node	*nd;
	t_node	*second;

	second = stack->head_a;
	while (min->rank >= second->rank && (second->next->rank != 0))
		second = second->next;
	nd = second;
	while (nd->next->rank != 0)
	{
		if ((second->rank > nd->next->rank) && (nd->next->rank > min->rank))
			second = nd->next;
		nd = nd->next;
	}
	return (second);
}
