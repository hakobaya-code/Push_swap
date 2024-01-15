/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:06:05 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/15 21:58:46 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_r(t_stack *stack, char c)
{
	swap(stack, c);
	rotate(stack, c);
}

void	r_s(t_stack *stack, char c)
{
	rotate(stack, c);
	swap(stack, c);

}

void	sort_3(t_stack *stack, char c)
{
	t_node	*nd;
	int		num1;
	int		num2;
	int		num3;

	if (c == 'a')
		nd = stack->head_a->next;
	else
		nd = stack->head_b->next;
	num1 = nd->prev->rank;
	num2 = nd->rank;
	num3 = nd->next->rank;
	//printf("enter sort_3\n");
	if (num1 < num2 && num2 < num3) // 123
		return ;
	else if (num1 < num3 && num2 > num3) // 132
		s_r(stack, c);
	else if (num2 < num1 && num1 < num3) // 213
		swap(stack, c);
	else if (num1 < num2 && num1 > num3) // 231
		rev_rotate(stack, c);
	else if (num1 > num2 && num2 < num3) // 312
		rotate(stack, c);
	else if (num1 > num2 && num2 > num3)
		r_s(stack, c); // 321
}

void	sort_3_rev(t_stack *stack, char c)
{
	t_node	*nd;
	int		num1;
	int		num2;
	int		num3;

	if (c == 'a')
		nd = stack->head_a->next;
	else
		nd = stack->head_b->next;
	num1 = nd->prev->rank;
	num2 = nd->rank;
	num3 = nd->next->rank;
	if (num1 < num2 && num2 < num3) // 123
		r_s(stack, c);
	else if (num1 < num3 && num2 > num3) // 132
		rotate(stack, c);
	else if (num2 < num1 && num1 < num3) // 213
		rev_rotate(stack, c);
	else if (num1 < num2 && num1 > num3) // 231
		swap(stack, c);
	else if (num1 > num2 && num2 < num3) // 312
		s_r(stack, c);
	else if (num1 > num2 && num2 > num3)
		return ; // 321
}
