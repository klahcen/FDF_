/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   song.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:24:36 by lkazaz            #+#    #+#             */
/*   Updated: 2024/01/20 14:38:31 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
#include <signal.h>
#include <sys/types.h>
#include <time.h>

void	song(int key)
{
	int	a;

	a = fork();
	key++;
	if (a == 0)
	{
		system("afplay ./rrr.mp3");
	}
	usleep(1000);
	kill(a, SIGKILL);
}

char	*ft_strrchr(char *str, int a)
{
	char			*c;
	unsigned char	l;
	int				i;

	i = 0;
	c = (char *)str;
	l = (unsigned char)a;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (c[i] == l)
			return (c + i + 1);
		i--;
	}
	if (l != 0)
		return (0);
	return (c);
}

void	ft_fdf(char *str)
{
	char	*a;
	int		i;
	char	*d;

	i = 0;
	d = "fdf";
	if (str[0] == '.')
		ft_error("hehe, Ta gad name file");
	a = ft_strrchr(str, '.');
	if (!a)
		ft_error("Ta fin hiya .fdf");
	while (a[i])
	{
		if (a[i] != d[i])
			ft_error("Ta fin hiya .fdf");
		i++;
	}
}

void	error_syntax(char *av)
{
	if (!(*av == '+' || *av == '-' || (*av >= '0' && *av <= '9')))
		ft_error("Ta1 gad lmaps1,");
	if ((*av == '+' || *av == '-') && !(av[1] >= '0' && av[1] <= '9'))
		ft_error("Ta2 gad lmaps1,");
	while (*++av)
	{
		if (!(*av >= '0' && *av <= '9'))
			ft_error("Ta3 gad lmaps1,");
	}
}

void	ft_isalnum(char *str)
{
	char	*a;
	int		i;

	i = 0;
	if (!str || str[0] == ' ' || str[0] == '\n')
		ft_error("Ta gad lmaps1,");
	a = malloc(ft_strlen(str) + 1);
	if (!a)
		return ;
	while (str[i] && str[i] != 32)
	{
		if (!(str[i] == ','))
			a[i] = str[i];
		else
			break ;
		i++;
	}
	a[i] = '\0';
	error_syntax(a);
	free(a);
}
