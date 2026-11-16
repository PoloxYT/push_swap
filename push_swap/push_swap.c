/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:40:47 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/16 16:19:07 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_stack(int *stack, int searched, t_sizes *sizes)
{
	int	i;

	i = 0;
	while (i != sizes->asize)
	{
		if (stack[i] == searched)
			return (1);
		i += 1;
	}
	return (0);
}

static int	is_valid(char *str, int *result)
{
	long	num;
	int		i;
	int		signe;

	i = 0;
	signe = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signe *= -1;
	}
	if (!str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > ((2147483647L + (signe == -1)) - (str[i] - '0')) / 10)
			return (0);
		num = num * 10 + str[i++] - '0';
	}
	if (str[i])
		return (0);
	*result = (int)(num * signe);
	return (1);
}

static int	ft_is_option(char *av[], int i)
{
	if (ft_strcmp(av[i], "--simple") == 0
		|| ft_strcmp(av[i], "--medium") == 0
		|| ft_strcmp(av[i], "--complex") == 0
		|| ft_strcmp(av[i], "--adaptive") == 0)
		return (1);
	return (0);
}

static int	*ft_argv_to_stack(t_sizes *sizes, int ac, int **stacka, char *av[])
{
	int	i;
	int	*arguments;
	int	value;

	i = 1;
	value = 0;
	arguments = malloc(2 * sizeof(int));
	if (!arguments)
		return (free(arguments), NULL);
	arguments[0] = -1;
	arguments[1] = -1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--bench") == 0)
		{
			if (arguments[0] != -1)
				return (free(arguments), NULL);
			arguments[0] = i;
		}
		else if (ft_is_option(av, i))
		{
			if (arguments[1] != -1)
				return (free(arguments), NULL);
			arguments[1] = i;
		}
		if (i != arguments[1] && i != arguments[0])
		{
			if (!is_valid(av[i], &value) || in_stack(*stacka, value, sizes))
				return (free(arguments), NULL);
			(*stacka)[sizes->asize] = value;
			sizes->asize += 1;
		}
		i += 1;
	}
	return (arguments);
}

int	main(int argc, char *argv[])
{
	int		*args;
	int		*stacks[2];
	t_bench	benchmark;
	t_sizes	sizes;

	if (argc == 1)
		return (0);
	stacks[0] = malloc(argc * sizeof(int));
	stacks[1] = malloc(argc * sizeof(int));
	ft_apply_structs(&sizes, &benchmark);
	if (!stacks[0] || !stacks[1])
		return (write(2, "Error\n", 6), ft_free(stacks[0], stacks[1], NULL, 0));
	args = ft_argv_to_stack(&sizes, argc, &stacks[0], argv);
	if (!args)
		return (write(2, "Error\n", 6), ft_free(stacks[0], stacks[1], args, 0));
	benchmark.disorder = ft_calculate_disorder(stacks[0], &sizes);
	if (args[1] == -1 || ft_strcmp(argv[args[1]], "--adaptive") == 0)
		ft_adaptative(&stacks[0], &stacks[1], &benchmark, &sizes);
	else if (ft_strcmp(argv[args[1]], "--simple") == 0)
		ft_choose_sort(0, &benchmark, stacks, &sizes);
	else if (ft_strcmp(argv[args[1]], "--medium") == 0)
		ft_choose_sort(1, &benchmark, stacks, &sizes);
	else if (ft_strcmp(argv[args[1]], "--complex") == 0)
		ft_choose_sort(2, &benchmark, stacks, &sizes);
	else
		return (write(2, "Error\n", 6), ft_free(stacks[0], stacks[1], args, 1));
	if (args[0] != -1)
		ft_benchmark(benchmark);
	ft_free(stacks[0], stacks[1], args, 1);
}
//