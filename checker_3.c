#include "push_swap.h"
#include "get_next_line.h"

int	midl(char **argv, int **mmm, t_list **head)
{
	int		*num;
	int		i;

	i = 0;
	num = (int *)malloc(sizeof(int) *(get_count(argv) + 1));
	if (!num)
		return (1);
	if (dop(&num, &i, head, argv) == 1)
		return (1);
	if (check_repeat(num, i) == 1)
		return (1);
	sort(num, i + 1);
	*mmm = NULL;
	free(num);
	return (0);
}

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

void	sort(int *num, int argc)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (num[j - 1] > num[j])
			{
				k = num[j - 1];
				num[j - 1] = num[j];
				num[j] = k;
			}
			j++;
		}
		i++;
	}	
}

char	**arg_oper(char *argv[])
{
	int		i;
	char	**new;

	i = 0;
	new = ft_split(argv[1], ' ');
	return (new);
}
