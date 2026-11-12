/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:39:32 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/12 14:31:36 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != -1)
		i += 1;
	return (i);
}

static int	get_pos(int *stack, int target)
{
	int	i;

	i = 0;
	while (stack[i] != target && stack[i] != -1)
		i++;
	return (i);

}

static void	ft_sort_fake_stack(int **sorted, int *stacka, int size)
{
	int	i;
	int	j;
	int	stock;

	i = -1;
	stock = 0;
	j = 0;
	while (i++ < size)
		(*sorted)[i] = stacka[i];
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if ((*sorted)[j] < (*sorted)[i])
			{
				stock = (*sorted)[i];
				(*sorted)[i] = (*sorted)[j];
				(*sorted)[j] = stock;
			}
			j += 1;
		}
		i += 1;
	}
}

static void	ft_push_back(int **stacka, int **stackb, t_bench *bench, int *sorted, t_sizes *sizes)
{
	int	len;
	int	target;

	len = 0;
	target = 0;
	while (sizes->bsize > 0)
	{
		sizes->bsize -= 1;
		target = sorted[sizes->bsize];
		len = sizes->bsize;
		if (get_pos(*stackb, target) <= len / 2)
		{
			while ((*stackb)[0] != target)
				rb(stackb, 1, bench, sizes);
		}
		else
		{
			while ((*stackb)[0] != target)
				rrb(stackb, 1, bench, sizes);
		}
		pa(stacka, stackb, bench, sizes);
	}
}

void	ft_chunk_sort(int **stacka, int **stackb, t_bench *bnch, t_sizes *size)
{
	int	pushed;
	int	*sorted;

	pushed = 0;
	sorted = malloc(size->asize * sizeof(int));
	if (!sorted)
	{
		write(2, "Error\n", 6);
		return ;
	}
	ft_sort_fake_stack(&sorted, *stacka, stack_size(*stacka));
	while (size->asize != 0)
	{
		if (get_pos(sorted, (*stacka)[0]) < pushed)
		{
			pb(stacka, stackb, bnch, size);
			rb(stackb, 1, bnch, size);
			pushed += 1;
		}
		else if (get_pos(sorted, (*stacka)[0]) < pushed + 15)
		{
			pb(stacka, stackb, bnch, size);
			pushed += 1;
		}
		else
			ra(stacka, 1, bnch, size);
	}
	ft_push_back(stacka, stackb, bnch, sorted, size);
}
