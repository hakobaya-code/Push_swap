/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:24:49 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/17 04:01:50 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A'
			&& c <= 'Z'));
}

//int	ft_isalnum(int c)
//{
//	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A'
//			&& c <= 'Z'))
//		return (1);
//	return (0);
//}

//int	main(void)
//{
//	int	alnum;

//	alnum = isalnum('a');
//	printf("%d\n", alnum);
//}
