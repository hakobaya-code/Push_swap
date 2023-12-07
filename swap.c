/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:42:15 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/07 17:01:24 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *head_a)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_a;
	nd2 = head_a->next;
	nd1->next = nd2->next;
	nd2->next = head_a;
	nd1->prev = nd2;
	nd2->prev = NULL;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node *head_b)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_b;
	nd2 = head_b->next;
	nd1->next = nd2->next;
	nd2->next = head_b;
	nd1->prev = nd2;
	nd2->prev = NULL;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node *head_a, t_node *head_b)
{
	sa(head_a);
	sb(head_b);
	ft_putstr_fd("ss\n", 1);
}
