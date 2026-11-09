/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlgoS-1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:48:43 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/09 10:21:32 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_issort(int **T)
{
    int i;

    i = 0;
    while ((*T)[i + 1] != -1)
    {
        if ((*T)[i] < (*T)[i + 1])
            i += 1;
        else
            return (0);
    }
    return (1);

}

// void ft_triselect(int **T)
// {
//     int i;
//     int issort;
//     int stock;

//     i = 0;
//     issort = 0;
//     stock = 0;
//     while (issort != 1)
//     {
//         while((*T)[i + 1] != -1)
//         {        stock = 1;
//         i = 0;
//         while ((*T)[i + 1] != -1)
//         {
//             if ((*T)[i] < (*T)[i + 1])
//                 i += 1;
//             else
//                 break ;
//         }
//         if (i == stock)
//             issort = 1;
//             if((*T)[i] < (*T)[i + 1])
//                 ra(T);
//             i++;
//         }
//         ft_issort(T);
//     }
// }

void	pb(int *astack[], int *bstack[])
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!(*astack))
		return ;
	if ((*bstack)[0] != -1)
	{
		while ((*bstack)[len] != -1)
			len += 1;
		if (len != 0)
			len = (*bstack)[len - 1];
		while ((*bstack)[i + 1] != -1)
		{
			(*bstack)[i + 1] = (*bstack)[i];
			i += 1;
		}
		(*bstack)[i] = len;
		(*bstack)[0] = (*astack)[0];
	}
	else
	{
		(*bstack[1]) = (*bstack)[0];
		(*bstack)[0] = (*astack)[0];
	}
	printf("bstack 0 = %d\n", (*bstack)[0]);
	i = 1;
	while ((*bstack)[i] != -1)
		i += 1;
	len = (*bstack)[i - 1];
	i = 1;
	while ((*astack)[i + 1] != -1)
	{
		(*astack)[i] = (*astack)[i + 1];
		i += 1;
	}
	(*astack)[i] = len;
}

void	pa(int *astack[], int *bstack[])
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while ((*astack)[len] != -1)
		len += 1;
	if (!(*bstack))
		return ;
	len = (*astack)[len - 1];
	if ((*astack)[0] != -1)
	{
		while ((*astack)[i + 1] != -1)
		{
			(*astack)[i + 1] = (*astack)[i];
			i += 1;
		}
		(*astack)[i] = len;
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

void	ft_triselect2(int **A, int **B)
{
	int	i;
	int	min;

	i = 0;
	min = i;
	while ((*A)[0] != -1)
	{
		while ((*A)[i] != -1)
		{
			if ((*A)[i] < (*A)[min])
				min = i;
			i += 1;
		}
		i = min;
		pb(A, B);
		i = 0;
		min = 0;
	}
	i = 0;
	while (i < 4)
		printf("%d\n", (*B)[i++]);
	i = 0;
	while ((*B)[i] != -1)
	{
		pa(A, B);
		i += 1;
	}
	if (ft_issort(A) == 1)
		printf("trie\n");
}

int	main(void)
{
	int	*tabtesta = malloc(4 * sizeof(int));
	int	*tabtestb = malloc(4 * sizeof(int));
	int	i;

	i = 0;
	tabtesta[0] = 1;
	tabtesta[1] = 2;
	tabtesta[2] = 3;
	tabtesta[3] = -1;
	tabtestb[0] = -1;
	ft_triselect2(&tabtesta, &tabtestb);
	while (i < 4)
		printf("%d\n", tabtesta[i++]);
	free(tabtesta);
	free(tabtestb);
}