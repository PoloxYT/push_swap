/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:40:47 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/13 11:14:52 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

static int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i += 1;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i += 1;
	}
	return (1);
}

static int	*ft_argv_to_stack(t_sizes *sizes, int ac, int **stacka, char *av[])
{
	int	i;
	int	j;
	int	*arguments;

	i = 0;
	j = 0;
	arguments = malloc(2 * sizeof(int));
	if (!arguments)
		return (NULL);
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--bench") == 0)
			arguments[0] = i;
		else if (ft_strncmp(av[i], "--", 2) == 0)
			arguments[1] = i;
		i += 1;
	}
	i = 1;
	while (i < ac)
	{
		if (i != arguments[1] && i != arguments[0])
		{
			if (!is_int(av[i]) || in_stack(*stacka, ft_atoi(av[i]), sizes))
				return (NULL);
			(*stacka)[j] = ft_atoi(av[i]);
			sizes->asize += 1;
			j += 1;
		}
		i += 1;
	}
	return (arguments);
}

static void	ft_apply_structs(t_sizes *sizes, t_bench *benchmark, int **stacka)
{
	int	i;

	i = 0;
	sizes->asize = 0;
	sizes->bsize = 0;
	benchmark->disorder = ft_calculate_disorder(*stacka, sizes);
	benchmark->complexity[17] = '\0';
	benchmark->strategy[21] = '\0';
	while (i < 11)
		benchmark->operations[i++] = 0;
}

int	main(int argc, char *argv[])
{
	int		*arguments;
	int		*stacks[2];
	t_bench	benchmark;
	t_sizes	sizes;

	if (!argv[1])
		return (write(2, "Error\n", 6) * 0);
	stacks[0] = malloc(argc * sizeof(int *));
	stacks[1] = malloc(argc * sizeof(int *));
	arguments = ft_argv_to_stack(&sizes, argc, &stacks[0], argv);
	if (!stacks[0] || !stacks[1] || !arguments)
		return (write(2, "Error\n", 6) * 0);
	ft_apply_structs(&sizes, &benchmark, &stacks[0]);
	if (arguments[1] != -1)
	{
		if (ft_strcmp(argv[arguments[1]], "--simple") == 0)
			ft_choose_sort(0, &benchmark, stacks, &sizes);
		else if (ft_strcmp(argv[arguments[1]], "--medium") == 0)
			ft_choose_sort(1, &benchmark, stacks, &sizes);
		// else if (ft_strcmp(argv[isforce], "--complex"))
		// 	merged_sort(&stacka, &stackb);
	}
	else
		ft_adaptative(&stacks[0], &stacks[1], &benchmark, &sizes);
	if (arguments[0] != -1)
		ft_benchmark(benchmark);
	int i = 0;
	while (i < sizes.asize)
		printf("%d\n", stacks[0][i++]);
}
// 
//