/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:28:15 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/27 09:31:41 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char			**ft_map(int size)
{
	int		i;
	char	**tab;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	while (i < size)
	{
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char) * (size + 1))))
			return (0);
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
