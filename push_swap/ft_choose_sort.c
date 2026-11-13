/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:51:01 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/13 13:54:13 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_sort(int choice, t_bench *bench, int **stacks, t_sizes *siz)
{
	if (choice == 0)
	{
		ft_memcpy(bench->strategy, "Simple");
		ft_memcpy(bench->complexity, "O(n²)");
		ft_tri_par_selection(&stacks[0], &stacks[1], bench, siz);
	}
	else if (choice == 1)
	{
		ft_memcpy(bench->strategy, "Medium");
		ft_memcpy(bench->complexity, "O(n√n)");
		ft_chunk_sort(&stacks[0], &stacks[1], bench, siz);
	}
	else if (choice == 2)
	{
		ft_memcpy(bench->strategy, "Complex");
		ft_memcpy(bench->complexity, "O(nlog(n))");
		radix(&stacks[0], &stacks[1], bench, siz);
	}
}
