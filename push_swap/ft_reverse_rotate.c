/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:12:16 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/17 09:38:36 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int	**astack, int print, t_bench *benchmark, t_sizes *sizes)
{
	int	i;
	int	stocklast;

	i = 0;
	stocklast = 0;
	if (sizes->asize < 2)
		return ;
	if (print == 1)
	{
		// write(1, "rra\n", 4); A COMMENTER EN LIVE CODING
		benchmark->operations[8] += 1;
	}
	stocklast = (*astack)[sizes->asize - 1];
	i = sizes->asize - 1;
	while (i != 0)
	{
		(*astack)[i] = (*astack)[i - 1];
		i -= 1;
	}
	(*astack)[0] = stocklast;
}

void	rrb(int	**bstack, int print, t_bench *benchmark, t_sizes *sizes)
{
	int	i;
	int	stocklast;

	i = 0;
	stocklast = 0;
	if (sizes->bsize < 2)
		return ;
	if (print == 1)
	{
		// write(1, "rrb\n", 4); A COMMENTER EN LIVE CODING
		benchmark->operations[9] += 1;
	}
	stocklast = (*bstack)[sizes->bsize - 1];
	i = sizes->bsize - 1;
	while (i != 0)
	{
		(*bstack)[i] = (*bstack)[i - 1];
		i -= 1;
	}
	(*bstack)[0] = stocklast;
}

void	rrr(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes)
{
	if (sizes->asize < 2 && sizes->bsize < 2)
		return ;
	// write(1, "rrr\n", 4); A COMMENTER EN LIVE CODING
	benchmark->operations[10] += 1;
	rra(astack, 0, benchmark, sizes);
	rrb(bstack, 0, benchmark, sizes);
}

// int	main(void)
// {
// 	int	*tabtesta = malloc(4 * sizeof(int));
// 	int	i;

// 	i = 0;
// 	tabtesta[0] = 1;
// 	tabtesta[1] = 2;
// 	tabtesta[2] = 3;
// 	tabtesta[3] = -1;
// 	rra(&tabtesta);
// 	while (i < 4)
// 		printf("%d\n", tabtesta[i++]);
// 	free(tabtesta);
// }