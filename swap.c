/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:42:15 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 20:25:10 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_a == NULL || stack->head_a->next == NULL)
		return ;
	nd1 = stack->head_a;
	nd2 = stack->head_a->next;
	nd1->prev = nd2;
	if (nd2->next != NULL)
	{
		nd1->next = nd2->next;
		nd2->next->prev = nd1;
	}
	else
		nd1->next = NULL;
	nd2->next = nd1;
	nd2->prev = NULL;
	stack->head_a = nd2;
}

static void	sb(t_stack *stack)
{
	t_node	*nd1;
	t_node	*nd2;

	if (stack->head_b == NULL || stack->head_b->next == NULL)
		return ;
	nd1 = stack->head_b;
	nd2 = stack->head_b->next;
	nd1->prev = nd2;
	if (nd2->next != NULL)
	{
		nd1->next = nd2->next;
		nd2->next->prev = nd1;
	}
	else
		nd1->next = NULL;
	nd2->next = nd1;
	nd2->prev = NULL;
	stack->head_b = nd2;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	ft_putstr_fd("ss\n", 1);
}

void	swap(t_stack *stack, char c)
{
	if (c == 'a')
	{
		sa(stack);
		ft_putstr_fd("sa\n", 1);
	}
	else
	{
		sb(stack);
		ft_putstr_fd("sb\n", 1);
	}
}
