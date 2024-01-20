/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:10:35 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/20 19:20:45 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*last_nd(t_stack *stack, char c)
{
	t_node	*nd;

	if (c == 'a')
		nd = stack->head_a;
	else
		nd = stack->head_b;
	while (nd->next != NULL)
		nd = nd->next;
	return (nd);
}

int	node_position(t_stack *stack, t_node *node, char c)
{
	int		pos;
	t_node	*rel_nd;

	if (c == 'a')
		rel_nd = stack->head_a;
	else
		rel_nd = stack->head_b;
	pos = 0;
	while (rel_nd != node && rel_nd->next != NULL)
	{
		rel_nd = rel_nd->next;
		pos++;
	}
	return (pos);
}

t_node	*find_a_pos(t_stack *stack)
{
	int		b;
	t_node	*a_pos;

	b = stack->head_b->rank;
	a_pos = stack->head_a;
	a_pos = find_next_min_node(stack, 'a', stack->head_b);
	return (a_pos);
}

t_node	*find_b_pos(t_stack *stack)
{
	int		a;
	t_node	*b_pos;

	a = stack->head_a->rank;
	b_pos = stack->head_b;
	b_pos = find_next_max_node(stack, 'b', stack->head_a);
	return (b_pos);
}

int	find_pos(t_stack *stack, t_node *max, char c)
{
	int		count;
	t_node	*nd;

	count = 0;
	if (c == 'a')
		nd = stack->head_a;
	else
		nd = stack->head_b;
	while (nd->rank != max->rank)
	{
		nd = nd->next;
		count++;
	}
	return (count);
}
