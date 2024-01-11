/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1000.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:50:14 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/11 20:34:13 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	digit_100_pb(int num, t_stack *stack)
{
	t_node	*nd;

	nd = stack->head_a;
	if (nd->rank / 100 == num)
		pb(stack);
	else
		ra(stack);
}

void	digit_100(int arg_num, t_stack *stack)
{
	int	count;
	int	num;
	int	i;

	num = arg_num / 100;
	i = num;
	while (num >= 0)
	{
		count = stack_a_size(stack);
		while (count > 0)
		{
			digit_100_pb(i, stack);
			count--;
		}
		i++;
		num--;
	}
}

void	sort_1000(int arg_num, t_stack *stack)
{
	digit_1(stack);
	digit_10(arg_num, stack);
	digit_100(arg_num, stack);
	//all_pa(stack);
	return ;
}