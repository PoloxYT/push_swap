/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_radix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:30:07 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/16 16:33:01 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_how_many_bits(int sizes)
{
	int	bit;
	int	max_bits;

	bit = 0;
	max_bits = sizes - 1;
	while ((max_bits >> bit) > 0)
		bit++;
	return (bit);
}

void	ft_swap(int i, int j, int **sorted)
{
	int	stock;

	stock = (*sorted)[i];
	(*sorted)[i] = (*sorted)[j];
	(*sorted)[j] = stock;
}

static int	*ft_sorted_copy(int *tab, int size)
{
	int	i;
	int	j;
	int	*sorted;

	i = 0;
	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return (NULL);
	while (i < size)
	{
		sorted[i] = tab[i];
		i += 1;
	}
	while (i > 1)
	{
		i -= 1;
		j = 0;
		while (j < i)
		{
			if (sorted[j] > sorted[i])
				ft_swap(i, j, &sorted);
			j += 1;
		}
	}
	return (sorted);
}

static int	ft_rank_bit(int *sorted, int size, int value, int bit)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < size)
	{
		if (sorted[i] < value)
			rank++;
		i++;
	}
	return ((rank >> bit) & 1);
}

int	radix(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes)
{
	int	*sorted;
	int	bit;
	int	count;
	int	size;

	size = sizes->asize;
	sorted = ft_sorted_copy(*astack, sizes->asize);
	if (!sorted)
		return (write(2, "Error\n", 6), 1);
	bit = 0;
	while (bit < ft_how_many_bits(size))
	{
		count = 0;
		while (count++ < size)
		{
			if (ft_rank_bit(sorted, size, (*astack)[0], bit))
				ra(astack, 1, benchmark, sizes);
			else
				pb(astack, bstack, benchmark, sizes);
		}
		while (sizes->bsize > 0)
			pa(astack, bstack, benchmark, sizes);
		bit += 1;
	}
	return (free(sorted), 0);
}
//
//
//
//