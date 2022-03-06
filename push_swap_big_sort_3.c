#include "push_swap.h"

void	int_get_ra(t_all_list *lists)
{
	while ((*lists).head
		&& (*lists).head -> content < (*lists).head -> next -> content)
	{
		ra(&((*lists).head));
		write(1, "ra\n", 3);
	}
	ra(&((*lists).head));
	write(1, "ra\n", 3);
}

void	int_get_rra(t_all_list *lists)
{
	t_list	*cur;

	cur = (*lists).head;
	while (cur -> next != NULL)
		cur = cur -> next;
	while ((*lists).head
		&& (*lists).head -> content > cur -> content)
	{
		rra(&((*lists).head));
		write(1, "rra\n", 4);
		cur = (*lists).head;
		while (cur -> next != NULL)
			cur = cur -> next;
	}
}

void	sortir(t_all_list *lists, int mid)
{
	t_list	*value;
	t_list	*cur;
	int		*ras;

	if (ft_lstsize((*lists).head) > 1)
	{
		while ((*lists).head && (*lists).b)
		{
			fill_score (lists);
			value = get_score_value(lists);
			cur = (*lists).b;
			ras = malloc (sizeof(int) * 4);
			rotate_b(value, &ras);
			rotate_a(value, &ras);
			get_ras_1(lists, &ras);
			get_ras_2(lists, &ras);
			pb(&((*lists).b), &((*lists).head), 'a');
			free(ras);
		}
		if ((*lists).head -> content > mid)
			int_get_ra(lists);
		else
			int_get_rra(lists);
	}
}

void	rotate_a(t_list *value, int **ras)
{
	int	one;
	int	two;

	one = value->score_a;
	two = value->score_a;
	(*ras)[2] = 0;
	(*ras)[0] = 0;
	if (value -> score_a < 0)
	{
		while (one < 0)
		{
			(*ras)[2]++;
			one++;
		}	
	}
	else
	{
		while (two > 0)
		{
			(*ras)[0]++;
			two--;
		}
	}
}
