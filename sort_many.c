/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:21:50 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/11 20:06:57 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	half(int arg_num, t_stack *stack)
{
	t_node	*nd;
	int		half_num;

	nd = stack->head_a;
	if (arg_num % 2 == 1)
		half_num = (arg_num + 1) / 2;
	else
		half_num = arg_num / 2;
	if (nd->rank >= half_num)
		return (1);
	else
		return (0);
}

void	start_half(int arg_num, t_stack *stack)
{
	t_node	*nd;
	t_node	*end;
	int		i;

	i = 0;
	nd = stack->head_a;
	end = last_nd(stack);
	while (i < arg_num)
	{
		if (half(arg_num, stack) == 1)
			pb(stack);
		else
			ra(stack);
		i++;
	}
}

int	stack_a_size(t_stack *stack)
{
	int		size;
	t_node	*nd;

	size = 1;
	nd = stack->head_a;
	while (nd->next != NULL)
	{
		nd = nd->next;
		size++;
	}
	return (size);
}

int	stack_b_size(t_stack *stack)
{
	int		size;
	t_node	*nd;

	size = 1;
	nd = stack->head_b;
	while (nd->next != NULL)
	{
		nd = nd->next;
		size++;
	}
	return (size);
}


//void	sort_100(int arg_num, t_stack *stack)
//{
//	return ;
//}

void	sort_many(int arg_num, t_stack *stack)
{
	int	size;

	size = stack_a_size(stack);
	//printf("size[%d]\n", size);
	//printf("arg_num[%d]\n", arg_num);
	if (arg_num <= 10)
		sort_10(arg_num, stack);
	if (arg_num <= 100)
		sort_100(arg_num, stack);
	return ;
}
