/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_split_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:26:13 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/14 19:53:10 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	check_argv_split(char *str)
//{
//	int	i;

//	i = 0;
//	if (!(str[i] >= '0' && str[i] <= '9'))
//		error_notdigit();
//	while (str[i] != "\0")
//	{
//		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
//			error_notdigit();
//		i++;
//	}
//}

//int	*split_str(char *str)
//{
//	int	*sp_array;


//}

char	**split_array(char **argv)
{
	char	**sp;

	//check_argv_split(argv[1]);
	sp = ft_split(argv[1], ' ');
	return (sp);
}
