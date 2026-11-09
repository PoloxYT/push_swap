/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:12:16 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/09 16:32:10 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int	**astack)
{
	int	i;
	int	stock;

	i = 0;
	stock = 0;
	while ((*astack)[i] != -1)
		i += 1;
	stock = (*astack)[0];
	(*astack)[0] = (*astack)[i - 1];
	i -= 1;
	while (i - 1 != 0)
	{
		(*astack)[i] = (*astack)[i - 1];
		i -= 1;
	}
	(*astack)[i] = stock;
}

void	rrb(int	**bstack)
{
	int	i;
	int	stock;

	i = 0;
	stock = 0;
	while ((*bstack)[i] != -1)
		i += 1;
	stock = (*bstack)[0];
	(*bstack)[0] = (*bstack)[i - 1];
	i -= 1;
	while (i - 1 != 0)
	{
		(*bstack)[i] = (*bstack)[i - 1];
		i -= 1;
	}
	(*bstack)[i] = stock;
}

void	rrr(int **astack, int **bstack)
{
	rra(astack);
	rrb(bstack);
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