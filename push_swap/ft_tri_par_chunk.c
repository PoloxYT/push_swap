/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:39:32 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/10 16:22:58 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_chunk_sort(int **stacka, int **stackb)
{
	int	i;
	int	*postab;

	i = 0;
	while (stacka[i] != -1)
		i += 1;
	postab = malloc(i * sizeof(int));
	if (!postab)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	while (i >= 0)
	{
		postab[i] = i;
		i -= 1;
	}
}
