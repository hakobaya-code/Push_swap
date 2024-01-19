/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 00:33:30 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/19 19:43:01 by hakobaya         ###   ########.fr       */
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
	//printf("a\n");
	while (nd->rank != b_pos->rank)
	{
		pos++;
		nd = nd->next;
	}
	//printf("b\n");
	nd = stack->head_b;
	while (nd->rank != b_pos->rank)
	{
		if (pos > stack_size(stack, 'b') / 2)
			rev_rotate(stack, 'b');
		else
			rotate(stack, 'b');
		nd = stack->head_b;
		//printf("c\n");
	}
	//printf("d\n");
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

int	insert_chunk(t_stack *stack, int a_prev)
{
	t_node	*nd;
	int		b;
	int		b_next;
	int		chunk;

	//printf("enter insert_chunk\n");
	nd = stack->head_b;
	chunk = 1;
	b = nd->rank;
	if (stack_size(stack, 'b') > 1)
		b_next = nd->next->rank;
	else
		return (1);
	//printf("insert_chunk\n");
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

void	a_rotate_insert(t_stack *stack)
{
	t_node	*a_pos;
	t_node	*nd;
	int		pa_count;

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

void	b_rotate_insert(t_stack *stack)
{
	t_node	*a_pos;
	t_node	*b_pos;
	t_node	*nd;
	int		pa_count;

	//printf("b_rotate_insert\n");
	b_pos = find_max_node(stack, 'b');
	//printf("b_rotate_insert b_pos[%d]\n", b_pos->rank);
	top_b_pos(stack, b_pos);
	//printf("b_rotate_insert top_b_pos passed\n");
	a_pos = find_a_pos(stack);
	//printf("b_rotate_insert a_pos[%d]\n", a_pos->rank);
	top_a_pos(stack, a_pos);
	//printf("b_rotate_insert top_a_pos passed\n");
	pa_count = insert_chunk(stack, last_nd(stack, 'a')->rank);
	//printf("pa_count[%d]\n", pa_count);
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

void	choice(t_stack *stack)
{
	//char	c;

	////printf("choice\n");
	//c = count_operations(stack);
	////printf("choice c[%c]\n", c);
	//if (c == 'a')
	//	a_rotate_insert(stack);
	//else
	b_rotate_insert(stack);
}

//void	first_insert(t_stack *stack)
//{
//	t_node	*nd;
//	int		chunk;

//	nd = stack->head_b;
//	chunk = 1;
//	while (1)
//	{
//		if (nd->rank > nd->next->rank)
//		{
//			nd = nd->next;
//			chunk++;
//		}
//		else
//			break ;
//	}
//	while (chunk > 0)
//	{
//		push(stack, 'a');
//		chunk--;
//	}
//}
