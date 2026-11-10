/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_selection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:48:43 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/10 10:56:03 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issort(int **T)
{
	int	i;

	i = 0;
	while ((*T)[i + 1] != -1)
	{
		if ((*T)[i + 1] > (*T)[i])
			i += 1;
		else
			return (0);
	}
	return (1);
}

void	ft_tri_par_selection(int **A, int **B)
{
	int	i;
	int	min;

	i = 0;
	min = (*A)[0];
	while ((*A)[0] != -1)
	{
		while ((*A)[i] != -1)
		{
			if ((*A)[i] < min)
				min = (*A)[i];
			i += 1;
		}
		while ((*A)[0] != min)
			ra(A, 1);
		pb(A, B);
		i = 0;
		min = (*A)[0];
	}
	i = 0;
	while ((*B)[0] != -1)
	{
		pa(A, B);
		i += 1;
	}
}

// int	main(void)
// {
// 	int	*tabtesta = malloc(4 * sizeof(int));
// 	int	*tabtestb = malloc(4 * sizeof(int));
// 	int	i;

// 	i = 0;
// 	tabtesta[0] = 7;
// 	tabtesta[1] = 4;
// 	tabtesta[2] = 3;
// 	tabtesta[3] = -1;
// 	tabtestb[0] = -1;
// 	ft_triselect2(&tabtesta, &tabtestb);
// 	while (i < 4)
// 	{
// 		ft_putnbr_fd(tabtesta[i], 1);
// 		i += 1;
// 	}
// 	free(tabtesta);
// 	free(tabtestb);
// }