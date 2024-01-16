/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:04:00 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 08:05:46 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node *nd)
{
	t_node	*next_nd;
	t_node	*free_nd;

	if (nd == NULL)
	{
		free(nd);
		nd = NULL;
		return ;
	}
	next_nd = nd->next;
	while (next_nd->next != NULL)
	{
		free_nd = nd;
		nd = next_nd;
		next_nd = next_nd->next;
		free(free_nd);
		free_nd = NULL;
	}
	free(nd);
	free(next_nd);
	nd = NULL;
	next_nd = NULL;
}

void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	free_node(stack->head_a);
	free_node(stack->head_b);
	free(stack);
	stack = NULL;
}
