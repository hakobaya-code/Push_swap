/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:02 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/09 17:20:18 by hakobaya         ###   ########.fr       */
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

t_node	*ra(t_node *head_a)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_a;
	nd2 = ft_lstlast(head_a);
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->prev = nd2->prev;
	nd2->prev = NULL;
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
	nd2 = ft_lstlast(head_b);
	nd1->prev = nd2->prev;
	nd2->prev = NULL;
	nd1->next = NULL;
	nd2->next = nd1;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node *head_a, t_node *head_b)
{
	ra(head_a);
	rb(head_b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_node *head_a)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_a;
	nd2 = ft_lstlast(head_a);
	nd1->prev = nd2->prev;
	nd2->prev->next = NULL;
	nd2->prev = NULL;
	nd2->next = nd1;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node *head_b)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_b;
	nd2 = ft_lstlast(head_b);
	nd1->prev = nd2->prev;
	nd2->prev->next = NULL;
	nd2->prev = NULL;
	nd2->next = nd1;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node *head_a, t_node *head_b)
{
	ra(head_a);
	rb(head_b);
	ft_putstr_fd("rrr\n", 1);
}