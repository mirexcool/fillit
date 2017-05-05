/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:10:24 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/22 18:20:41 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

int		ft_fillit(char *file, int i);
int		make_arrays(char **tet, int s, int i);
char	**ft_mkarray(int row, int col);
int		move_side(char **arr);
int		solve_tet(char ***arr, int s);
int		ft_strcat_array(char **from, char **into);
int		ft_check_tetr(char **tet, int n, int j);

#endif
