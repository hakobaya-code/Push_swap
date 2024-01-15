/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:25:36 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/15 22:44:45 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_notdigit(void)
{
	ft_putstr_fd("🚨ERROR🚨: ARGV IS NOT DIGIT !!\n", 1);
	exit(1);
}

//int	error_argc(void)
//{
//	ft_putstr_fd("🚨ERROR🚨:AT LEAST TWO ARGUMENTS ARE REQUIRED.\n", 1);
//	return (1);
//}

void	error_overint(void)
{
	ft_putstr_fd("🚨ERROR🚨: ARGV IS OVER INT\n", 1);
	exit(1);
}
//void	error_sortnum(void)
//{
//	ft_putstr_fd("🚨ERROR🚨: SORT NUMBER IS NOT CORRECT\n", 1);
//	exit(1);
//}

void	error_same_num(int *array)
{
	ft_putstr_fd("🚨ERROR🚨: THE SAME NUMBERS ARE INCLUDED\n", 1);
	free(array);
	exit(1);
}

void	check_sorted(t_stack *stack)
{
	t_node	*nd;

	nd = stack->head_a;
	while (nd->next != NULL)
	{
		if (nd->rank < nd->next->rank)
			nd = nd->next;
		else
			return ;
	}
	ft_putstr_fd("🚨ERROR🚨: ALREADY SORTED\n", 1);
	exit(1);
}
