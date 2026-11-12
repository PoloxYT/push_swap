/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_adaptative.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:59:29 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/12 12:05:10 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putrevstr(int n)
{
	int		i;
	char	str[11];

	i = 0;
	str[10] = '\0';
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		i += 1;
		n = n / 10;
	}
	i -= 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i -= 1;
	}
}

void	ft_putnbr(int n)
{
	char	c;

	c = 'g';
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
		return ;
	}
	ft_putrevstr(n);
}

void	ft_print_ops(t_bench benchmark)
{
	write(1, "[bench] ", 8);
	write(1, "sa: ", 4);
	ft_putnbr(benchmark.operations[0]);
	write(1, " sb: ", 5);
	ft_putnbr(benchmark.operations[1]);
	write(1, " ss: ", 5);
	ft_putnbr(benchmark.operations[2]);
	write(1, " pa: ", 5);
	ft_putnbr(benchmark.operations[3]);
	write(1, " pb: ", 5);
	ft_putnbr(benchmark.operations[4]);
	write(1, "\n[bench] ", 9);
	write(1, "ra: ", 4);
	ft_putnbr(benchmark.operations[5]);
	write(1, " rb: ", 5);
	ft_putnbr(benchmark.operations[6]);
	write(1, " rr: ", 5);
	ft_putnbr(benchmark.operations[7]);
	write(1, " rra: ", 6);
	ft_putnbr(benchmark.operations[8]);
	write(1, " rrb: ", 6);
	ft_putnbr(benchmark.operations[9]);
	write(1, " rrr: ", 6);
	ft_putnbr(benchmark.operations[10]);
	write(1, "\n", 1);
}

void	ft_benchmark(t_bench benchmark)
{
	int	i;
	int	ops;

	i = 0;
	ops = 0;
	write(1, "[bench] desordre: ", 18);
	benchmark.disorder *= 100;
	ft_putnbr((int)benchmark.disorder);
	write(1, ".", 1);
	benchmark.disorder -= (int)benchmark.disorder;
	benchmark.disorder *= 100;
	ft_putnbr((int)benchmark.disorder);
	write(1, "%\n", 2);
	write(1, "[bench] strategie: ", 19);
	ft_putstr(benchmark.strategy, 1);
	write(1, " / ", 3);
	ft_putstr(benchmark.complexity, 1);
	write(1, "\n", 1);
	write(1, "[bench] operations: ", 20);
	while (i < 11)
		ops += benchmark.operations[i++];
	ft_putnbr(ops);
	write(1, "\n", 1);
	ft_print_ops(benchmark);
}

void	ft_adaptative(int **stacka, int **stackb, t_bench *benchmark)
{
	ft_memcpy(benchmark->strategy, "Adaptative");
	if (benchmark->disorder < 0.2)
	{
		ft_tri_par_selection(stacka, stackb, benchmark);
		ft_memcpy(benchmark->complexity, "O(n²)");
	}
	else if (benchmark->disorder >= 0.2 && benchmark->disorder < 0.5)
	{
		ft_chunk_sort(stacka, stackb, benchmark);
		ft_memcpy(benchmark->complexity, "O(n√n)");
	}
	else if (benchmark->disorder >= 0.5)
		return ;
}

float	ft_calculate_disorder(int *stack)
{
	int	errors;
	int	pairs;
	int	i;
	int	j;

	errors = 0;
	pairs = 0;
	i = 0;
	j = 0;
	while (stack[i + 1] != -1)
	{
		j = i + 1;
		while (stack[j + 1] != -1)
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