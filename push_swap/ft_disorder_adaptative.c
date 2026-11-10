/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_adaptative.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:59:29 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/10 11:28:47 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptative(int **stacka, int **stackb, float disorder)
{
	if (disorder < 0.2)
		ft_tri_par_selection(stacka, stackb);
	else if (disorder >= 0.2 && disorder < 0.5)
		return ;
	else if (disorder >= 0.5)
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