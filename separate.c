#include "push_swap.h"

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

int	get_count(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	dop(int **num, int *i, t_list **head, char **argv)
{
	char	**diff;
	t_list	*new;

	*head = NULL;
	if (get_count(argv) == 2)
		diff = arg_oper(argv);
	else
		diff = &argv[(*i) + 1];
	while (diff[*i])
	{
		if (check_integer(diff[*i]) == 1
			|| ft_atoi(diff[*i], &(*num)[*i]) == 1)
		{
			free(*num);
			return (1);
		}
		new = ft_lstnew((*num)[*i]);
		ft_lstadd_back(head, new);
		(*i)++;
	}
	return (0);
}

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
	(*mmm)[0] = num[i + 1 - 2];
	(*mmm)[1] = num[0];
	(*mmm)[2] = num[(i + 1 - 2) / 2];
	free(num);
	return (0);
}
