/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:24:16 by lkazaz            #+#    #+#             */
/*   Updated: 2024/01/20 14:19:17 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

void	ft_initm0(t_pix *param)
{
	param->scale = 1;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 1;
	param->win_x = 1290;
	param->win_y = 1080;
	param->shift_x = param->win_x / 2;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->win_x, param->win_y,
			"FDF");
}

int	close_window(t_pix *param)
{
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	exit(0);
}

void	valid_map(char *str)
{
	int		fd;
	char	*line;
	int		x;
	int		x1;

	ft_fdf(str);
	fd = open(str, O_RDONLY);
	if (fd <= 0)
		ft_error("file does not exist");
	line = get_next_line(fd);
	if (!line)
		ft_error("No data found.");
	x = ft_countword(line, ' ');
	while (line)
	{
		x1 = ft_countword(line, ' ');
		if (x > x1)
			ft_error("Found wrong line length. Exiting.");
		free(line);
		line = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	t_pix	**matrix;

	if (argc != 2)
		ft_error("usage: ./fdf map.fdf");
	valid_map(*++argv);
	matrix = read_map(*argv);
	ft_initm0(&PRM[0][0]);
	draw(matrix);
	mlx_key_hook(PRM[0][0].win_ptr, mouse_hook, matrix);
	mlx_hook(PRM[0][0].win_ptr, 17, 0, close_window, &PRM[0][0]);
	mlx_loop(PRM[0][0].mlx_ptr);
}
