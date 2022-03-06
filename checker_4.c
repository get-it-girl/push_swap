#include "push_swap.h"
#include "get_next_line.h"

int	get_count(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	rrr_1(t_all_list *lists)
{
	rra_1(&((*lists).head));
	rra_1(&((*lists).b));
}

void	rr_1(t_all_list *lists)
{
	ra_1(&((*lists).head));
	ra_1(&((*lists).b));
}

int	extra_push(char *c, t_all_list *lists)
{
	if (ft_strncmp(c, "ra", 3) == 0)
		ra_1(&((*lists).head));
	else if (ft_strncmp(c, "rb", 3) == 0)
		ra_1(&((*lists).b));
	else if (ft_strncmp(c, "rra", 4) == 0)
		rra_1(&((*lists).head));
	else if (ft_strncmp(c, "rrb", 4) == 0)
		rra_1(&((*lists).b));
	else if (ft_strncmp(c, "sa", 3) == 0)
		sa_1(&((*lists).head), 'l');
	else if (ft_strncmp(c, "sb", 3) == 0)
		sa_1(&((*lists).b), 'l');
	else if (ft_strncmp(c, "pa", 3) == 0)
		pb_1(&((*lists).b), &((*lists).head), 'l');
	else if (ft_strncmp(c, "pb", 3) == 0)
		pb_1(&((*lists).head), &((*lists).b), 'l');
	else if (ft_strncmp(c, "rr", 3) == 0)
		rr_1(lists);
	else if (ft_strncmp(c, "rrr", 4) == 0)
		rrr_1(lists);
	else
		return (1);
	return (0);
}

int	get_command(char *c, t_all_list *lists)
{
	if (extra_push(c, lists) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
