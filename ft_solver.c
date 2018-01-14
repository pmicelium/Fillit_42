/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:59:42 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/27 09:49:08 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

static int		ft_check(char **tab, t_param param, int i, int j)
{
	int		size;
	int		a;

	a = param.a;
	size = ft_strlen(tab[i]);
	if ((i + param.i[a] < size && j + param.j[a] < size)
	&& (i + param.i[a + 1] < size && j + param.j[a + 1] < size)
	&& (i + param.i[a + 2] < size && j + param.j[a + 2] < size)
	&& (i + param.i[a + 3] < size && j + param.j[a + 3] < size))
	{
		if ((tab[i + param.i[a]][j + param.j[a]])
		&& (tab[i + param.i[a + 1]][j + param.j[a + 1]])
		&& (tab[i + param.i[a + 2]][j + param.j[a + 2]])
		&& (tab[i + param.i[a + 3]][j + param.j[a + 3]])
		&& (tab[i + param.i[a]][j + param.j[a]] == '.')
		&& (tab[i + param.i[a + 1]][j + param.j[a + 1]] == '.')
		&& (tab[i + param.i[a + 2]][j + param.j[a + 2]] == '.')
		&& (tab[i + param.i[a + 3]][j + param.j[a + 3]] == '.'))
			return (1);
	}
	return (0);
}

static char		**ft_rm_tetri(char **map, int k)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	c = 65 + k;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

static char		**ft_place_tetri(char **tab, t_param param, int i, int j)
{
	int		k;
	int		a;

	a = param.a;
	k = a / 4;
	tab[i + param.i[a]][j + param.j[a]] = 65 + k;
	tab[i + param.i[a + 1]][j + param.j[a + 1]] = 65 + k;
	tab[i + param.i[a + 2]][j + param.j[a + 2]] = 65 + k;
	tab[i + param.i[a + 3]][j + param.j[a + 3]] = 65 + k;
	return (tab);
}

static int		ft_end_algo(char **map, t_param param)
{
	ft_printtab_char(map);
	ft_free_tab(map);
	free(param.i);
	free(param.j);
	return (1);
}

int				ft_algo(t_param param, int nb_tetri, char **map)
{
	int		i;
	int		j;

	i = -1;
	if ((param.a / 4) >= nb_tetri)
		return (ft_end_algo(map, param));
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_check(map, param, i, j) == 1 && param.a < nb_tetri * 4)
			{
				map = ft_place_tetri(map, param, i, j);
				param.a = param.a + 4;
				if (ft_algo(param, nb_tetri, map) == 1)
					return (1);
				param.a = param.a - 4;
				map = ft_rm_tetri(map, param.a / 4);
			}
		}
	}
	return (0);
}
