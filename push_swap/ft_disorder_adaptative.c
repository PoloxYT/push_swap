/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_adaptative.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:59:29 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/12 15:15:36 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(2, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	write(2, &(char){n % 10 + '0'}, 1);
}

static void	ft_print_ops(t_bench benchmark)
{
	write(2, "[bench] ", 8);
	write(2, "sa: ", 4);
	ft_putnbr(benchmark.operations[0]);
	write(2, " sb: ", 5);
	ft_putnbr(benchmark.operations[1]);
	write(2, " ss: ", 5);
	ft_putnbr(benchmark.operations[2]);
	write(2, " pa: ", 5);
	ft_putnbr(benchmark.operations[3]);
	write(2, " pb: ", 5);
	ft_putnbr(benchmark.operations[4]);
	write(2, "\n[bench] ", 9);
	write(2, "ra: ", 4);
	ft_putnbr(benchmark.operations[5]);
	write(2, " rb: ", 5);
	ft_putnbr(benchmark.operations[6]);
	write(2, " rr: ", 5);
	ft_putnbr(benchmark.operations[7]);
	write(2, " rra: ", 6);
	ft_putnbr(benchmark.operations[8]);
	write(2, " rrb: ", 6);
	ft_putnbr(benchmark.operations[9]);
	write(2, " rrr: ", 6);
	ft_putnbr(benchmark.operations[10]);
	write(2, "\n", 1);
}

void	ft_benchmark(t_bench benchmark)
{
	int	i;
	int	ops;

	i = 0;
	ops = 0;
	write(2, "[bench] desordre: ", 18);
	benchmark.disorder *= 100;
	ft_putnbr((int)benchmark.disorder);
	write(2, ".", 1);
	benchmark.disorder -= (int)benchmark.disorder;
	benchmark.disorder *= 100;
	ft_putnbr((int)benchmark.disorder);
	write(2, "%\n", 2);
	write(2, "[bench] strategie: ", 19);
	ft_putstr(benchmark.strategy, 1);
	write(2, " / ", 3);
	ft_putstr(benchmark.complexity, 1);
	write(2, "\n", 1);
	write(2, "[bench] operations: ", 20);
	while (i < 11)
		ops += benchmark.operations[i++];
	ft_putnbr(ops);
	write(2, "\n", 1);
	ft_print_ops(benchmark);
}

void	ft_adaptative(int **stacka, int **stackb, t_bench *bnch, t_sizes *size)
{
	ft_memcpy(bnch->strategy, "Adaptative");
	if (bnch->disorder < 0.2)
	{
		ft_tri_par_selection(stacka, stackb, bnch, size);
		ft_memcpy(bnch->complexity, "O(n²)");
	}
	else if (bnch->disorder >= 0.2 && bnch->disorder < 0.5)
	{
		ft_chunk_sort(stacka, stackb, bnch, size);
		ft_memcpy(bnch->complexity, "O(n√n)");
	}
	else if (bnch->disorder >= 0.5)
		return ;
}

float	ft_calculate_disorder(int *stack, t_sizes *sizes)
{
	int	errors;
	int	pairs;
	int	i;
	int	j;

	errors = 0;
	pairs = 0;
	i = 0;
	j = 0;
	while (i + 1 != sizes->asize)
	{
		j = i + 1;
		while (j + 1 != sizes->asize)
		{
			pairs += 1;
			if (stack[i] > stack[j])
				errors += 1;
			j += 1;
		}
		i += 1;
	}
	return ((float)errors / pairs);
}
//
//
//