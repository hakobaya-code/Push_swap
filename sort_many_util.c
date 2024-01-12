/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:26:48 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 18:15:16 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_5_b_other(t_stack *stack)
{
	t_node	*nd;
	t_node	*rank_5;
	int		count;

	nd = stack->head_a;
	rank_5 = find_max_node(stack, 'a');
	//printf("rank[%d]\n", rank_5->rank);
	count = 4;
	while (count-- > 0)
		rank_5 = find_next_max_node(stack, 'a', rank_5);
	while (stack_size(stack, 'a') > 5)
	{
		if (nd->rank < rank_5->rank)
			push(stack, 'b');
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}
