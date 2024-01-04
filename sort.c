/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:07 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/04 17:26:47 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa, sb, ss
//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
//ss : sa and sb at the same time.

void	sort_2(t_stack *stack)
{
	t_node	*nd;
	int		num1;
	int		num2;

	printf("💜enter sort_2\n");
	nd = stack->head_a;
	num1 = nd->num;
	num2 = nd->next->num;
	printf("num1 : %d\n", num1);
	printf("num2 : %d\n", num2);
	if (num1 < num2)
		return ;
	else
		sa(stack);
}



void	sort(int arg_num, t_stack *stack)
{
	printf("💜enter sort\n");
	//printf("💜enter sort\n");
	if (arg_num == 2)
	{
		sort_2(stack);
	}
	else if (arg_num == 3)
	{
		sort_3(stack);
	}
	else if (arg_num <= 6)
	{
		sort_u6(arg_num, stack);
	}
}
