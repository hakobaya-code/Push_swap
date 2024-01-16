/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:10:35 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/16 20:08:44 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*last_nd(t_stack *stack, char c)
{
	t_node	*nd;

	if (c == 'a')
		nd = stack->head_a;
	else
		nd = stack->head_b;
	while (nd->next != NULL)
		nd = nd->next;
	return (nd);
}

int	calc_min(t_stack *stack)
{
	int		min;
	t_node	*nd;

	nd = stack->head_a;
	min = nd->rank;
	while (nd->next != NULL)
	{
		if (min > nd->next->rank)
			min = nd->next->rank;
		nd = nd ->next;
	}
	return (min);
}

int	calc_second_min(t_stack *stack, int min)
{
	int		second_min;
	t_node	*nd;

	nd = stack->head_a;
	second_min = nd->rank;
	if (second_min == min)
		second_min = nd->next->rank;
	while (nd->next != NULL)
	{
		if (second_min > nd->next->rank && nd->next->rank != min)
			second_min = nd->next->rank;
		nd = nd->next;
	}
	return (second_min);
}
