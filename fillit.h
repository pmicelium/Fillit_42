/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:59:50 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/27 09:32:44 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 22

typedef struct	s_param
{
	int			*i;
	int			*j;
	int			a;
}				t_param;

int				ft_parse(char *buff);
void			ft_place(char **tetri, int nb);
char			**ft_solver(char **map, char **tetri, t_param param, int nb);
int				ft_algo(t_param param, int tetri, char **map);
char			**ft_map(int size);

#endif
