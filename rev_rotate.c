/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:17:46 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 20:10:15 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rra(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_a == NULL || stack->head_a->next == NULL)
		return ;
	nd1 = stack->head_a;
	nd2 = last_nd(stack, 'a');
	nd2->prev->next = NULL;
	nd1->prev = nd2;
	nd2->prev = NULL;
	nd2->next = nd1;
	stack->head_a = nd2;
}

static void	rrb(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_b == NULL || stack->head_b->next == NULL)
		return ;
	nd1 = stack->head_b;
	nd2 = last_nd(stack, 'b');
	nd2->prev->next = NULL;
	nd1->prev = nd2;
	nd2->prev = NULL;
	nd2->next = nd1;
	stack->head_b = nd2;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_putstr_fd("rrr\n", 1);
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
