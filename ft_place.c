/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtudes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:54:27 by vtudes            #+#    #+#             */
/*   Updated: 2017/11/27 09:50:25 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

static char		ft_size_map(int tetri)
{
	int		nb;
	int		map;

	nb = tetri * 4;
	map = 1;
	if (tetri <= 0 || tetri > 26)
		return (0);
	while (map * map < nb)
		map++;
	return (map);
}

static t_param	ft_put_top_left_1(t_param param, int a, int tmp_i, int tmp_j)
{
	param.i[a - 4] = param.i[a - 4] - tmp_i;
	param.j[a - 4] = param.j[a - 4] - tmp_j;
	param.i[a - 3] = param.i[a - 3] - tmp_i;
	param.j[a - 3] = param.j[a - 3] - tmp_j;
	param.i[a - 2] = param.i[a - 2] - tmp_i;
	param.j[a - 2] = param.j[a - 2] - tmp_j;
	param.i[a - 1] = param.i[a - 1] - tmp_i;
	param.j[a - 1] = param.j[a - 1] - tmp_j;
	return (param);
}

static t_param	ft_put_top_left(t_param param, int nb_tetri)
{
	int		a;
	int		tmp_i;
	int		tmp_j;

	a = 0;
	while (a < (nb_tetri * 4) + 1)
	{
		if (a % 4 == 0 && a != 0)
			param = ft_put_top_left_1(param, a, tmp_i, tmp_j);
		if (a % 4 == 0)
		{
			tmp_i = param.i[a];
			tmp_j = param.j[a];
			a++;
		}
		if (a % 4 != 0)
		{
			if (param.i[a] < tmp_i)
				tmp_i = param.i[a];
			if (param.j[a] < tmp_j)
				tmp_j = param.j[a];
		}
		a++;
	}
	return (param);
}

static t_param	ft_keep_mem(char **tetri, int nb)
{
	int			i;
	int			j;
	t_param		param;

	i = -1;
	param.a = 0;
	if ((!(param.i = (int*)ft_memalloc(sizeof(int) * (nb * 5))))
	|| (!(param.j = (int*)ft_memalloc(sizeof(int) * (nb * 5)))))
		exit(1);
	while (++i < nb * 4)
	{
		j = -1;
		while (++j < 5)
		{
			if (tetri[i][j] == '#')
			{
				param.i[param.a] = i % 4;
				param.j[param.a++] = j;
			}
		}
	}
	free(tetri);
	return (param);
}

void			ft_place(char **tetri, int nb)
{
	char		**map;
	t_param		param;
	int			size_map;

	size_map = ft_size_map(nb);
	map = ft_map(size_map);
	param = ft_keep_mem(tetri, nb);
	param = ft_put_top_left(param, nb);
	param.a = 0;
	while (ft_algo(param, nb, ft_map(size_map++)) == 0)
		;
}
