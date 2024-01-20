/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:33:30 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/20 19:18:20 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_a_pos(t_stack *stack, t_node *a_pos)
{
	t_node	*nd;
	int		pos;

	nd = stack->head_a;
	pos = 0;
	while (nd->rank != a_pos->rank)
	{
		pos++;
		nd = nd->next;
	}
	nd = stack->head_a;
	while (nd->rank != a_pos->rank)
	{
		if (pos > stack_size(stack, 'a') / 2)
			rev_rotate(stack, 'a');
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}

void	top_b_pos(t_stack *stack, t_node *b_pos)
{
	t_node	*nd;
	int		pos;

	nd = stack->head_b;
	pos = 0;
	while (nd->rank != b_pos->rank)
	{
		pos++;
		nd = nd->next;
	}
	nd = stack->head_b;
	while (nd->rank != b_pos->rank)
	{
		if (pos > stack_size(stack, 'b') / 2)
			rev_rotate(stack, 'b');
		else
			rotate(stack, 'b');
		nd = stack->head_b;
	}
}

int	insert_chunk(t_stack *stack, int a_prev)
{
	t_node	*nd;
	int		b;
	int		b_next;
	int		chunk;

	nd = stack->head_b;
	chunk = 1;
	b = nd->rank;
	if (stack_size(stack, 'b') > 1)
		b_next = nd->next->rank;
	else
		return (1);
	while (nd->next != NULL)
	{
		if (nd->rank > nd->next->rank && nd->next->rank > a_prev)
		{
			nd = nd->next;
			chunk++;
		}
		else
			break ;
	}
	return (chunk);
}

void	insert(t_stack *stack)
{
	t_node	*a_pos;
	t_node	*b_pos;
	t_node	*nd;
	int		pa_count;

	b_pos = find_max_node(stack, 'b');
	top_b_pos(stack, b_pos);
	a_pos = find_a_pos(stack);
	top_a_pos(stack, a_pos);
	pa_count = insert_chunk(stack, last_nd(stack, 'a')->rank);
	if (pa_count == 1)
	{
		nd = stack->head_a;
		pa_count = opt(stack, nd->rank, last_nd(stack, 'a')->rank);
	}
	while (pa_count > 0)
	{
		push(stack, 'a');
		pa_count--;
	}
}
