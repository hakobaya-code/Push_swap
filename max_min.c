/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:20:00 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 17:20:53 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min_node(t_stack *stack, char c)
{
	t_node	*nd;
	t_node	*min_nd;

	if (c == 'a')
	{
		nd = stack->head_a;
		min_nd = stack->head_a;
	}
	else
	{
		nd = stack->head_b;
		min_nd = stack->head_b;
	}
	while (nd->next != NULL)
	{
		if (min_nd->rank > nd->next->rank)
			min_nd = nd->next;
		nd = nd->next;
	}
	return (min_nd);
}

t_node	*find_second_min_node(t_stack *stack, char c, t_node *min)
{
	t_node	*nd;
	t_node	*second;

	if (c == 'a')
		second = stack->head_a;
	else
		second = stack->head_b;
	if (min->rank == second->rank)
		second = second->next;
	nd = second;
	while (nd->next != NULL)
	{
		if ((second->rank > nd->next->rank) && (nd->next->rank != min->rank))
			second = nd->next;
		nd = nd->next;
	}
	return (second);
}

t_node	*find_max_node(t_stack *stack, char c)
{
	t_node	*nd;
	t_node	*max_nd;

	if (c == 'a')
	{
		nd = stack->head_a;
		max_nd = stack->head_a;
	}
	else
	{
		nd = stack->head_b;
		max_nd = stack->head_b;
	}
	while (nd->next != NULL)
	{
		if (max_nd->rank < nd->next->rank)
			max_nd = nd->next;
		nd = nd->next;
	}
	return (max_nd);
}

t_node	*find_second_max_node(t_stack *stack, char c, t_node *max)
{
	t_node	*nd;
	t_node	*second;

	if (c == 'a')
		second = stack->head_a;
	else
		second = stack->head_b;
	if (max->rank == second->rank)
		second = second->next;
	nd = second;
	while (nd->next != NULL)
	{
		if ((second->rank < nd->next->rank) && (nd->next->rank != max->rank))
			second = nd->next;
		nd = nd->next;
	}
	return (second);
}
