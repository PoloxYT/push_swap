/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:53:55 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/09 09:46:15 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	pb(int *astack[], int *bstack[])
{
	int	i;

	if (!(*astack) || (*astack)[0] == -1)
		return ;
	i = 0;
	while ((*bstack)[i] != -1)
		i += 1;
	while (i >= 0)
	{
		(*bstack)[i + 1] = (*bstack)[i];
		i--;
	}
	(*bstack)[0] = (*astack)[0];
	i = 0;
	while ((*astack)[i] != -1)
	{
		(*astack)[i] = (*astack)[i + 1];
		i += 1;
	}
}

void	pa(int *astack[], int *bstack[])
{
	int	i;

	i = 0;
	if (!(*bstack))
		return ;
	if ((*astack)[0])
	{
		while ((*astack)[i] != -1)
		{
			(*astack)[i + 1] = (*astack)[i];
			i += 1;
		}
	}
	(*astack)[0] = (*bstack)[0];
	i = 0;
	while ((*bstack)[i + 1] != -1)
	{
		(*bstack)[i] = (*bstack)[i + 1];
		i += 1;
	}
	(*bstack)[i] = (*bstack)[i + 1];
}
//
//
//
// int	main(void)
// {
// 	int	*tabtesta = malloc(4 * sizeof(int));
// 	int	*tabtestb = malloc(4 * sizeof(int));
// 	int	i;

// 	i = 0;
// 	tabtesta[0] = 1;
// 	tabtesta[1] = 2;
// 	tabtesta[2] = 3;
// 	tabtesta[3] = -1;
// 	tabtestb[0] = -1;
// 	pb(&tabtesta, &tabtestb);
// 	printf("%d\n", tabtestb[i]);
// 	free(tabtesta);
// 	free(tabtestb);
// }