/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:39:01 by lkazaz            #+#    #+#             */
/*   Updated: 2024/01/18 09:33:26 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	ft_convert(char *str)
{
	int		resl;
	int		i;
	int		len;
	int		pro;
	char	c;

	if (!str)
		return (0);
	len = ft_strlen(str);
	i = 0;
	resl = 0;
	pro = 0;
	while (str[i])
	{
		if (str[i] > 96 && str[i] < 123)
			c = str[i] - 32;
		else
			c = str[i];
		pro = ft_hex(len - i - 1);
		resl += ft_arry(c) * pro;
		i++;
	}
	return (resl);
}

int	get_dots_from_line(char *line, t_pix **matrix_of_dots, int y)
{
	char	**dots;
	char	**li;
	int		x;

	li = ft_split(line, '\n');
	dots = ft_split(*li, ' ');
	x = 0;
	while (dots[x])
	{
		ft_isalnum(dots[x]);
		matrix_of_dots[y][x].color = ft_convert(ft_strchr1(dots[x], 'x'));
		if (ft_atoi(dots[x]) > INT_MAX || ft_atoi(dots[x]) < INT_MIN)
			ft_error("N9asss7, rah fti rang int,");
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].lakhir = 0;
		free(dots[x++]);
	}
	free(dots);
	free_matrix(li);
	matrix_of_dots[y][--x].lakhir = 1;
	return (x);
}

int	ft_countword(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

t_pix	**memory_allocete(char *file_name)
{
	t_pix	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	new = NULL;
	fd = open(file_name, O_RDONLY);
	x = ft_len_line(fd);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	new = ft_aloc(x, y, new);
	close(fd);
	return (new);
}

t_pix	**read_map(char *file_name)
{
	t_pix	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = memory_allocete(file_name);
	fd = open(file_name, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		get_dots_from_line(line, matrix_of_dots, y++);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}
