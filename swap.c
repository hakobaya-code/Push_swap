/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:42:15 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/09 17:17:25 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sa(t_node *head_a)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_a;
	nd2 = head_a->next;
	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->next = nd2->next;
	nd1->prev = nd2;
	nd2->next->prev = nd1;
	nd2->next = nd1;
	nd2->prev = NULL;
	//printf("💜nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💜nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	head_a = nd2;
	//printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	ft_putstr_fd("sa\n", 1);
	return (head_a);
}

t_node	*sb(t_node *head_b)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_b;
	nd2 = head_b->next;
	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->next = nd2->next;
	nd1->prev = nd2;
	nd2->next->prev = nd1;
	nd2->next = nd1;
	nd2->prev = NULL;
	//printf("💜nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💜nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	head_b = nd2;
	//printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	ft_putstr_fd("sb\n", 1);
	return (head_b);
}

void	ss(t_node *head_a, t_node *head_b)
{
	sa(head_a);
	sb(head_b);
	ft_putstr_fd("ss\n", 1);
}
