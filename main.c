/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:58:27 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/22 19:48:24 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	return (0);
}

static int	error(void)
{
	ft_putendl("error");
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		return (usage());
	if (ft_fillit(*(argv + 1), 0) != 0)
		return (error());
	return (0);
}
