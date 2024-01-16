/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:58:41 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/17 00:29:38 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opt(t_stack *stack, int a, int a_prev)
{
	t_node	*nd;
	int		b;
	int		b_next;
	int		ret;

	nd = stack->head_b;
	b = nd->rank;
	if (stack_size(stack, 'b') > 1)
		b_next = nd->next->rank;
	else
		return (1);
	if (b_next > b && b_next > a_prev && b_next < a)
	{
		swap(stack, 'b');
		ret = insert_chunk(stack, last_nd(stack, 'a')->rank);
		return (ret);
	}
	else
		return (1);
}
