/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:25:36 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/17 01:52:23 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_invalid_args(void)
{
	ft_putstr_fd("🚨ERROR🚨\n", 2);
	exit(1);
}

void	error_same_num(int *array)
{
	ft_putstr_fd("🚨ERROR🚨: THE SAME NUMBERS ARE INCLUDED\n", 2);
	free(array);
	exit(1);
}

void	check_sorted(t_stack *stack)
{
	t_node	*nd;

	if (stack->head_a != NULL)
		nd = stack->head_a;
	else
		return ;
	while (nd->next != NULL)
	{
		if (nd->rank < nd->next->rank)
			nd = nd->next;
		else
			return ;
	}
	if (stack->head_b == NULL)
		exit(1);
}

void	check_sort(t_stack *stack)
{
	t_node	*nd;

	nd = find_max_node(stack, 'a');
	if (nd->rank == last_nd(stack, 'a')->rank)
		return ;
	else
	{
		while (nd->rank != last_nd(stack, 'a')->rank)
			rev_rotate(stack, 'a');
	}
}
