/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:07:47 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/04 22:08:12 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
