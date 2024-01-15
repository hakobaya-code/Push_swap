/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:55:32 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/15 22:25:07 by hakobaya         ###   ########.fr       */
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

int	check_argv(int argc, char **argv, int flag)
{
	int		i;
	long	num;

	if (flag == 1)
	{
		i = 0;
		argc--;
	}
	else
		i = 1;
	num = 0;
	while (i < argc)
	{
		check_argv_all(argv, i, num);
		i++;
	}
	return (0);
}

int	*make_array(int arg_num, char **argv, int flag)
{
	int	*array;
	int	i;

	i = 0;
	check_argv(arg_num + 1, argv, flag);
	array = (int *)malloc(sizeof(int) * arg_num);
	if (!array)
		exit(1);
	while (i < arg_num)
	{
		if (flag == 1)
			array[i] = ft_atoi(&argv[i][0]);
		else
			array[i] = ft_atoi(&argv[i + 1][0]);
		i++;
	}
	check_same_num(array, arg_num);
	return (array);
}

int	*make_split_array(int *argc, char **argv)
{
	int	*array;

	argv = ft_split(argv[1], ' ');
	*argc = count_words(argv) + 1;
	array = make_array(*argc - 1, argv, 1);
	return (array);
}
