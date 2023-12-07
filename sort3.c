/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:06:05 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/07 17:21:28 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_132(t_node *head_a)
{
	rra();
	sa();
	return ;
}

void	sort_321(t_node *head_a)
{
	ra();
	sa();
}

void	sort_3(t_node *head_a)
{
	t_node	*nd1;
	t_node	*nd2;
	t_node	*nd3;

	nd1 = head_a;
	nd2 = head_a->next;
	nd3 = head_a->next->next;
	if (nd1->num < nd2->num && nd2->num < nd3->num)
		return ;
	else if (nd1->num < nd3->num && nd2->num > nd3->num)
		sort_132(head_a);
	else if (nd1->num < nd2->num && nd2->num < nd3->num)
		sa(head_a);
	else if (nd1->num > nd2->num && nd1->num < nd3->num)
		rra(head_a);
	else if (nd1->num > nd3->num && nd2->num < nd3->num)
		ra();
	else
		sort_321(head_a);
	return ;
}
