/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:07:42 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/07 16:33:53 by hakobaya         ###   ########.fr       */
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
	t_node	*node1;
	t_node	*node2;

	node1 = head_a;
	node2 = head_b;

	node1->next = node2;
	node2->prev = node1;
}

void	pb(t_node *head_a, t_node *head_b)
{
	t_node	*node1;
	t_node	*node2;

	node1 = head_b;
	node2 = head_a;

	node1->next = node2;
	node2->prev = node1;
}
