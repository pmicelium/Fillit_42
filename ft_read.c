/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:44:15 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/27 09:45:26 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <fcntl.h>

static int		ft_count(char *argv)
{
	int		fd;
	char	buff[BUFF_SIZE];
	int		ret;
	int		nb;

	nb = 0;
	if (!(fd = open(argv, O_RDONLY)))
		return (0);
	while ((ret = read(fd, buff, BUFF_SIZE - 1)))
		nb++;
	return (nb);
}

static char		**ft_read(char *argv)
{
	int		fd;
	char	buff[BUFF_SIZE];
	int		ret;
	char	*tetri;

	tetri = ft_strjoin("\0", "\0");
	if (!(fd = open(argv, O_RDONLY)))
		return (0);
	while ((ret = read(fd, buff, BUFF_SIZE - 1)))
	{
		buff[ret] = '\0';
		if (ft_parse(buff) == 1)
			tetri = ft_strjoin(tetri, buff);
		else
			return (0);
	}
	if (tetri[0] == '\0')
		return (0);
	if (tetri[ft_strlen(tetri) - 1] == 10 && tetri[ft_strlen(tetri) - 2] == 10)
		return (0);
	close(fd);
	return (ft_strsplit(tetri, '\n'));
}

int				main(int argc, char *argv[])
{
	char	**str;
	int		nb_tetri;

	if (argc != 2)
	{
		ft_putendl("usage : run the program with a single file that contains");
		ft_putendl("no more than 26 pieces of tetris written in this form :");
		ft_putstr("\n##..\n##..\n....\n....\n\n");
		return (write(1, "error\n", 6));
	}
	str = ft_read(argv[1]);
	if (str == 0)
		return (write(1, "error\n", 6));
	nb_tetri = ft_count(argv[1]);
	ft_place(str, nb_tetri);
	return (0);
}
