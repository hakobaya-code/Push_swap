/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:06:09 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 14:33:25 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	top_push_a(int arg_num, int pos, t_stack *stack)
{
	int	i;

	i = 0;
	if (arg_num - pos >= pos)
	{
		while (i < pos)
		{
			while (i < pos)
			{
				rotate(stack, 'a');
				i++;
			}
		}
	}
	else
	{
		while (i < arg_num - pos)
		{
			rev_rotate(stack, 'a');
			i++;
		}
	}
	push(stack, 'b');
	return ;
}

void	top_push_b(int arg_num, int pos, t_stack *stack)
{
	int	i;

	i = 0;
	if (arg_num - pos >= pos)
	{
		while (i < pos)
		{
			while (i < pos)
			{
				rotate(stack, 'b');
				i++;
			}
		}
	}
	else
	{
		while (i < arg_num - pos)
		{
			rev_rotate(stack, 'b');
			i++;
		}
	}
	push(stack, 'a');
	return ;
}

void	top_push(int arg_num, int pos, t_stack *stack, char c)
{
	if (c == 'a')
		top_push_a(arg_num, pos, stack);
	else
		top_push_b(arg_num, pos, stack);
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
