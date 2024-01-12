/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:07 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/12 14:19:08 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa, sb, ss
//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
//ss : sa and sb at the same time.

void	sort_2(t_stack *stack, char c)
{
	t_node	*nd;
	int		num1;
	int		num2;

	if (c == 'a')
		nd = stack->head_a;
	else
		nd = stack->head_b;
	num1 = nd->num;
	num2 = nd->next->num;
	if (num1 < num2)
		return ;
	else
		swap(stack, c);
}

void	sort(int arg_num, t_stack *stack)
{
	if (arg_num == 2)
		sort_2(stack, 'a');
	else if (arg_num == 3)
		sort_3(stack, 'a');
	else if (arg_num == 4)
		sort_4(stack, 'a');
	else if (arg_num == 5)
		sort_5(arg_num, stack, 'a');
	else
		return ;
		//sort_many(arg_num, stack, 'a');
}
