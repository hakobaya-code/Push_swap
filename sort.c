/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:07 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/12 16:55:56 by hakobaya         ###   ########.fr       */
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
	if (stack->head_a->num < stack->head_a->next->num)
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
	printf("💜after sotr_2\n");
	//else (arg_num == 3)
	//{
	//	sort_3(stack);
	//}
	//else if (arg_num <= 6)
	//{
	//	//なんか処理する
	//}
	//else
	//{
	//	//なんか処理する
	//}
}
