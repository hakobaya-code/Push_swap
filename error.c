/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:25:36 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/08 11:38:01 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_notdigit(void)
{
	ft_putstr_fd("ERROR: ARGV IS NOT DIGIT !!", 1);
	return ;
}

int	error_argc(void)
{
	ft_putstr_fd("ERROR:AT LEAST TWO ARGUMENTS ARE REQUIRED.", 1);
	return (1);
}

