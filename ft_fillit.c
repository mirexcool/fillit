/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:12:06 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/23 16:35:36 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	make_fillit(int i, char **tet)
{
	int cels;
    int res;

    cels = i * 4;
	if (i < 1)
		return (1);
    res = 2;
    while (res * res < cels)
        res++;
    if (make_arrays(tet, res, i) != 0)
		return (1);
	return (0);
}

static int	make_tet(char **tet_i, int fd)
{
	int 	c;
	char	s;

	c = 0;
	*tet_i = ft_strnew(20);
	if (*tet_i == NULL)
		return (1);
	c = read(fd, *tet_i, 20);
	read(fd, &s, 1);
	if (c == 0)
		return (0);
	if (c < 20  || ft_check_tetr(tet_i, 0, 0) != 0)
		return (1);
	return (c);
}

int			ft_fillit(char *file, int i)
{
	int		c;
	int		fd;
	char	**tet;

	c = 20;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	tet = (char**)malloc(sizeof(char*) * 27);
	if (tet == NULL)
		return (1);
	while (c == 20)
	{
		c = make_tet(&tet[i], fd);
		if (c == 1)
			return (1);
		i++;
	}
	i--;
	tet[i] = NULL;
	if (make_fillit(i, tet) != 0)
		return (1);
	return (0);
}
