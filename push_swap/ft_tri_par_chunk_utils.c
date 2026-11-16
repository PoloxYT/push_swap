/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_par_chunk_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:49:41 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/16 13:54:08 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chunk_size(int n)
{
	int	chunksize;

	chunksize = 1;
	while ((long)chunksize * chunksize < n)
		chunksize += 1;
	return (chunksize * 5 / 4);
}
