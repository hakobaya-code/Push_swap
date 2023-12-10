/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:37:52 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/10 17:24:02 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <libc.h>

int	main(int argc, char **argv)
{
	int		index;
	int		*array;
	t_node	*nd;
	t_node	*list;

	index = 0;
	if (argc < 2)
		return (error_argc());
	printf("hello\n");
	array = make_array(argc - 1, argv);
	list = initialize_list(array[index]);
	printf("initialize [%p]\n", list);
	while (index < argc - 2)
	{
		index++;
		nd = add_node(list, array[index]);
	}
	printf("NODE: 🙆‍♀️add_node done.\n");
	free(array);
	printf("list head %p, prev %p, next %p, num %d\n", list, list->prev, list->next, list->num);
	list = rra(list);
	printf("list head %p, prev %p, next %p, num %d\n", list, list->prev, list->next, list->num);
	while (1)
	{
		if (list == NULL)
			break ;
		printf("check node *** node [%p], num [%d], prev [%p], next[%p]\n", list, list->num, list->prev, list->next);
		list = list->next;
	}
	printf("💜end node\n");
	printf("💛end swap\n");
	//sort(argc - 1, list);
	//free();
	return (0);
}


__attribute__((destructor))
static void	destructor()
{
	system("\n\nleaks -q a.out");
}
