/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:06:37 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/10 10:50:39 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int **astack, int print)
{
	int	i;
	int	stock;
	int	stockone;

	i = 0;
	stock = 0;
	stockone = (*astack)[0];
	if (print == 1)
		write(1, "ra\n", 3);
	while ((*astack)[i] != -1)
		i += 1;
	stock = (*astack)[i - 1];
	(*astack)[i - 1] = (*astack)[0];
	i = 0;
	while ((*astack)[i + 1] != stockone)
	{
		(*astack)[i] = (*astack)[i + 1];
		i += 1;
	}
	(*astack)[i] = stock;
}

void	rb(int **bstack, int print)
{
	int	i;
	int	stock;
	int	stockone;

	i = 0;
	stock = 0;
	stockone = (*bstack)[0];
	if (print == 1)
		write(1, "rb\n", 3);
	while ((*bstack)[i] != -1)
		i += 1;
	stock = (*bstack)[i - 1];
	(*bstack)[i - 1] = (*bstack)[0];
	i = 0;
	while ((*bstack)[i + 1] != stockone)
	{
		(*bstack)[i] = (*bstack)[i + 1];
		i += 1;
	}
	(*bstack)[i] = stock;
}

void	rr(int **astack, int **bstack)
{
	write(1, "rr\n", 3);
	ra(astack, 0);
	rb(bstack, 0);
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