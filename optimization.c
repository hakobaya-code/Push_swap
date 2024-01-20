/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:58:41 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/20 19:21:01 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opt(t_stack *stack, int a, int a_prev)
{
	t_node	*nd;
	int		b;
	int		b_next;
	int		ret;

	nd = stack->head_b;
	b = nd->rank;
	if (stack_size(stack, 'b') > 1)
		b_next = nd->next->rank;
	else
		return (1);
	if (b_next > b && b_next > a_prev && b_next < a)
	{
		swap(stack, 'b');
		ret = insert_chunk(stack, last_nd(stack, 'a')->rank);
		return (ret);
	}
	else
		return (1);
}

int	count_a_rotate(t_stack *stack)
{
	int		half;
	int		count;
	t_node	*top_a;
	t_node	*nd;
	t_node	*top_b;

	half = (stack_size(stack, 'a') / 2) + 1;
	top_b = stack->head_b;
	top_a = find_next_min_node(stack, 'a', top_b);
	nd = stack->head_a;
	count = 0;
	while (nd->rank != top_a->rank)
	{
		count++;
		nd = nd->next;
	}
	if (count > half)
		count = stack_size(stack, 'a') - count + 1;
	else
		count = count - 1;
	return (count);
}

int	count_b_rotate(t_stack *stack)
{
	int		half;
	int		count;
	t_node	*max_b;
	t_node	*nd;

	nd = stack->head_b;
	half = (stack_size(stack, 'b') / 2) + 1;
	max_b = find_max_node(stack, 'b');
	count = 0;
	while (nd->rank != max_b->rank)
	{
		count++;
		nd = nd->next;
	}
	if (count > half)
		count = stack_size(stack, 'a') - count + 1;
	else
		count = count - 1;
	return (count);
}

char	count_operations(t_stack *stack)
{
	int		count_a;
	int		count_b;

	count_a = count_a_rotate(stack);
	count_b = count_b_rotate(stack);
	if (count_a == 0)
		return ('b');
	else if (count_a >= count_b)
		return ('b');
	else
		return ('a');
}

void	opt_rrb(t_stack *stack)
{
	t_node	*nd;
	int		rrb_count;

	nd = last_node(stack->head_b);
	rrb_count = 1;
	while (nd->rank < nd->prev->rank)
	{
		nd = nd->prev;
		rrb_count++;
	}
	while (rrb_count-- > 0)
		rev_rotate(stack, 'b');
}
