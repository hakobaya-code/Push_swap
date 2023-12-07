/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:02 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/07 16:44:29 by hakobaya         ###   ########.fr       */
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

void	ra(t_node *head_a)
{
	t_node	*node1;
	t_node	*node2;

	node1 = head_a;
	node2 = ft_lstlast(head_a);
	node1->prev = node2->prev;
	node2->prev = NULL;
	node1->next = NULL;
	node2->next = node1;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node *head_b)
{
	t_node	*node1;
	t_node	*node2;

	node1 = head_b;
	node2 = ft_lstlast(head_b);
	node1->prev = node2->prev;
	node2->prev = NULL;
	node1->next = NULL;
	node2->next = node1;
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
	t_node	*node1;
	t_node	*node2;

	node1 = head_a;
	node2 = ft_lstlast(head_a);
	node1->prev = node2->prev;
	node2->prev->next = NULL;
	node2->prev = NULL;
	node2->next = node1;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node *head_b)
{
	t_node	*node1;
	t_node	*node2;

	node1 = head_b;
	node2 = ft_lstlast(head_b);
	node1->prev = node2->prev;
	node2->prev->next = NULL;
	node2->prev = NULL;
	node2->next = node1;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node *head_a, t_node *head_b)
{
	ra(head_a);
	rb(head_b);
	ft_putstr_fd("rrr\n", 1);
}