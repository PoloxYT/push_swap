/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:31:59 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/16 11:21:43 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_bench
{
	float	disorder;
	char	strategy[22];
	char	complexity[18];
	int		operations[11];
}	t_bench;

typedef struct s_sizes
{
	int	asize;
	int	bsize;
}	t_sizes;

void	sa(int	**stack, int print, t_bench *benchmark, t_sizes *sizes);
void	sb(int	**stack, int print, t_bench *benchmark, t_sizes *sizes);
void	ss(int **stacka, int **stackb, t_bench *benchmark, t_sizes *sizes);
void	ra(int **astack, int print, t_bench *benchmark, t_sizes *sizes);
void	rb(int **bstack, int print, t_bench *benchmark, t_sizes *sizes);
void	rr(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes);
void	rra(int	**astack, int print, t_bench *benchmark, t_sizes *sizes);
void	rrb(int	**bstack, int print, t_bench *benchmark, t_sizes *sizes);
void	rrr(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes);
void	pa(int *astack[], int *bstack[], t_bench *benchmark, t_sizes *sizes);
void	pb(int *astack[], int *bstack[], t_bench *benchmark, t_sizes *sizes);
void	ft_tri_par_selection(int **A, int **B, t_bench *bench, t_sizes *size);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, int len);
size_t	ft_putstr(const char *s, int isprint);
void	*ft_strcpy(void *dest, void *src);
void	*merged_sort(int *alist, int n);
float	ft_calculate_disorder(int *stack, t_sizes *sizes);
void	ft_adaptative(int **stacka, int **stackb, t_bench *bnch, t_sizes *size);
void	ft_benchmark(t_bench benchmark);
void	ft_chunk_sort(int **stacka, int **stackb, t_bench *bnch, t_sizes *size);
void	ft_choose_sort(int choice, t_bench *bench, int **stacks, t_sizes *siz);
void	radix(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes);

#endif