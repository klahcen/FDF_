/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:29:14 by lkazaz            #+#    #+#             */
/*   Updated: 2024/01/20 15:05:52 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_key1(int key, t_pix **matrix)
{
	if (key == 47)
		PRM[0][0].scale += 1;
	if (key == 43 && PRM[0][0].scale - 1 >= 0)
		PRM[0][0].scale -= 1;
	if (key == 1)
		PRM[0][0].z_scale += 1;
	if (key == 2)
		PRM[0][0].z_scale -= 1;
	if (key == 84)
		PRM[0][0].is_isometric = 1;
}

void	ft_key(int key, t_pix **matrix)
{
	ft_key1(key, matrix);
	if (key == 3)
		PRM[0][0].angle += 45;
	if (key == 4)
		PRM[0][0].angle -= 45;
	if (key == 123)
		PRM[0][0].shift_x -= 10;
	if (key == 124)
		PRM[0][0].shift_x += 10;
	if (key == 126)
		PRM[0][0].shift_y -= 10;
	if (key == 125)
		PRM[0][0].shift_y += 10;
	if (key == 83)
		PRM[0][0].is_isometric = 0;
	if (key == 53)
		exit(0);
}

int	mouse_hook(int key, t_pix **matrix)
{
	mlx_clear_window(PRM[0][0].mlx_ptr, PRM[0][0].win_ptr);
	ft_key(key, matrix);
	draw(matrix);
	return (0);
}

char	*ft_strchr1(char *str, int a)
{
	char			*c;
	unsigned char	l;

	c = (char *)str;
	l = (unsigned char)a;
	while (*c)
	{
		if (*c == l)
			return (++c);
		c++;
	}
	if (l != 0)
		return (0);
	return (c);
}

t_pix	**ft_aloc(int x, int y, t_pix **new)
{
	new = (t_pix **)malloc(sizeof(t_pix *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_pix *)malloc(sizeof(t_pix) * (x + 1));
	return (new);
}
