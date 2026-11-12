/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabaille <pabaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:59:02 by pabaille          #+#    #+#             */
/*   Updated: 2026/11/11 11:21:06 by pabaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, void *src)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)(dest);
	s = (unsigned char *)(src);
	while (s[i] != 0)
	{
		d[i] = s[i];
		i += 1;
	}
	d[i] = '\0';
	return (dest);
}

int	ft_atoi(const char	*str)
{
	int		i;
	int		signe;
	long	num;

	i = 0;
	signe = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i += 1;
	}
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			return ((int)((num / 10) * signe));
		num += str[i] - '0';
		num *= 10;
		i += 1;
	}
	num = (num / 10) * signe;
	return ((int)(num));
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != 0 && str1[i] == str2[i])
		i += 1;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	ft_strncmp(const char *str1, const char *str2, int len)
{
	int	i;

	i = 0;
	while (str1[i] != 0 && i < len - 1 && str1[i] == str2[i])
		i += 1;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

size_t	ft_putstr(const char *s, int isprint)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (isprint == 1)
			write(1, &s[i], 1);
		i += 1;
	}
	return (i);
}
