/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:31:59 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/17 09:45:09 by pabaille         ###   ########.fr       */
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
	int		error;
}	t_bench;

typedef struct s_sizes
{
	int	asize;
	int	bsize;
	int	printcount; // LIVE CODING
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
void	ft_tri_par_selection(int **a, int **b, t_bench *bench, t_sizes *size);
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
int		radix(int **astack, int **bstack, t_bench *benchmark, t_sizes *sizes);
int		ft_chunk_size(int n);
void	ft_pbrb(int **a, int **b, t_sizes *sizes, t_bench *bnc);
int		ft_free(int *a, int *b, int *c, int freec);
void	ft_putnbr(int nb);
void	ft_apply_structs(t_sizes *sizes, t_bench *benchmark);
int		in_stack(int *stack, int searched, t_sizes *sizes);
int		is_valid(char *str, int *result);
int		ft_is_option(char *av);

#endif