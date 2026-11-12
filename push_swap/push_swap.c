/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:40:47 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/12 15:19:17 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	is_in_stack(int *stack, int searched, t_sizes *sizes)
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

int	is_int(char *str)
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

int	main(int argc, char *argv[])
{
	int		i;
	int		isforce;
	int		isbench;
	int		*tabstack;
	int		*stackb;
	int		j;
	t_bench	benchmark;
	t_sizes sizes;

	i = 1;
	j = 0;
	isforce = -1;
	isbench = -1;
	if (!argv[1])
	{
		write(2, "Error\n", 6);
		return (0);
	}
	tabstack = malloc(argc * sizeof(int *));
	stackb = malloc(argc * sizeof(int *));
	if (!tabstack || !stackb)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			isbench = i;
		else if (ft_strncmp(argv[i], "--", 2) == 0)
			isforce = i;
		i += 1;
	}
	i = 1;
	sizes.asize = 0;
	sizes.bsize = 0;
	while (i < argc)
	{
		if (i != isforce && i != isbench)
		{
			if (!is_int(argv[i]) || is_in_stack(tabstack, ft_atoi(argv[i]), &sizes))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			tabstack[j] = ft_atoi(argv[i]);
			sizes.asize += 1;
			j += 1;
		}
		i += 1;
	}
	benchmark.disorder = ft_calculate_disorder(tabstack, &sizes);
	benchmark.complexity[17] = '\0';
	benchmark.strategy[21] = '\0';
	i = 0;
	while (i < 11)
		benchmark.operations[i++] = 0;
	if (isforce != -1)
	{
		if (ft_strcmp(argv[isforce], "--simple") == 0)
		{
			ft_memcpy(benchmark.strategy, "Simple");
			ft_memcpy(benchmark.complexity, "O(n²)");
			ft_tri_par_selection(&tabstack, &stackb, &benchmark, &sizes);
		}
		else if (ft_strcmp(argv[isforce], "--medium") == 0)
		{
			ft_memcpy(benchmark.strategy, "Medium");
			ft_memcpy(benchmark.complexity, "O(n√n)");
			ft_chunk_sort(&tabstack, &stackb, &benchmark, &sizes);
		}
		// else if (ft_strcmp(argv[isforce], "--complex"))
		// 	merged_sort(&tabstack, &stackb);
		else if (ft_strcmp(argv[isforce], "--adaptative") == 0)
			ft_adaptative(&tabstack, &stackb, &benchmark, &sizes);
	}
	else
		ft_adaptative(&tabstack, &stackb, &benchmark, &sizes);
	if (isbench != -1)
		ft_benchmark(benchmark);
	i = 0;
	while (i < sizes.asize)
		printf("%d\n", tabstack[i++]);
}
// 
//