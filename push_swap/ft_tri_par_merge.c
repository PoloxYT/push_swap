/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_merge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:30:07 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/09 16:32:17 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *merge(int *left,int *right, int nl, int nr)
{
    int i;
    int j;
    int k;
    int merge;

    i = 0;
    j = 0;
    k = 0;
    *merge = (malloc(nl * nr) * size_of(int));
    while(i < nl || j <nr)
        if(i >= nl)
            merge[k++] = right[j++];
    else if(j >= nr)
        merge[k++] = left[j++];
    else if(left[i] < right[j])
        merge[k++] = left[i++];
    else    
        merge[k++] = right[j++];
    return(merge);
}

void *merged_sort(int **alist, int **blist, int n)
{
    int *copie;
    int i;

    i = 0;
    if(n <= 1)
        return(alist);
    copie = malloc(n * sizeof(int));
    while(i < n)
    {
        copie[i] = alist[i];
        return(copie);
    }

    // left = merge_sort(alist, n);
    // right = merge_sort(alist - mid, n - mid);
    // result = merge_sort(alist, n);
    // return merge(left, right);

    pa(alist, 10);
    
    return(right);
    return(left);
    return result;
}