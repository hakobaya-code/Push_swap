/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:37:52 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/07 15:25:15 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		index;
	int		*array;
	t_node	*nd;
	t_node	*list;

	index = 0;
	if (argc < 2)
		return (error_argc());
	array = make_array(argv);
	list = initialize_list();
	while (index < argc)
	{
		nd = add_list(&list, array[index]);
		index++;
	}
	sort(argc - 1, list);
	//free();
	return (0);
}


__attribute__((destructor))
static void	destructor()
{
	system("leaks -q push_swap");
}
