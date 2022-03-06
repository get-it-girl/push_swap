#include "push_swap.h"

int	check_integer(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if ((c[i] < 48 || c[i] > 57)
			&& c[i] != '-' && c[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	check_repeat(int *num, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (num[j] == num[i] && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
