/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_selection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:48:43 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/13 13:47:49 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tri_par_selection(int **A, int **B, t_bench *bench, t_sizes *size)
{
	int	i;
	int	min;

	i = 0;
	min = (*A)[0];
	while (size->asize != 0)
	{
		while (i != size->asize)
		{
			if ((*A)[i] < min)
				min = (*A)[i];
			i += 1;
		}
		while ((*A)[0] != min)
			ra(A, 1, bench, size);
		pb(A, B, bench, size);
		i = 0;
		min = (*A)[0];
	}
	i = 0;
	while (size->bsize != 0)
	{
		pa(A, B, bench, size);
		i += 1;
	}
}
//