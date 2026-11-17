/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:06:37 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/17 09:39:15 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int **astack, int print, t_bench *benchmark, t_sizes *sizes)
{
	int	i;
	int	stockfirst;

	i = 0;
	if (sizes->asize < 2)
		return ;
	stockfirst = (*astack)[0];
	if (print == 1)
		benchmark->operations[5] += 1;
	// if (print == 1) A COMMENTER EN LIVE CODING
	// 	write(1, "ra\n", 3); A COMMENTER EN LIVE CODING
	while (i < sizes->asize - 1)
	{
		(*astack)[i] = (*astack)[i + 1];
		i += 1;
	}
	(*astack)[i] = stockfirst;
}

void	rb(int **bstack, int print, t_bench *benchmark, t_sizes *sizes)
{
	int	i;
	int	stockfirst;

	i = 0;
	if (sizes->bsize < 2)
		return ;
	stockfirst = (*bstack)[0];
	if (print == 1)
		benchmark->operations[6] += 1;
	// if (print == 1) A COMMENTER EN LIVE CODING
	// 	write(1, "rb\n", 3); A COMMENTER EN LIVE CODING
	while (i < sizes->bsize - 1)
	{
		(*bstack)[i] = (*bstack)[i + 1];
		i += 1;
	}
	(*bstack)[i] = stockfirst;
}

void	rr(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes)
{
	if (sizes->asize < 2 && sizes->bsize < 2)
		return ;
	// write(1, "rr\n", 3); A COMMENTER EN LIVE CODING
	benchmark->operations[7] += 1;
	ra(astack, 0, benchmark, sizes);
	rb(bstack, 0, benchmark, sizes);
}

// int	main(void)
// {
// 	int	*tabtesta = malloc(5 * sizeof(int));
// 	int	i;

// 	i = 0;
// 	tabtesta[0] = 1;
// 	tabtesta[1] = 2;
// 	tabtesta[2] = 3;
// 	tabtesta[3] = -1;
// 	ft_triselect(&tabtesta);
// 	while (i < 4)
// 		printf("%d\n", tabtesta[i++]);
// 	free(tabtesta);
// }