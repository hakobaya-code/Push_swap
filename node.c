/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:23:23 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/08 17:06:50 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!(ft_isdigit(argv[i][0])))
		{
			error_notdigit();
			return (1);
		}
		i++;
	}
	printf("node.c: 🙆‍♀️check_argv done [i]%d\n", i);
	return (0);
}

int	*make_array(int arg_num, char **argv)
{
	int	*array;
	int	check;
	int	i;

	printf("enter make_array\n");
	i = 0;
	check = check_argv(argv);
	if (check == 1)
		exit(1);
	printf("arg_num: %d\n", arg_num);
	array = (int *)malloc(sizeof(int) * arg_num);
	if (!array)
		exit(1);
	while (i < arg_num)
	{
		array[i] = ft_atoi(&argv[i + 1][0]);
		printf("array[%d]:%d\n", i + 1, array[i]);
		i++;
	}
	return (array);
}

t_node	*initialize_stack(void)
{
	t_node	*stack;

	stack = (t_node *)malloc(sizeof(t_node));
	if (!stack)
		return (NULL);
	stack->num = 0;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

//t_node	*make_stack(t_node stack)
//{
//	t_node	*nd;

//	nd = (t_node *)malloc(sizeof(t_node));
//	if (!nd)
//		return (NULL);
//	nd->num = NULL;
//	nd->next = NULL;
//	nd->prev = NULL;
//	return (nd);
//}

t_node	*last_node(t_node *node)
{
	if (node == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	*add_stack(t_node *stack, int num)
{
	t_node	*nd;
	t_node	*new_nd;

	if (stack == NULL)
		return (NULL);
	new_nd = (t_node *)malloc(sizeof(t_node));
	if (!new_nd)
		return (NULL);
	nd = last_node(stack);
	new_nd->num = num;
	new_nd->next = NULL;
	new_nd->prev = nd;
	printf("nd->num:[%d], nd->next:[%p], nd->prev:[%p],\n", new_nd->num, new_nd->next, new_nd->prev);
	return (NULL);
}
