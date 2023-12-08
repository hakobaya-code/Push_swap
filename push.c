/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:07:42 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/08 11:20:10 by hakobaya         ###   ########.fr       */
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
	nd1->next = nd2;
	nd2->prev = nd1;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node *head_a, t_node *head_b)
{
	t_node	*nd1;
	t_node	*nd2;

	nd1 = head_b;
	nd2 = head_a;
	nd1->next = nd2;
	nd2->prev = nd1;
	ft_putstr_fd("pb\n", 1);
}




//#include <stdio.h>
//#include <libc.h>

//int	main(int argc, char **argv)
//{
//	t_node	*head_a;
//	t_node
//}
