/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haruka <haruka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:06:05 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/13 18:55:45 by haruka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_132(t_stack *stack)
{
	rra(stack);
	sa(stack);
	return ;
}

void	sort_321(t_stack *stack)
{
	ra(stack);
	sa(stack);
}

void	sort_3(t_stack *stack)
{
	t_node	*nd;
	int		num1;
	int		num2;
	int		num3;

	nd = stack->head_a->next;
	num1 = nd->prev->num;
	num2 = nd->num;
	num3 = nd->next->num;
	if (num1 < num2 && num2 < num3) // 123
		return ;
	else if (num1 < num3 && num2 > num3) // 132
		sort_132(stack);
	else if (num2 < num1 && num1 < num3) // 213
		sa(stack);
	else if (num1 < num2 && num1 > num3) // 231
		rra(stack);
	else if (num1 > num2 && num2 < num3) // 312
		ra(stack);
	else
		sort_321(stack); // 321
	return ;
}
