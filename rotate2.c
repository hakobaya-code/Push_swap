/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:27:51 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/10 18:45:30 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *stack, t_node *head_a, t_node *head_b)
{
	ra(stack, head_a);
	rb(stack, head_b);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack *stack, t_node *head_a, t_node *head_b)
{
	ra(stack, head_a);
	rb(stack, head_b);
	ft_putstr_fd("rrr\n", 1);
}
