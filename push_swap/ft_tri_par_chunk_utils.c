/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_chunk_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:49:41 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/16 16:13:46 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_size(int n)
{
	int	chunksize;

	chunksize = 1;
	while ((long)chunksize * chunksize < n)
		chunksize += 1;
	return (chunksize * 5 / 4);
}

void	ft_pbrb(int **a, int **b, t_sizes *sizes, t_bench *bnc)
{
	pb(a, b, bnc, sizes);
	rb(b, 1, bnc, sizes);
}

int	ft_free(int *a, int *b, int *c, int freec)
{
	free(a);
	free(b);
	if (freec == 1)
		free(c);
	return (1);
}

void	ft_putnbr(int nb)
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
