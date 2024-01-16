/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:02 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 20:11:15 by hakobaya         ###   ########.fr       */
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
}

static void	rb(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_b == NULL || stack->head_b->next == NULL)
		return ;
	nd1 = stack->head_b;
	nd2 = last_nd(stack, 'b');
	nd1->next->prev = NULL;
	stack->head_b = nd1->next;
	nd1->prev = nd2;
	nd1->next = NULL;
	nd2->next = nd1;
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
