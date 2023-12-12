/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:42:15 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/12 17:04:37 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_a == NULL || stack->head_a->next == NULL)
		return ;
	nd1 = stack->head_a;
	nd2 = stack->head_a->next;
	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->next = nd2->next;
	nd1->prev = nd2;
	nd2->next->prev = nd1;
	nd2->next = nd1;
	nd2->prev = NULL;
	//printf("💜nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💜nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	//printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	stack->head_a = nd2;
	//printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_b == NULL || stack->head_b->next == NULL)
		return ;
	nd1 = stack->head_b;
	nd2 = stack->head_b->next;
	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->next = nd2->next;
	nd1->prev = nd2;
	nd2->next->prev = nd1;
	nd2->next = nd1;
	nd2->prev = NULL;
	//printf("💜nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💜nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	stack->head_b = nd2;
	//printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	ft_putstr_fd("ss\n", 1);
}
