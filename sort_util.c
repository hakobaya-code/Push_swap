/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:06:09 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/04 22:08:05 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*last_nd(t_stack *stack)
{
	t_node	*nd;

	nd = stack->head_a;
	while (nd->next != NULL)
		nd = nd->next;
	return (nd);
}

void	top_push(int arg_num, int pos, t_stack *stack)
{
	int	i;

	i = 0;
	if (arg_num - pos >= pos)
	{
		while (i < pos)
		{
			while (i < pos)
			{
				ra(stack);
				i++;
			}
		}
	}
	else
	{
		while (i < arg_num - pos)
		{
			rra(stack);
			i++;
		}
	}
	pb(stack);
	return ;
}


int	node_position(t_stack *stack, t_node *node)
{
	int		pos;
	t_node	*rel_nd;

	pos = 0;
	rel_nd = stack->head_a;
	while (rel_nd != node && rel_nd->next != NULL)
	{
		rel_nd = rel_nd->next;
		pos++;
	}
	return (pos);
}

t_node	*find_min_node(t_stack *stack)
{
	t_node	*nd;
	t_node	*min_nd;

	nd = stack->head_a;
	min_nd = stack->head_a;
	while (nd->next != NULL)
	{
		if (min_nd->rank > nd->next->rank)
			min_nd = nd->next;
		nd = nd->next;
	}
	return (min_nd);
}

