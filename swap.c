/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:42:15 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/07 16:45:19 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *head_a)
{
	t_node	*node1;
	t_node	*node2;

	node1 = head_a;
	node2 = head_a->next;
	node1->next = node2->next;
	node2->next = head_a;
	node1->prev = node2;
	node2->prev = NULL;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node *head_b)
{
	t_node	*node1;
	t_node	*node2;

	node1 = head_b;
	node2 = head_b->next;
	node1->next = node2->next;
	node2->next = head_b;
	node1->prev = node2;
	node2->prev = NULL;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node *head_a, t_node *head_b)
{
	sa(head_a);
	sb(head_b);
	ft_putstr_fd("ss\n", 1);
}
