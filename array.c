/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:55:32 by hakobaya          #+#    #+#             */
/*   Updated: 2023/12/09 15:55:34 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argv_all(char **argv, int i, long num)
{
	int	j;
	int	minus;

	minus = 1;
	j = 0;
	if (argv[i][j] == '-')
	{
		minus *= -1;
		j++;
	}
	num = 0;
	while (argv[i][j] >= '0' && argv[i][j] <= '9')
	{
		num = num * 10 + (argv[i][j] - '0');
		j++;
	}
	num *= minus;
	if (num > INT_MAX || num < INT_MIN)
		error_overint();
	if (argv[i][j] != '\0')
		error_notdigit();
	printf("[%d] %ld\n", i, num);
}

int	check_argv(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	num = 0;
	while (i < argc)
	{
		check_argv_all(argv, i, num);
		i++;
	}
	return (0);
}

int	*make_array(int arg_num, char **argv)
{
	int	*array;
	int	i;

	printf("enter make_array\n");
	i = 0;
	check_argv(arg_num + 1, argv);
	printf("arg_num: %d\n", arg_num);
	array = (int *)malloc(sizeof(int) * arg_num);
	if (!array)
		exit(1);
	while (i < arg_num)
	{
		array[i] = ft_atoi(&argv[i + 1][0]);
		printf("array[%d]:%d\n", i + 1, array[i]);
		i++;
	}
	return (array);
}