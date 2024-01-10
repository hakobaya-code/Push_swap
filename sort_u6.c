/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:25:04 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/10 17:10:23 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(int arg_num, t_stack *stack)
{
	t_node	*min_node;
	int		pos;

	min_node = find_min_node(stack);
	pos = node_position(stack, min_node);
	top_push(4, pos, stack);
	sort_3(stack);
	if (arg_num == 5)
		sort_2b(stack);
	else if (arg_num == 6)
		sort_3b(stack);
	pa(stack);
	return ;
}

void	sort_5_2(t_stack *stack, int min, int min2)
{
	t_node	*nd;
	t_node	*ld;

	nd = stack->head_a;
	ld = last_nd(stack);
	if (nd->next->rank == min || nd->next->rank == min2)
		ra(stack);
	else if (nd->next->next->rank == min || nd->next->next->rank == min2)
	{
		ra(stack);
		ra(stack);
	}
	else if (ld->rank == min || ld->rank == min2)
		rra(stack);
	else if (ld->prev->rank == min || ld->prev->rank == min2)
	{
		rra(stack);
		rra(stack);
	}
	return ;
}

void	sort_5(int arg_num, t_stack *stack)
{
	int		min;
	int		min2;

	min = calc_min(stack);
	min2 = calc_second_min(stack, min);
	sort_5_2(stack, min, min2);
	pb(stack);
	sort_4(arg_num, stack);
	pa(stack);
	return ;
}

void	sort_6(int arg_num, t_stack *stack)
{
	t_node	*nd;
	t_node	*ld;

	nd = stack->head_a->next;
	ld = last_nd(stack);
	if (nd->rank == 0 || nd->rank == 1 || nd->rank == 2)
		ra(stack);
	else if (nd->next->rank == 0 || nd->next->rank == 1 || nd->next->rank == 2)
	{
		ra(stack);
		ra(stack);
	}
	else if (ld->rank == 0 || ld->rank == 1 || ld->rank == 2)
		rra(stack);
	else if (ld->prev->rank == 0 || ld->prev->rank == 1 || ld->prev->rank == 2)
	{
		rra(stack);
		rra(stack);
	}
	pb(stack);
	sort_5(arg_num, stack);
	pa(stack);
	return ;
}

void	sort_u6(int arg_num, t_stack *stack)
{
	t_node	*min_node;
	t_node	*nd;
	int		pos;
	int		count;

	min_node = stack->head_a;
	nd = stack->head_a;
	pos = 0;
	count = 0;
	if (arg_num == 4)
		sort_4(4, stack);
	else if (arg_num == 5)
		sort_5(5, stack);
	else if (arg_num == 6)
		sort_6(6, stack);
	return ;
}

	//printf("💓check node stack_a *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_a, stack->head_a->num, stack->head_a->rank, stack->head_a->prev, stack->head_a->next);
	//if (stack->head_b != NULL)
	//	printf("💓check node stack_b *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_b, stack->head_b->num, stack->head_b->rank, stack->head_b->prev, stack->head_b->next);