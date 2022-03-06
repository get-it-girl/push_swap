#include "push_swap.h"

int	get_swap(t_list **head)
{
	int	a;
	int	b;
	int	c;

	if (ft_lstsize((*head)) == 3)
	{
		a = (*head)->content;
		b = (*head)->next->content;
		c = (*head)->next->next->content;
		if ((a > b && a < c && b < c)
			|| (a > b && a > c && b > c)
			|| (a < c && a < b && b > c))
			return (1);
	}
	return (0);
}

void	write_com_max(int i, int count, int max, t_all_list *lists)
{
	if (i / 2 < count)
	{	
		while ((*lists).head -> content != max)
		{
			rra(&(*lists).head);
			write (1, "rra\n", 4);
		}
	}
	else
	{
		while ((*lists).head -> content != max)
		{
			ra(&(*lists).head);
			write (1, "ra\n", 3);
		}
	}
}

void	search_max(t_all_list *lists)
{
	int		max;
	int		i;
	t_list	*cur;
	int		count;

	i = 0;
	count = 0;
	max = (*lists).head -> content;
	cur = (*lists).head;
	while ((cur))
	{
		if (cur -> content > max)
		{
			max = cur -> content;
			count = i;
		}
		cur = cur -> next;
		i++;
	}
	write_com_max(i, count, max, lists);
	pb(&(*lists).head, &(*lists).b, 'b');
}

void	sort_2(t_all_list *lists)
{
	if ((*lists).head -> content > (*lists).head -> next -> content)
		sa(&(*lists).head, 'a');
}
