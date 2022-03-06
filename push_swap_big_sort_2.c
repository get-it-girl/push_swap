#include "push_swap.h"

int	check_last(t_list **head, int value)
{
	t_list	*cur;

	cur = *head;
	while (cur -> next != NULL && cur)
		cur = cur -> next;
	if (cur -> content < value)
		return (1);
	return (0);
}

int	get_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	get_ras_1(t_all_list *lists, int **ras)
{
	int	min;
	int	i;

	i = 0;
	min = get_min((*ras)[0], (*ras)[1]);
	while (i < min && (*ras)[0] > 0 && (*ras)[1] > 0)
	{
		ra(&(*lists).head);
		ra(&(*lists).b);
		write(1, "rr\n", 3);
		i++;
	}
	while ((*ras)[0] > min)
	{
		ra(&(*lists).head);
		write(1, "ra\n", 3);
		(*ras)[0]--;
	}
	while ((*ras)[1] > min)
	{
		ra(&(*lists).b);
		write(1, "rb\n", 3);
		(*ras)[1]--;
	}
}

void	get_ras_2(t_all_list *lists, int **ras)
{
	int	min;
	int	i;

	i = 0;
	min = get_min((*ras)[2], (*ras)[3]);
	while (i < min && (*ras)[2] > 0 && (*ras)[3] > 0)
	{
		rra(&(*lists).head);
		rra(&(*lists).b);
		write(1, "rrr\n", 4);
		i++;
	}
	while ((*ras)[2] > min)
	{
		rra(&(*lists).head);
		write(1, "rra\n", 4);
		(*ras)[2]--;
	}
	while ((*ras)[3] > min)
	{
		rra(&(*lists).b);
		write(1, "rrb\n", 4);
		(*ras)[3]--;
	}
}

t_list	*get_score_value(t_all_list *lists)
{
	t_list	*value;
	int		sc;
	t_list	*cur;

	sc = (*lists).b -> score;
	value = (*lists).b;
	cur = (*lists).b -> next;
	while (cur)
	{
		if (cur -> score < sc)
		{
			value = cur;
			sc = cur -> score;
		}
		cur = cur -> next;
	}
	return (value);
}
