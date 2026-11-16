/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:40:47 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/16 17:04:00 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	treat_args(char *arg, int **stacka, t_sizes *sizes)
{
	int	value;

	if (ft_strcmp(arg, "--bench") == 0)
		return (2);
	if (ft_is_option(arg) == 1)
		return (3);
	if (!is_valid(arg, &value) || in_stack(*stacka, value, sizes))
		return (0);
	(*stacka)[sizes->asize] = value;
	sizes->asize += 1;
	return (1);
}

static int	*ft_argv_to_stack(t_sizes *sizes, int ac, int **stacka, char *av[])
{
	int	i;
	int	*arguments;
	int	status;

	i = 1;
	status = 0;
	arguments = malloc(2 * sizeof(int));
	if (!arguments)
		return (free(arguments), NULL);
	arguments[0] = -1;
	arguments[1] = -1;
	while (i < ac)
	{
		status = treat_args(av[i], stacka, sizes);
		if (status == 0 || (status == 2 && arguments[0] != -1)
			|| (status == 3 && arguments[1] != -1))
			return (free(arguments), NULL);
		if (status == 2)
			arguments[0] = i;
		if (status == 3)
			arguments[1] = i;
		i += 1;
	}
	return (arguments);
}

static int	ft_get_choice(int pos, char **argv)
{
	if (pos == -1 || ft_strcmp(argv[pos], "--adaptive") == 0)
		return (-1);
	if (ft_strcmp(argv[pos], "--simple") == 0)
		return (0);
	if (ft_strcmp(argv[pos], "--medium") == 0)
		return (1);
	else
		return (2);
}

static void	ft_run_sort(int choice, int **stacks, t_bench *bnch, t_sizes *siz)
{
	if (choice == -1)
		ft_adaptative(&stacks[0], &stacks[1], bnch, siz);
	else
		ft_choose_sort(choice, bnch, stacks, siz);
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
		return (write(2, "Error\n", 6), ft_free(stacks[0], stacks[1], NULL, 0));
	benchmark.disorder = ft_calculate_disorder(stacks[0], &sizes);
	ft_run_sort(ft_get_choice(args[1], argv), stacks, &benchmark, &sizes);
	if (args[0] != -1)
		ft_benchmark(benchmark);
	ft_free(stacks[0], stacks[1], args, 1);
	return (0);
}
//