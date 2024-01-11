/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:55:32 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/11 19:58:59 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_same_num(int *array, int arg_num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arg_num - 1)
	{
		j = i + 1;
		while (j < arg_num)
		{
			if (array[i] == array[j])
				error_same_num(array);
			j++;
		}
		i++;
	}
	return ;
}

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
	//printf("[%d] %ld\n", i, num);
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

	i = 0;
	check_argv(arg_num + 1, argv);
	//printf("arg count: %d\n", arg_num);
	array = (int *)malloc(sizeof(int) * arg_num);
	if (!array)
		exit(1);
	while (i < arg_num)
	{
		array[i] = ft_atoi(&argv[i + 1][0]);
		//printf("array[%d]:%d\n", i + 1, array[i]);
		i++;
	}
	check_same_num(array, arg_num);
	return (array);
}
