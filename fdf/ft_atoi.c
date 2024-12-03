/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:55:09 by lkazaz            #+#    #+#             */
/*   Updated: 2024/01/17 14:12:56 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sin;
	long	resl;
	int		s;

	i = 0;
	s = 0;
	sin = 1;
	resl = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] == '+' || str[i] == '-') && s == 0)
	{
		if (str[i] == '-')
			sin *= -1;
		i++;
		s++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resl = resl * 10 + (str[i] - 48);
		i++;
	}
	return (resl * sin);
}

int	ft_hex(int n)
{
	int	i;
	int	hex;

	i = 0;
	hex = 1;
	while (i < n)
	{
		hex *= 16;
		i++;
	}
	return (hex);
}

int	ft_arry(char k)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	while (base[i])
	{
		if (base[i] == k)
			return (i);
		i++;
	}
	return (0);
}

int	ft_len_line(int fd)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	i = ft_countword(line, ' ');
	free(line);
	return (i);
}
