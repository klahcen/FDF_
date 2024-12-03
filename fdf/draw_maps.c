/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:56:22 by lkazaz            #+#    #+#             */
/*   Updated: 2024/01/16 21:28:32 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

float	fmodule(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float	ft_max(float i, float j)
{
	if (i > j)
		return (i);
	return (j);
}

int	ft_color(float a)
{
	if (a > 0)
		return (0xFF0000);
	else if (a == 0)
		return (0x006400);
	else
		return (0x0000FF);
}

void	line(t_pix a, t_pix b, t_pix *param, t_data data)
{
	float	step_x;
	float	step_y;
	float	max;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = ft_max(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	if (a.color == 0)
		a.color = ft_color(a.z);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x > param->win_x - 1 || a.y > param->win_y - 1 || a.y < 0
			|| a.x < 0)
			return ;
		my_mlx_pixel_put(&data, a.x, a.y, a.color);
		a.x += step_x;
		a.y += step_y;
	}
}

void	draw(t_pix **matrix)
{
	int		y;
	int		x;
	t_data	data;

	y = 0;
	data.img = mlx_new_image(PRM[0][0].mlx_ptr, 1290, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], &PRM[0][0], data);
			if (!matrix[y][x].lakhir)
				line(matrix[y][x], matrix[y][x + 1], &PRM[0][0], data);
			if (matrix[y][x].lakhir)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(PRM[0][0].mlx_ptr, PRM[0][0].win_ptr, data.img, 0,
		0);
}
