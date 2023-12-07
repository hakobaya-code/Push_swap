/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:23:23 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/07 15:23:49 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_argv(char *argv)
{
	while (++argv)
	{
		if (!(ft_isdigit(argv)))
		{
			//error_notdigit();
			return (1);
		}
	}
	return (0);
}

int	*make_array(char *argv)
{
	int	*array;
	int	check;
	int	i;

	i = 0;
	check = check_argv(argv);
	if (check == 1)
		return (0);
	while (++argv)
	{
		array[i] = ft_atoi(argv);
		i++;
	}
	return (array);
}

t_node	*initialize_list(void)
{
	t_node	*list;

	list = (t_node *)malloc(sizeof(t_node));
	if (!list)
		return (NULL);
	list->num = NULL;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

//t_node	*make_list(t_node list)
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

void	*add_list(t_node *list, int num)
{
	t_node	*nd;
	t_node	*new_nd;

	if (list == NULL)
		return ;
	new_nd = (t_node *)malloc(sizeof(t_node));
	if (!new_nd)
		return (NULL);
	nd = last_node(list);
	new_nd->num = num;
	new_nd->next = NULL;
	new_nd->prev = nd;
}