
#include "fillit.h"

static int	read_arr(int *coor, char **arr)
{
	int	i;
	int	j;
	int k;

	k = 0;
	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] != '.')
			{
				coor[8] = arr[i][j];
				coor[k] = i;
				coor[k + 1] = j;
				k += 2;
				arr[i][j] = '.';
			}
			j++;
		}	
		i++;
	}
	coor[9] = i;
	return (0);
}

static int	change_arr(int *coor, int l, int h)
{
	int i;

	i = 0;
	while (i < 8)
	{
		coor[i] = h + coor[i];
		coor[i + 1] = l + coor[i + 1];
		i += 2;
	}
	return (0);
}

static int	write_arr(char **arr, int *coor)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		arr[coor[i]][coor[i + 1]] = (char)coor[8];
		i += 2;
	}
	return (0);
}

static int	if_safe(int *coor, int *l, int *h)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (*h + coor[i] >= coor[9])
		{
			*h = *h - coor[0] - 1;
			return (1);
		}
		if (*l + coor[i + 1] < 0)
		{
			(*l)++;
			return (1);
		}
		if (*l + coor[i + 1] >= coor[9])
		{
			*l = coor[9] * -1;
			(*h)++;
			return (1);
		}
		i += 2;
	}
	return (0);
}

int		move_side(char **arr)
{
	int		coor[10];
	int		i;
	int		l;
	int		h;

	l = 1;
	h = 0;
	i = 0;
	read_arr(&coor[0], arr);
	while (if_safe(&coor[0], &l, &h) != 0)
	{
	}
	change_arr(&coor[0], l, h);
	write_arr(arr, &coor[0]);
	return (0);
}
