/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:08:07 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/07 15:22:29 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa, sb, ss
//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
//ss : sa and sb at the same time.

void	sort_2()
{

	return ;
}

void	sort(int arg_num, t_node *list)
{
	if (arg_num == 2)
	{
		sort_2();
	}
	else if (arg_num == 3)
	{
		sort_3();
	}
	else if (arg_num <= 6)
	{
		//なんか処理する
	}
	else
	{
		//なんか処理する
	}
}
