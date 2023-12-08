/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:37:52 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/08 18:00:54 by hakobaya         ###   ########.fr       */
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
	printf("main.c: 🙆‍♀️make_array done!! array:%d, %d, %d\n", array[0], array[1], array[2]);
	list = initialize_list(array[index]);
	printf("initialize [%p]\n", list);
	while (index < argc - 2)
	{
		index++;
		nd = add_node(list, array[index]);
	}
	printf("main.c: 🙆‍♀️add_node done.\n");
	free(array);
	printf("free array\n");
	while (1)
	{
		if (list == NULL)
			exit(0);
		printf("check node *** node [%p], num [%d], prev [%p], next[%p]\n", list, list->num, list->prev, list->next);
		list = list->next;
	}
	//sort(argc - 1, list);
	//free();
	return (0);
}


__attribute__((destructor))
static void	destructor()
{
	system("leaks -q push_swap");
}
