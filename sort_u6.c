/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:25:04 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/07 17:59:15 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*min_node(t_node *head_a, int *index)
{
	t_node	*min_node;
	t_node	*nd1;
	t_node	*nd2;
	int		i;

	i = 0;
	nd1 = head_a;
	nd2 = head_a->next;
	min_node = head_a;
	while (nd2->next != NULL)
	{
		if (nd1->num > nd2->num)
		{
			min_node = nd2->num;
			index = i;
		}
		nd1 = nd2;
		nd2 = nd2->next;
		i++;
	}
	return (min_node);
}

void	sort_4(t_node *head_a, t_node *head_b)
{
	int		index;
	t_node	*m_node;

	index = 0;
	m_node = min_node(head_a, &index);
	if (index != 3)
	{
		while (head_a->prev != NULL)
			sa(m_node->prev);
	}
	else
		rra(head_a);
	pb(head_a);
	sort_3(head_a);
	return ;
}

void	sort_5(t_node *head_a, t_node *head_b)
{
	int		index;
	t_node	*m_node;

	index = 0;
	m_node = min_node(head_a, &index);
	if (index < 3)
	{
		while (head_a->prev != NULL)
			sa(m_node->prev);
	}
	else
	{
		while (m_node->next != NULL)
			sa(m_node);
		rra(head_a);
	}
	pb(head_a);
	sort_4(head_a, head_b);
	return ;
}

void	sort_6(t_node *head_a, t_node *head_b)
{
	int		index;
	t_node	*m_node;

	index = 0;
	m_node = min_node(head_a, &index);
	if (index < 4)
	{
		while (head_a->prev != NULL)
			sa(m_node->prev);
	}
	else
	{
		while (m_node->next != NULL)
			sa(m_node);
		rra(head_a);
	}
	pb(head_a);
	sort_5(head_a, head_b);
	return ;
}

void	sort_u6(int arg_num, t_node *head_a, t_node *head_b)
{
	if (arg_num < 4 && arg_num > 6)
		return ;
	if (arg_num == 4)
		sort_4(head_a, head_b);
	else if (arg_num == 5)
		sort_5(head_a, head_b);
	else
		sort_6(head_a, head_b);
	return ;
}