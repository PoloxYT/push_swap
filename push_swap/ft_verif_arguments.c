/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:34:43 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/16 16:56:09 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_stack(int *stack, int searched, t_sizes *sizes)
{
	int	i;

	i = 0;
	while (i != sizes->asize)
	{
		if (stack[i] == searched)
			return (1);
		i += 1;
	}
	return (0);
}

int	is_valid(char *str, int *result)
{
	long	num;
	int		i;
	int		signe;

	i = 0;
	signe = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signe *= -1;
	}
	if (!str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > ((2147483647L + (signe == -1)) - (str[i] - '0')) / 10)
			return (0);
		num = num * 10 + str[i++] - '0';
	}
	if (str[i])
		return (0);
	*result = (int)(num * signe);
	return (1);
}

int	ft_is_option(char *av)
{
	if (ft_strcmp(av, "--simple") == 0
		|| ft_strcmp(av, "--medium") == 0
		|| ft_strcmp(av, "--complex") == 0
		|| ft_strcmp(av, "--adaptive") == 0)
		return (1);
	return (0);
}
//
//
//
//
//