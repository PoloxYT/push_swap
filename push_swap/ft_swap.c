/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:31:18 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/06 16:20:47 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sa(int	**stack)
{
	int	stock;

	stock = *stack[0];
	(*stack)[0] = *stack[1];
	(*stack)[1] = stock;
}

void	sb(int	**stack)
{
	int	stock;

	stock = (*stack)[0];
	(*stack)[0] = (*stack)[1];
	(*stack)[1] = stock;
}

void	ss(int **stacka, int **stackb)
{
	sb(stackb);
	sa(stacka);
}
//
//
//
//
//