/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:37:52 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/04 17:07:09 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <libc.h>

t_stack	*make_stack(int	*array)
{
	t_stack	*stack;
	t_node	*stack_a;
	t_node	*stack_b;

	stack = (t_stack *)malloc(sizeof(stack));
	if (!stack)
		exit(1);
	stack_a = initialize_list(array[0]);
	//stack_b = initialize_stackb();
	stack_b = NULL;
	stack->head_a = stack_a;
	stack->head_b = stack_b;
	return (stack);
}

int	main(int argc, char **argv)
{
	int		index;
	int		*array;
	t_node	*nd;
	t_stack	*stack;

	index = 0;
	if (argc < 2)
		return (error_argc());
	array = make_array(argc - 1, argv);
	stack = make_stack(array);
	printf("initialize stack_a [%p]\n", stack->head_a);
	printf("initialize stack_b [%p]\n", stack->head_b);
	while (index < argc - 2)
	{
		index++;
		nd = add_node(stack->head_a, array[index]);
	}
	array = compaction(array, argc - 1, stack->head_a);
	printf("NODE: 🙆‍♀️add_node done.\n");
	free(array);
	printf("NODE: 🙆‍♀️try swap.\n");
	//printf("main: head_a %p, prev %p, next %p, num %d\n", stack->head_a, stack->head_a->prev, stack->head_a->next, stack->head_a->num);
	//sa(stack);
	//sb(stack);
	//rra(stack);
	//rrb(stack);
	//rr(stack);
	//pb(stack);
	//pa(stack);
	//printf("main: head_a %p, prev %p, next %p, num %d\n", stack->head_a, stack->head_a->prev, stack->head_a->next, stack->head_a->num);
	//printf("main: head_b %p, prev %p, next %p, num %d\n", stack->head_b, stack->head_b->prev, stack->head_b->next, stack->head_b->num);
	printf("💛sort start\n");
	sort(argc - 1, stack);
	while (1)
	{
		if (stack->head_a == NULL)
			break ;
		printf("🎁check node stack_a *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_a, stack->head_a->num, stack->head_a->rank, stack->head_a->prev, stack->head_a->next);
		stack->head_a = stack->head_a->next;
	}
	while (1)
	{
		if (stack->head_b == NULL)
			break ;
		printf("🎁check node stack_b *** node [%p], num [%d], rank[%d], prev [%p], next[%p]\n", stack->head_b, stack->head_b->num, stack->head_b->rank, stack->head_b->prev, stack->head_b->next);
		stack->head_b = stack->head_b->next;
	}
	//printf("💜end node\n");
	//printf("💛end swap\n");
	//free();
	return (0);
}


//__attribute__((destructor))
//static void	destructor()
//{
//	system("\n\nleaks -q push_swap");
//}
