/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:07:29 by yyefimov          #+#    #+#             */
/*   Updated: 2016/12/23 17:22:36 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_abs(int x, int y, int a, int b)
{
	int res1;
	int res2;

	res1 = x - a;
	res2 = y - b;
	if (res1 < 0)
		res1 = -res1;
	if (res2 < 0)
		res2 = -res2;
	return (res1 + res2);
}

int	check_tab(int *tab)
{
	int	d;
	int	x;
	int	y;
	int	i;
	int	j;

	d = 0;
	i = 0;
	while (i < 4)
	{
		x = tab[2 * i];
		y = tab[2 * i + 1];
		j = 0;
		while (j < 4)
		{
			if (ft_abs(x, y, tab[2 * j], tab[2 * j + 1]) == 1)
				d++;
			j++;
		}
		i++;
	}
	if (d >= 6)
		return (0);
	return (1);
}

int	ft_check_tetr(char **tet, int n, int j)
{
	int	tab[8];
	int	k;

	k = 0;
	j = 0;
	while (tet[0][j] != '\0')
	{
		if ((tet[0][j] != '#' && tet[0][j] != '.' && tet[0][j] != '\n')
			|| ( tet[0][0] != '.' && tet[0][0] != '#'))
			return (1);
		if (tet[0][j] == '#')
		{
			tab[2 * n] = j / 5;
			tab[2 * n + 1] = j % 5;
			n++;
		}
		if (tet[0][j] == '.')
			k++;
		if (n > 4)
			break ;
		j++;
	}
	if (n == 4 && k == 12)
	{
		if (check_tab(tab) == 0)
			return (0);
	}
	return (1);
}
