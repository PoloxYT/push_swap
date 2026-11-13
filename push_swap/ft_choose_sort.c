/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:51:01 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/13 15:38:12 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_sort(int choice, t_bench *bench, int **stacks, t_sizes *siz)
{
	if (choice == 0)
	{
		ft_memcpy(bench->strategy, "Simple");
		ft_memcpy(bench->complexity, "O(n²)");
		if (bench->disorder != 0)
			ft_tri_par_selection(&stacks[0], &stacks[1], bench, siz);
	}
	else if (choice == 1 && bench->disorder != 0)
	{
		ft_memcpy(bench->strategy, "Medium");
		ft_memcpy(bench->complexity, "O(n√n)");
		if (bench->disorder != 0)
			ft_chunk_sort(&stacks[0], &stacks[1], bench, siz);
	}
	else if (choice == 2 && bench->disorder != 0)
	{
		ft_memcpy(bench->strategy, "Complex");
		ft_memcpy(bench->complexity, "O(nlog(n))");
		if (bench->disorder != 0)
			radix(&stacks[0], &stacks[1], bench, siz);
	}
	return ;
}
