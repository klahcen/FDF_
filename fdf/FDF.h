/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 20:50:32 by lkazaz            #+#    #+#             */
/*   Updated: 2024/01/20 14:26:29 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef PRM
#  define PRM matrix
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_pix
{
	float	x;
	float	y;
	float	z;
	int		lakhir;
	int		color;
	int		scale;
	int		z_scale;
	int		shift_x;
	int		shift_y;
	int		is_isometric;
	double	angle;
	int		win_x;
	int		win_y;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_pix;

/*---------------------libft---------------------------*/
long		ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		**ft_free(char **str, int k);
/*---------------------get_next_line-------------------*/
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
char		*get_next_line(int fd);
/*---------------------FDF_FUNCTION--------------------*/
void		ft_error(char *str);
void		ft_initm0(t_pix *param);
void		draw(t_pix **matrix);
t_pix		**read_map(char *file_name);
t_pix		**memory_allocete(char *file_name);
int			ft_countword(char const *str, char c);
int			get_dots_from_line(char *line, t_pix **matrix_of_dots, int y);
void		do_key(int key, t_pix **matrix);
int			is_key(int key);
void		new_window(t_pix **matrix);
int			deal_key(int key, t_pix **matrix);
void		set_param(t_pix *a, t_pix *b, t_pix *param);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			mouse_hook(int key, t_pix **data);
char		*ft_strchr1(char *str, int a);
int			ft_hex(int n);
int			ft_arry(char k);
t_pix		**ft_aloc(int x, int y, t_pix **new);
int			ft_len_line(int fd);
void		song(int key);
int			ft_convert(char *str);
void		ft_fdf(char *str);
void		ft_isalnum(char *str);
void		free_matrix(char **av);

#endif