/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:40:47 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/12 16:51:49 by pabaille         ###   ########.fr       */
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
	sizes->asize = 0;
	sizes->bsize = 0;
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

int	main(int argc, char *argv[])
{
	int		i;
	int		*arguments;
	int		*stacka;
	int		*stackb;
	t_bench	benchmark;
	t_sizes sizes;

	i = 1;
	if (!argv[1])
		return (write(2, "Error\n", 6) * 0);
	stacka = malloc(argc * sizeof(int *));
	stackb = malloc(argc * sizeof(int *));
	arguments = ft_argv_to_stack(&sizes, argc, &stacka, argv);
	if (!stacka || !stackb || !arguments)
		return (write(2, "Error\n", 6) * 0);
	benchmark.disorder = ft_calculate_disorder(stacka, &sizes);
	benchmark.complexity[17] = '\0';
	benchmark.strategy[21] = '\0';
	i = 0;
	while (i < 11)
		benchmark.operations[i++] = 0;
	if (arguments[1] != -1)
	{
		if (ft_strcmp(argv[arguments[1]], "--simple") == 0)
		{
			ft_memcpy(benchmark.strategy, "Simple");
			ft_memcpy(benchmark.complexity, "O(n²)");
			ft_tri_par_selection(&stacka, &stackb, &benchmark, &sizes);
		}
		else if (ft_strcmp(argv[arguments[1]], "--medium") == 0)
		{
			ft_memcpy(benchmark.strategy, "Medium");
			ft_memcpy(benchmark.complexity, "O(n√n)");
			ft_chunk_sort(&stacka, &stackb, &benchmark, &sizes);
		}
		// else if (ft_strcmp(argv[isforce], "--complex"))
		// 	merged_sort(&stacka, &stackb);
		else if (ft_strcmp(argv[arguments[1]], "--adaptative") == 0)
			ft_adaptative(&stacka, &stackb, &benchmark, &sizes);
	}
	else
		ft_adaptative(&stacka, &stackb, &benchmark, &sizes);
	if (arguments[0] != -1)
		ft_benchmark(benchmark);
	i = 0;
	while (i < sizes.asize)
		printf("%d\n", stacka[i++]);
}
// 
//