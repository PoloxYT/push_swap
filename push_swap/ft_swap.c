/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:31:18 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/10 10:51:49 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int	**stack, int print)
{
	int	stock;

	if (print == 1)
		write(1, "sa\n", 3);
	stock = *stack[0];
	(*stack)[0] = *stack[1];
	(*stack)[1] = stock;
}

void	sb(int	**stack, int print)
{
	int	stock;

	if (print == 1)
		write(1, "sb\n", 3);
	stock = (*stack)[0];
	(*stack)[0] = (*stack)[1];
	(*stack)[1] = stock;
}

void	ss(int **stacka, int **stackb)
{
	write(1, "ss\n", 3);
	sb(stackb, 0);
	sa(stacka, 0);
}
//
//
//
//
//