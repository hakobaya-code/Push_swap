/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:06:05 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/10 16:53:04 by hakobaya         ###   ########.fr       */
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
	else if (num1 > num2 && num2 > num3)
		sort_321(stack); // 321
	else
		printf("error sort 3\n");
	return ;
}

void	sort_3b(t_stack *stack)
{
	t_node	*nd;
	int		num1;
	int		num2;
	int		num3;

	nd = stack->head_b->next;
	num1 = nd->prev->num;
	num2 = nd->num;
	num3 = nd->next->num;
	if (num1 < num2 && num2 < num3) // 123
	{
		rb(stack);
		sb(stack);
	}
	else if (num1 < num3 && num2 > num3) // 132
		rb(stack);
	else if (num2 < num1 && num1 < num3) // 213
		rrb(stack);
	else if (num1 < num2 && num1 > num3) // 231
		sb(stack);
	else if (num1 > num2 && num2 < num3) // 312
	{
		rrb(stack);
		sb(stack);
	}
	else if (num1 > num2 && num2 > num3)
		return ; // 321
	else
		printf("error sort 3\n");
	return ;
}