/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:59:57 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/24 16:10:13 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check03_1(char *buff, int i)
{
	int co;

	co = 0;
	if (i % 5 != 0 && buff[i - 1] == '#')
		co++;
	if (i % 5 < 3 && buff[i + 1] == '#')
		co++;
	if (i / 5 < 3 && buff[i + 5] == '#')
		co++;
	if (i / 5 != 0 && buff[i - 5] == '#')
		co++;
	return (co);
}

static int		ft_check03(char *buff)
{
	int		i;
	int		co;

	i = 0;
	co = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			co = co + ft_check03_1(buff, i);
		i++;
	}
	if (co < 5)
		return (0);
	return (1);
}

static int		ft_check02(char *buff)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (buff[i + 1])
	{
		while (buff[i] != '\n')
		{
			j++;
			i++;
		}
		if (j != 4)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

static int		ft_check01(char *buff)
{
	int		i;
	int		p;
	int		h;
	int		n;

	i = 0;
	p = 0;
	h = 0;
	n = 0;
	while (buff[i])
	{
		if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
			return (0);
		if (buff[i] == '.')
			p++;
		if (buff[i] == '#')
			h++;
		if (buff[i] == '\n')
			n++;
		i++;
	}
	if (p != 12 || h != 4 || n < 4)
		return (0);
	return (1);
}

int				ft_parse(char *buff)
{
	if (ft_check01(buff) == 0)
		return (0);
	if (ft_check02(buff) == 0)
		return (0);
	if (ft_check03(buff) == 0)
		return (0);
	return (1);
}
