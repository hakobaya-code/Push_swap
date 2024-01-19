/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:21:50 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/19 19:15:28 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_mini(int arg_num, t_stack *stack)
{
	if (arg_num == 0 || arg_num == 1)
		return ;
	if (arg_num == 2)
		sort_2(stack, 'a');
	if (arg_num == 3)
		sort_3(stack, 'a');
	if (arg_num == 4)
		sort_4(stack, 'a');
	if (arg_num == 5)
		sort_5(5, stack, 'a');
}

int	divide_pos(t_stack *stack, int unsorted, int percent)
{
	int		size;
	int		size_3;
	t_node	*nd;

	size = unsorted;
	nd = find_min_node(stack, 'a');
	size_3 = size * percent / 3;
	while (size_3 > 0)
	{
		nd = find_next_min_node(stack, 'a', nd);
		size_3--;
	}
	return (nd->rank);
}

//void	divide_3(t_stack *stack, int big, int small)
//{
//	t_node	*nd;
//	int		size;

//	nd = stack->head_a;
//	size = stack_size(stack, 'a');
//	while (size-- > 0)
//	{
//		if (nd->rank / 20 == small)
//		{
//			push(stack, 'b');
//			rotate(stack, 'b');
//		}
//		else if (nd->rank / 20 == big)
//			push(stack, 'b');
//		else
//			rotate(stack, 'a');
//		nd = stack->head_a;
//	}
//}

void	rr_judge(t_stack *stack, t_node *nd, int big, int small)
{
	int	rank;

	rank = nd->next->rank;
	if (rank / 10 != big || rank / 10 != small)
	{
		push(stack, 'b');
		rr(stack);
	}
	else
	{
		push(stack, 'b');
		rotate(stack, 'a');
	}
}

void	divide(t_stack *stack, int big, int small)
{
	t_node	*nd;
	int		count;

	nd = stack->head_a;
	count = 0;
	while (stack_size(stack, 'a') > 5 && count < 20)
	{
		if (nd->rank >= max_5(stack)->rank)
			rotate(stack, 'a');
		else if (nd->rank / 10 == small)
		{
			rr_judge(stack, nd, big, small);
			count++;
		}
		else if (nd->rank / 10 == big)
		{
			push(stack, 'b');
			count++;
		}
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}

void	divide_500(t_stack *stack, int big, int small)
{
	t_node	*nd;
	int		count;

	nd = stack->head_a;
	count = 0;
	while (stack_size(stack, 'a') > 5 && count < 40)
	{
		if (nd->rank >= max_5(stack)->rank)
			rotate(stack, 'a');
		else if (nd->rank / 20 == small)
		{
			push(stack, 'b');
			rotate(stack, 'b');
			count++;
		}
		else if (nd->rank / 20 == big)
		{
			push(stack, 'b');
			count++;
		}
		else
			rotate(stack, 'a');
		nd = stack->head_a;
	}
}
//void	divide_group(int arg_num, t_stack *stack)
//{
//	int	group;
//	int	big;
//	int	small;

//	group = arg_num / 20;
//	big = (group / 2);
//	small = (group / 2) - 1;
//	while (big < group - 1)
//	{
//		divide_3(stack, big, small);
//		big++;
//		small--;
//	}
//}

void	divide_group(int arg_num, t_stack *stack)
{
	int	group;
	int	count;

	group = arg_num / 10;
	count = 0;
	while (stack_size(stack, 'a') >= 5)
	{
		divide(stack, count + 1, count);
		count += 2;
		if (stack_size(stack, 'a') <= 5)
			return ;
	}
}

void	divide_group_500(int arg_num, t_stack *stack)
{
	int	group;
	int	count;

	group = arg_num / 20;
	count = 0;
	while (stack_size(stack, 'a') >= 5)
	{
		divide(stack, count + 1, count);
		count += 2;
		if (stack_size(stack, 'a') <= 5)
			return ;
	}
}
void	sort_many(int arg_num, t_stack *stack)
{
	t_node	*nd;

	//if (arg_num > 300)
	//	divide_group_500(arg_num, stack);
	//else
	divide_group(arg_num, stack);
	sort_mini(stack_size(stack, 'a'), stack);
	//first_insert(stack);
	//nd = stack->head_b;
	//while (stack->head_b != NULL)
	//	choice(stack);
	//printf("sort_many after sort_5\n");
	nd = stack->head_b;
	while (nd != NULL)
	{
		choice(stack);
		nd = stack->head_b;
	}
	check_sort(stack);
}
