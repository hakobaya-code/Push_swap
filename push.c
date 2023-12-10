/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:07:42 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/10 17:58:14 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pa, pb
//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.

void	pa(t_node *head_a, t_node *head_b)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_a;
	nd2 = head_b;
	printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2->prev [%p] num[%d] prev[%p] next[%p]\n", nd2->prev->next, nd2->prev->num, nd2->prev->prev, nd2->prev->next);
	printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	head_a = nd1->next;
	printf("💛after head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	head_a->prev = NULL;
	printf("💛after head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);
	if (nd2 == NULL)
	{
		head_b = nd1;
		nd1->next = NULL;
	}
	nd1->next = nd2;
	nd2->prev = nd1;
	head_b = nd1;
	ft_putstr_fd("pa\n", 1);
}

//void	pb(t_node *head_a, t_node *head_b)
//{
//	t_node	*nd1;
//	t_node	*nd2;

//	nd1 = head_b;
//	nd2 = head_a;
//	nd1->next = nd2;
//	nd2->prev = nd1;
//	ft_putstr_fd("pb\n", 1);
//}

//#include <stdio.h>
//#include <libc.h>

//int	main(int argc, char **argv)
//{
//	t_node	*head_a;
//	t_node
//}
