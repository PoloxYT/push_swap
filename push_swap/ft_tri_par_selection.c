/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_selection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:48:43 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/16 15:19:17 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tri_par_selection(int **a, int **b, t_bench *bench, t_sizes *size)
{
	int	i;
	int	min;

	i = 0;
	min = (*a)[0];
	while (size->asize != 0)
	{
		while (i != size->asize)
		{
			if ((*a)[i] < min)
				min = (*a)[i];
			i += 1;
		}
		while ((*a)[0] != min)
			ra(a, 1, bench, size);
		pb(a, b, bench, size);
		i = 0;
		if (size->asize > 0)
			min = (*a)[0];
	}
	while (size->bsize != 0)
	{
		pa(a, b, bench, size);
		i += 1;
	}
}
//