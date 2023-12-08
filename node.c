/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:23:23 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/08 18:01:27 by hakobaya         ###   ########.fr       */
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

t_node	*initialize_list(int num)
{
	t_node	*first_node;

	first_node = (t_node *)malloc(sizeof(t_node));
	if (!first_node)
		return (NULL);
	first_node->num = num;
	first_node->next = NULL;
	first_node->prev = NULL;
	return (first_node);
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

void	*add_node(t_node *node, int num)
{
	t_node	*nd;
	t_node	*new_nd;

	if (node == NULL)
		return (NULL);
	new_nd = (t_node *)malloc(sizeof(t_node));
	if (!new_nd)
		return (NULL);
	nd = last_node(node);
	new_nd->num = num;
	nd->next = new_nd;
	new_nd->next = NULL;
	new_nd->prev = nd;
	//printf("💚nd:[%p]\n nd->num:[%d]\n nd->next:[%p]\n nd->prev:[%p],\n", nd, nd->num, nd->next, nd->prev);
	//printf("💛new_nd:[%p]\n new_nd->num:[%d]\n new_nd->next:[%p]\n new_nd->prev:[%p],\n", new_nd, new_nd->num, new_nd->next, new_nd->prev);
	nd = new_nd;
	//printf("💜nd->num:[%d]\n nd->next:[%p]\n nd->prev:[%p],\n", nd->num, nd->next, nd->prev);
	return (NULL);
}
