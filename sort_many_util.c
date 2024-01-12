/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:26:48 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 15:45:27 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_5_b_other(int arg_num, t_stack *stack)
{
	t_node	*nd;
	int		rank_max;

	nd = stack->head_a;
	rank_max = arg_num - 1;
	while (stack_size(stack, 'a') > 5)
	{
		if (nd->rank <= (rank_max - 5))
			push(stack, 'b');
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}
