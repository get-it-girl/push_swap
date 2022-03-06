#include "push_swap.h"

int	get_mininum(t_all_list *lists)
{
	t_list	*cur;
	int		min;

	min = (*lists).head -> content;
	cur = (*lists).head;
	while (cur)
	{
		if (cur -> content < min)
			min = cur -> content;
		cur = cur -> next;
	}
	return (min);
}

void	write_com(int i, int count, int min, t_all_list *lists)
{
	if (i / 2 < count)
	{	
		while ((*lists).head -> content != min)
		{
			rra(&(*lists).head);
			write (1, "rra\n", 4);
		}
	}
	else
	{
		while ((*lists).head -> content != min)
		{
			ra(&(*lists).head);
			write (1, "ra\n", 3);
		}
	}
}

void	comp(t_all_list *lists)
{
	int		min;
	int		count;
	int		i;
	t_list	*cur;

	count = 0;
	i = 0;
	min = (*lists).head -> content;
	cur = (*lists).head;
	while ((cur))
	{
		if (cur -> content < min)
		{
			min = cur -> content;
			count = i;
		}
		cur = cur -> next;
		i++;
	}
	write_com(i, count, min, lists);
}

void	small_sort(t_all_list *lists)
{
	if (ft_lstsize((*lists).head) == 3)
	{
		if (get_swap(&(*lists).head) == 1)
			sa(&(*lists).head, 'a');
		comp(lists);
	}
	else if (ft_lstsize((*lists).head) == 4)
	{
		search_max(lists);
		if (get_swap(&(*lists).head) == 1)
			sa(&(*lists).head, 'a');
		comp(lists);
	}
	else
	{
		search_max(lists);
		search_max(lists);
		if (get_swap(&(*lists).head) == 1)
			sa(&(*lists).head, 'a');
		comp(lists);
	}
	get_push_back(lists);
}

void	get_push_back(t_all_list *lists)
{
	while ((*lists).b)
	{
		pb(&(*lists).b, &(*lists).head, 'a');
		ra(&(*lists).head);
		write(1, "ra\n", 3);
	}
}
