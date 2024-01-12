/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:17:46 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 13:59:15 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_putstr_fd("rrr\n", 1);
}

void	rra(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_a == NULL || stack->head_a->next == NULL)
		return ;
	nd1 = stack->head_a;
	nd2 = last_nd(stack, 'a');
	nd2->prev->next = NULL;
	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2->prev [%p] num[%d] prev[%p] next[%p]\n", nd2->prev->next, nd2->prev->num, nd2->prev->prev, nd2->prev->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->prev = nd2;
	nd2->prev = NULL;
	nd2->next = nd1;
	stack->head_a = nd2;

	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	//printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
}

void	rrb(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_b == NULL || stack->head_b->next == NULL)
		return ;
	nd1 = stack->head_b;
	nd2 = last_nd(stack, 'b');
	nd2->prev->next = NULL;
	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2->prev [%p] num[%d] prev[%p] next[%p]\n", nd2->prev->next, nd2->prev->num, nd2->prev->prev, nd2->prev->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->prev = nd2;
	nd2->prev = NULL;
	nd2->next = nd1;
	stack->head_b = nd2;
//	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
//	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
//	printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_b, head_b->num, head_b->prev, head_b->next);
}

void	rev_rotate(t_stack *stack, char c)
{
	if (c == 'a')
	{
		rra(stack);
		ft_putstr_fd("rra\n", 1);
	}
	else
	{
		rrb(stack);
		ft_putstr_fd("rrb\n", 1);
	}
}
