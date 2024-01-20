/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:06:09 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/20 19:27:29 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_push_a(int arg_num, int pos, t_stack *stack)
{
	int	i;

	i = 0;
	if (arg_num - pos >= pos)
	{
		while (i < pos)
		{
			while (i < pos)
			{
				rotate(stack, 'a');
				i++;
			}
		}
	}
	else
	{
		while (i < arg_num - pos)
		{
			rev_rotate(stack, 'a');
			i++;
		}
	}
	push(stack, 'b');
	return ;
}

void	top_push_b(int arg_num, int pos, t_stack *stack)
{
	int	i;

	i = 0;
	if (arg_num - pos >= pos)
	{
		while (i < pos)
		{
			while (i < pos)
			{
				rotate(stack, 'b');
				i++;
			}
		}
	}
	else
	{
		while (i < arg_num - pos)
		{
			rev_rotate(stack, 'b');
			i++;
		}
	}
	push(stack, 'a');
	return ;
}

void	top_push(int arg_num, int pos, t_stack *stack, char c)
{
	if (c == 'a')
		top_push_a(arg_num, pos, stack);
	else
		top_push_b(arg_num, pos, stack);
}

t_node	*max_5(t_stack *stack)
{
	t_node	*nd;
	t_node	*rank_5;
	int		count;

	nd = stack->head_a;
	rank_5 = find_max_node(stack, 'a');
	count = 4;
	while (count-- > 0)
		rank_5 = find_next_max_node(stack, 'a', rank_5);
	return (rank_5);
}

int	stack_size(t_stack *stack, char c)
{
	int		size;
	t_node	*nd;

	size = 1;
	if (c == 'a')
		nd = stack->head_a;
	else
		nd = stack->head_b;
	while (nd->next != NULL)
	{
		nd = nd->next;
		size++;
	}
	return (size);
}
