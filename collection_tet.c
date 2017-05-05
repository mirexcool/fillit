
#include "fillit.h"

static	int	is_safe(char **from, char **into)
{
	int		i;
	int 	j;

	i = 0;
	while (into[i] != NULL)
	{
		j = 0;
		while (into[i][j] != '\0')
		{
			if (from[i][j] != '.' && into[i][j] != '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	write_arr(char **from, char **into)
{
	int		i;
	int 	j;

	i = 0;
	while (into[i] != NULL)
	{
		j = 0;
		while (into[i][j] != '\0')
		{
			if (from[i][j] != '.')
				into[i][j] = from[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

char	**solve_all(char ***arr, int s, char **into)
{
	int		max;
	char	**buf;
	char	**into_new;

	into_new = ft_mkarray(s, s);
	if (into != NULL)
	{
		ft_strcat_array(into, into_new);
		write_arr(*arr, into_new);
		arr++;
	}
	max = (s - 1) * (s - 1);
	buf = NULL;
	if (*arr != NULL)
	{
		while (buf == NULL)
		{
			if (is_safe(*arr, into_new) == 0)
			{
				buf = solve_all(arr, s, into_new);
			}
			if (buf == NULL)
			{
				if (max <= 0)
				{
					return (NULL);
				}
				move_side(*arr);
				max--;
			}
		}
	}
	if (buf != NULL)
		return (buf);
	return (into_new);
}

int		solve_tet(char ***arr, int s)
{
	char **finish;

	finish = solve_all(arr, s, NULL);
	if (finish == NULL)
		return (1);
	ft_putstr_array(finish);
	return (0);
}
