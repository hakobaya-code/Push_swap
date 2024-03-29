/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:23:23 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/20 19:41:53 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*initialize_list(int num)
{
	t_node	*first_node;

	first_node = (t_node *)malloc(sizeof(t_node));
	if (!first_node)
		exit(1);
	first_node->num = num;
	first_node->next = NULL;
	first_node->prev = NULL;
	first_node->rank = 0;
	return (first_node);
}

t_node	*initialize_stackb(void)
{
	t_node	*first_node;

	first_node = (t_node *)malloc(sizeof(t_node));
	if (!first_node)
		exit(1);
	first_node->next = NULL;
	first_node->prev = NULL;
	return (first_node);
}

t_node	*last_node(t_node *node)
{
	if (node == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	*add_node(t_node *node, int num)
{
	t_node	*nd;
	t_node	*new_nd;

	if (node == NULL)
		return (NULL);
	new_nd = (t_node *)malloc(sizeof(t_node));
	if (!new_nd)
		exit(1);
	nd = last_node(node);
	new_nd->num = num;
	new_nd->rank = 0;
	nd->next = new_nd;
	new_nd->next = NULL;
	new_nd->prev = nd;
	nd = new_nd;
	return (NULL);
}
