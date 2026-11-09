/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:06:37 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/06 16:20:44 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ra(int **astack)
{
	int	i;
	int	stock;
	int	stockone;

	i = 0;
	stock = 0;
	stockone = (*astack)[0];
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

void ft_triselect(int **T)
{
    int i;
    int issort;
    int stock;

    i = 0;
    issort = 0;
    stock = 0;
    while (issort != 1)
    {
        while((*T)[i + 1] != -1)
        {
            if((*T)[i] < (*T)[i + 1])
                ra(T);
            i++;
        }
        stock = 1;
        i = 0;
        while ((*T)[i + 1] != -1)
        {
            if ((*T)[i] < (*T)[i + 1])
                i += 1;
            else
                break ;
        }
        if (i == stock)
            issort = 1;
    }
}

void	rb(int **bstack)
{
	int	i;
	int	stock;
	int	stockone;

	i = 0;
	stock = 0;
	stockone = (*bstack)[0];
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
	ra(astack);
	rb(bstack);
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