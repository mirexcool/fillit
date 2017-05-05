
#include "fillit.h"

static void	find_start(char *tet, int *l, int *h)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	*l = 5;
	*h = 0;
	while (tet[i] != '\0')
	{
		if (tet[i] == '#' && f == 0)
		{
			*h = i / 5;
			f++;
		}
		if (tet[i] == '#' && *l > i % 5)
			*l = i % 5;
		i++;
	}
}

static void	rewrite(char *tet, char **arr, char k)
{
	int		j;
	int		l;
	int		h;
	int		c;

	j = 0;
	c = 0;
	find_start(tet, &l, &h);
	while (tet[j] != '\0')
	{
		if (tet[j] == '.')
			c++;
		if (tet[j] == '#')
		{
			arr[c / 4 - h][c % 4 - l] = k;
			c++;
		}
		j++;
	}
}

int		rewrite_arr(char **tet, char ***arr)
{
	char	k;
	int		i;

	i = 0;
	while (tet[i] != NULL)
	{
		k = i + 'A';
		rewrite(tet[i], arr[i], k);
		i++;
	}
	return (0);
}

int		make_arrays(char **tet, int s, int i)
{
	int		t;
	char	***arr;

	t = 0;
	arr = (char***)malloc(sizeof(char**) * (i + 1));
	if (!arr)
		return (1);
	while (t < i)
	{
		arr[t] = ft_mkarray(s, s);
		if (arr[t] == NULL)
			return (1);
		t++;
	}
	arr[t] = NULL;
	if (rewrite_arr(tet, arr) != 0)	
		return (1);
	if (solve_tet(arr, s) != 0)
		return (1);
	return (0);
}
