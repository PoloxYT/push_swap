/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_radix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:30:07 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/13 11:15:09 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_verif_bits(int sizes)
{
	int	bit;
	int	max_bits;
	
	bit = 0;
	max_bits = sizes -1;
}

void	ft_bits(int **astack, int **bstack, t_bench *benchmark,
		t_sizes *sizes, int bit)
{
	if ((((*astack)[0] >> bit) & 1) == 0)
		pb(astack, bstack, benchmark, sizes);
	else
		ra(astack, benchmark, sizes);
}

void	radix(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes)
{
	int	i;
	int	j;
	int	bit;
	int	max_bits;

	i = sizes->bsize;
	j = sizes->asize;
	bstack = malloc(sizes * sizeof(int));
	if (!astack)
		return ;
	while (astack[i] != -1)
	{
		ft_bits(astack, bstack);
		i++;
	}
	while (bstack[j] != '\0') 
	{
		ft_bits(astack, bstack);
		j++;
	}
}
