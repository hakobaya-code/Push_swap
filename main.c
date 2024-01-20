/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:37:52 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/20 19:47:45 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <libc.h>

t_stack	*make_stack(int *array)
{
	t_stack	*stack;
	t_node	*stack_a;
	t_node	*stack_b;

	stack = (t_stack *)malloc(sizeof(stack));
	if (!stack)
		exit(1);
	stack_a = initialize_list(array[0]);
	stack_b = NULL;
	stack->head_a = stack_a;
	stack->head_b = stack_b;
	return (stack);
}

int	count_words(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		index;
	int		*array;
	t_node	*nd;
	t_stack	*stack;

	index = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
		array = make_split_array(&argc, argv);
	else
		array = make_array(argc - 1, argv, 0);
	stack = make_stack(array);
	while (index < argc - 2)
	{
		index++;
		nd = add_node(stack->head_a, array[index]);
	}
	compaction(array, argc - 1, stack->head_a);
	sort(argc - 1, stack);
	free_stack(stack);
	return (0);
}
