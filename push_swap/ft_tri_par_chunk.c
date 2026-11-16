/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:39:32 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/16 16:49:02 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pos(int *stack, int target, int size)
{
	int	i;

	i = 0;
	while (i != size && stack[i] != target)
		i++;
	return (i);
}

static void	ft_sort_fake_stack(int **sorted, int *stacka, int size)
{
	int	i;
	int	j;
	int	stock;

	i = 0;
	while (i < size)
	{
		(*sorted)[i] = stacka[i];
		i += 1;
	}
	while (i > 1)
	{
		i -= 1;
		j = 0;
		while (j < i)
		{
			if ((*sorted)[j] > (*sorted)[i])
			{
				stock = (*sorted)[i];
				(*sorted)[i] = (*sorted)[j];
				(*sorted)[j] = stock;
			}
			j += 1;
		}
	}
}

static int	*ft_push_to_b(int **a, int **b, t_sizes *sizes, t_bench *bnc)
{
	int	pushed;
	int	*sorted;
	int	size;

	pushed = 0;
	size = sizes->asize;
	sorted = malloc(sizes->asize * sizeof(int));
	if (!sorted)
		return (NULL);
	ft_sort_fake_stack(&sorted, *a, sizes->asize);
	while (sizes->asize != 0)
	{
		if (get_pos(sorted, (*a)[0], size) < pushed)
			ft_pbrb(a, b, sizes, bnc);
		else if (get_pos(sorted, (*a)[0], size) < pushed + ft_chunk_size(size))
			pb(a, b, bnc, sizes);
		else
		{
			ra(a, 1, bnc, sizes);
			pushed -= 1;
		}
		pushed += 1;
	}
	return (sorted);
}

static void	ft_push_back(int ***stacks, t_bench *bnc, int *std, t_sizes *siz)
{
	int	len;
	int	target;

	len = 0;
	target = 0;
	while (siz->bsize > 0)
	{
		target = std[siz->bsize - 1];
		len = siz->bsize;
		if (get_pos(*stacks[1], target, siz->bsize) <= len / 2)
		{
			while ((*stacks[1])[0] != target)
				rb(stacks[1], 1, bnc, siz);
		}
		else
		{
			while ((*stacks[1])[0] != target)
				rrb(stacks[1], 1, bnc, siz);
		}
		pa(stacks[0], stacks[1], bnc, siz);
	}
}

void	ft_chunk_sort(int **stacka, int **stackb, t_bench *bnch, t_sizes *size)
{
	int	*sorted;
	int	**stacks[2];

	sorted = ft_push_to_b(stacka, stackb, size, bnch);
	if (!sorted)
	{
		write(2, "Error\n", 6);
		return ;
	}
	stacks[0] = stacka;
	stacks[1] = stackb;
	ft_push_back(stacks, bnch, sorted, size);
	free(sorted);
}
