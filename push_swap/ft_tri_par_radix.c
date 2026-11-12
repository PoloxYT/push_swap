/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_radix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:30:07 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/12 14:05:58 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes)
{
	int i;
    int bit;

    i = sizeof(atackb);
    bstack = malloc(i * sizeof(int));
	if (!astack)
		return ;
    while(astack != -1)
    {
        if((((*astack)->index >> bit) & 1) == 0)
            pb(astack, bstack);
        if((((*bstack)->index >> bit) & 1) == 0)
            pa(bstack, astack);
        stacka[i]++;
    }
}
