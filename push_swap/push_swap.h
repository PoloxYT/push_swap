/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:31:59 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/09 16:32:25 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

void	sa(int	**stack);
void	sb(int	**stack);
void	ss(int **stacka, int **stackb);
void	ra(int **astack);
void	rb(int **bstack);
void	rr(int **astack, int **bstack);
void	rra(int	**astack);
void	rrb(int	**bstack);
void	rrr(int **astack, int **bstack);
void	pa(int *astack[], int *bstack[]);
void	pb(int *astack[], int *bstack[]);
int		ft_issort(int **T);
void	ft_tri_par_selection(int **A, int **B);
int		ft_atoi(const char	*str);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, int len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src);
void 	*merged_sort(int *alist, int n);

#endif