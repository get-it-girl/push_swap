#include "push_swap.h"
#include "get_next_line.h"

int	check_sort(t_list **head)
{
	int	i;
	int	size;

	i = 1;
	size = ft_lstsize((*head));
	while ((*head))
	{
		if ((*head)->next && (*head)->content < (*head)->next->content)
			i++;
		(*head) = (*head)->next;
	}
	if (i == size)
		return (1);
	return (0);
}

int	extra_main(char **c, t_all_list *lists)
{
	*c = get_next_line(0);
	while (*c)
	{
		if (get_command(*c, lists) == 0)
			*c = get_next_line(0);
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char		*c;
	int			*mmm;
	t_all_list	lists;

	if (argc == 1)
		return (0);
	mmm = malloc (sizeof(int) * 3);
	if (!mmm)
		return (0);
	if (midl(argv, &mmm, &(lists.head)) == 1)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (extra_main(&c, &lists) == 0)
		return (0);
	if (check_sort(&(lists).head) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&lists.head);
	free(mmm);
	return (0);
}
