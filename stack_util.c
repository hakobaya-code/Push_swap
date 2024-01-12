/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:09:24 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 14:09:41 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack, char c)
{
	int		size;
	t_node	*nd;

	size = 1;
	if (c == 'a')
		nd = stack->head_a;
	else
		nd = stack->head_b;
	while (nd->next != NULL)
	{
		nd = nd->next;
		size++;
	}
	return (size);
}

