/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:25:04 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/04 18:36:00 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_top_and_push(int arg_num, int pos, t_stack *stack)
{
	int	i;

	i = 0;
	printf("🌟arg_num[%d]\n", arg_num);
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
		if (nd->rank > nd->next->rank)
			min_nd = nd->next;
		nd = nd->next;
	}
	return (min_nd);
}

void	sort_u6(int arg_num, t_stack *stack)
{
	t_node	*min_node;
	t_node	*nd;
	int		pos;
	int		count;

	printf("enter sort_u6\n");
	min_node = stack->head_a;
	nd = stack->head_a;
	pos = 0;
	count = 0;
	while (arg_num - 3 > 0)
	{
		printf("😆arg_num[%d]\n", arg_num);
		min_node = find_min_node(stack);
		pos = node_position(stack, min_node);
		printf("min_node_num[%d] pos[%d]\n", min_node->num, pos);
		to_top_and_push(arg_num, pos, stack);
		count++;
		arg_num--;
		printf("💭check node stack_a *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_a, stack->head_a->num, stack->head_a->rank, stack->head_a->prev, stack->head_a->next);
		if (stack->head_b != NULL)
			printf("💭check node stack_b *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_b, stack->head_b->num, stack->head_b->rank, stack->head_b->prev, stack->head_b->next);
	}
	sort_3(stack);
	while (count > 0)
	{
		pa(stack);
		count--;
	}
	printf("💓check node stack_a *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_a, stack->head_a->num, stack->head_a->rank, stack->head_a->prev, stack->head_a->next);
	if (stack->head_b != NULL)
		printf("💓check node stack_b *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_b, stack->head_b->num, stack->head_b->rank, stack->head_b->prev, stack->head_b->next);
	return ;
}
