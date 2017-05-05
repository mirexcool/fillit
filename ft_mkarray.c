
#include "fillit.h"

static void	clean_str(char *s, int col)
{
	int i;

	i = 0;
	while (i < col)
	{
		s[i] = '.';
		i++;
	}
	s[i] = '\0';
}

char		**ft_mkarray(int row, int col)
{
	int		i;
	char	**arr;

	i = 0;
	if (col == 0 || row == 0)
		return (NULL);
	arr = (char**)malloc(sizeof(char*) * (row + 1));
	if (!arr)
		return (NULL);
	while (i < row)
	{
		arr[i] = (char*)malloc(sizeof(char) * (col + 1));
		if (arr[i] == NULL)
			return (NULL);
		clean_str(arr[i], col);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int			ft_strcat_array(char **from, char **into)
{
	int		i;
	int		j;

	i = 0;
	while (from[i] != NULL)
	{
		j = 0;
		while (from[i][j] != '\0')
		{
			if (from[i][j] != '.')
			{
					into[i][j] = from[i][j];
			}
			j++;
		}
		i++;
	}
	return (0);
}
