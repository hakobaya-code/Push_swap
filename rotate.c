/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:02 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/10 17:28:44 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra, rb, rr, rra, rrb, rrr

//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.
//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.
//rr : ra and rb at the same time.
//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
//rrr : rra and rrb at the same time.

t_node	*list_last(t_node *list)
{
	if (list == NULL)
		return (list);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_node	*ra(t_node *head_a)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_a;
	nd2 = list_last(head_a);
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	printf("💛nd1->next [%p] num[%d] prev[%p] next[%p]\n", nd1->next, nd1->next->num, nd1->next->prev, nd1->next->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->next->prev = NULL;
	head_a = nd1->next;
	nd1->prev = nd2;
	nd1->next = NULL;
	nd2->next = nd1;
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	ft_putstr_fd("ra\n", 1);
	return (head_a);
}

t_node	*rb(t_node *head_b)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_b;
	nd2 = list_last(head_b);
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	printf("💛nd1->next [%p] num[%d] prev[%p] next[%p]\n", nd1->next, nd1->next->num, nd1->next->prev, nd1->next->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->next->prev = NULL;
	head_b = nd1->next;
	nd1->prev = nd2;
	nd1->next = NULL;
	nd2->next = nd1;
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_b, head_b->num, head_b->prev, head_b->next);
	ft_putstr_fd("ra\n", 1);
	return (head_b);
}



t_node	*rra(t_node *head_a)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_a;
	nd2 = list_last(head_a);
	nd2->prev->next = NULL;
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	printf("💛nd2->prev [%p] num[%d] prev[%p] next[%p]\n", nd2->prev->next, nd2->prev->num, nd2->prev->prev, nd2->prev->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->prev = nd2;
	nd2->prev = NULL;
	nd2->next = nd1;
	head_a = nd2;
	ft_putstr_fd("rra\n", 1);
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	return (head_a);
}

t_node	*rrb(t_node *head_b)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_b;
	nd2 = list_last(head_b);
	nd2->prev->next = NULL;
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	printf("💛nd2->prev [%p] num[%d] prev[%p] next[%p]\n", nd2->prev->next, nd2->prev->num, nd2->prev->prev, nd2->prev->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->prev = nd2;
	nd2->prev = NULL;
	nd2->next = nd1;
	head_b = nd2;
	ft_putstr_fd("rrb\n", 1);
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_b, head_b->num, head_b->prev, head_b->next);
	return (head_b);
}
