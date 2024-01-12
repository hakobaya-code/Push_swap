/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:02 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 18:53:23 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_a == NULL || stack->head_a->next == NULL)
		return ;
	nd1 = stack->head_a;
	nd2 = last_nd(stack, 'a');
	stack->head_a = nd1->next;
	nd1->next->prev = NULL;
	nd1->prev = nd2;
	nd1->next = NULL;
	nd2->next = nd1;
	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	//printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_a, head_a->num, head_a->prev, head_a->next);

}

static void	rb(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_b == NULL || stack->head_b->next == NULL)
		return ;
	nd1 = stack->head_b;
	nd2 = last_nd(stack, 'b');
	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd1->next [%p] num[%d] prev[%p] next[%p]\n", nd1->next, nd1->next->num, nd1->next->prev, nd1->next->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	nd1->next->prev = NULL;
	stack->head_b = nd1->next;
	nd1->prev = nd2;
	nd1->next = NULL;
	nd2->next = nd1;
	//printf("💛nd1 [%p] num[%d] prev[%p] next[%p]\n", nd1, nd1->num, nd1->prev, nd1->next);
	//printf("💛nd2 [%p] num[%d] prev[%p] next[%p]\n", nd2, nd2->num, nd2->prev, nd2->next);
	//printf("💛head_a [%p] num[%d] prev[%p] next[%p]\n", head_b, head_b->num, head_b->prev, head_b->next);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_putstr_fd("rr\n", 1);
}

void	rotate(t_stack *stack, char c)
{
	if (c == 'a')
	{
		ra(stack);
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		rb(stack);
		ft_putstr_fd("rb\n", 1);
	}
}
