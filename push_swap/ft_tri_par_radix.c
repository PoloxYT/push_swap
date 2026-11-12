/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_radix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:30:07 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/12 16:51:46 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes)
{
	int i;
    int j;
    int bit;
    int max_bits;

    i = sizes->bsize;
    j = sizes->asize;
    bit = 
    max_bits = 1;
    bstack = malloc(sizes * sizeof(int));
	if (!astack)
		return ;
    while(astack[i] != -1)
    {
        i++;
        if((((astack)->index >> bit) & 1) == 0)
            pb(astack, bstack);
    }
    while(bstack[j] != '\0') 
    {
        j++;
        pa(bstack, astack);
    }
}
