/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:40:47 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/10 11:35:28 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		isforce;
	int		isbench;
	int		*tabstack;
	int		*stackb;
	int		j;

	i = 1;
	j = 0;
	isforce = 0;
	isbench = 0;
	tabstack = malloc(argc * sizeof(int *));
	stackb = malloc(argc * sizeof(int *));
	if (!tabstack || !stackb)
		return (0);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			isbench = i;
		else if (ft_strncmp(argv[i], "--", 2) == 0)
			isforce = i;
		i += 1;
	}
	i = 1;
	while (i < argc)
	{
		if (i != isforce && i != isbench)
		{
			tabstack[j] = ft_atoi(argv[i]);
			j += 1;
		}
		i += 1;
	}
	tabstack[j] = -1;
	stackb[0] = -1;
	if (isforce != 0)
	{
		if (ft_strcmp(argv[isforce], "--simple") == 0)
			ft_tri_par_selection(&tabstack, &stackb);
		// else if (ft_strcmp(argv[isforce], "--medium"))
		// else if (ft_strcmp(argv[isforce], "--complex"))
		// 	merged_sort(&tabstack, &stackb);
		else if (ft_strcmp(argv[isforce], "--adaptative"))
			ft_adaptative(&tabstack, &stackb, ft_calculate_disorder(tabstack));
	}
	else
		ft_adaptative(&tabstack, &stackb, ft_calculate_disorder(tabstack));
	i = 0;
	while (i < argc - 2)
		printf("%d\n", tabstack[i++]);
}
//