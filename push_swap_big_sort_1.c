#include "push_swap.h"

void	rotate_b(t_list *value, int **ras)
{
	int	one;
	int	two;

	one = value->score_b;
	two = value->score_b;
	(*ras)[1] = 0;
	(*ras)[3] = 0;
	if (value -> score_b < 0)
	{
		while (one < 0)
		{
			(*ras)[3]++;
			one++;
		}	
	}
	else
	{
		while (two > 0)
		{
			(*ras)[1]++;
			two--;
		}
	}
}

int	get_b_score(t_all_list *lists, int value)
{
	int		count_b_1;
	int		count_b_2;
	t_list	*cur;

	count_b_1 = 0;
	count_b_2 = 0;
	cur = (*lists).b;
	while (cur)
	{
		count_b_2++;
		cur = cur -> next;
	}
	cur = (*lists).b;
	while (cur -> content != value)
	{
		count_b_1++;
		count_b_2--;
		cur = cur -> next;
	}
	if (count_b_1 < count_b_2)
		return (count_b_1);
	return (count_b_2 * -1);
}

int	get_a_score_1(t_all_list *lists, int value)
{
	int		count_a;
	t_list	*cur;
	t_list	*extra;

	count_a = 0;
	cur = (*lists).head;
	extra = (*lists).head;
	while (extra->next)
		extra = extra -> next;
	if (value < cur -> content && extra -> content < value)
		return (0);
	if (cur -> next)
		extra = cur -> next;
	else
		return (count_a);
	while ((!(value > cur->content && extra -> content > value))
		&& cur && extra->next)
	{
		count_a++;
		cur = cur -> next;
		extra = extra -> next;
	}
	count_a++;
	return (count_a);
}

int	get_a_score_2(t_all_list *lists, int value)
{
	int		count_a;
	t_list	*cur;
	t_list	*extra;

	count_a = 0;
	cur = (*lists).head;
	while (cur->next)
	{
		count_a++;
		cur = cur -> next;
	}
	cur = (*lists).head;
	if (cur->next)
		extra = cur->next;
	while (!(value > cur->content && value < extra -> content)
		&& extra->next && cur -> next)
	{
		count_a--;
		cur = cur->next;
		extra = extra->next;
	}
	return (count_a * -1);
}

void	fill_score(t_all_list *lists)
{
	int		value;
	int		count_a;
	int		count_b;
	t_list	*cur;

	cur = (*lists).b;
	while ((*lists).head && cur)
	{
		value = cur->content;
		if (get_a_score_1(lists, value) < get_a_score_2(lists, value) * (-1))
			count_a = get_a_score_1(lists, value);
		else
			count_a = get_a_score_2(lists, value);
		cur->score_a = count_a;
		count_b = get_b_score(lists, value);
		cur->score_b = count_b;
		if (count_b < 0)
			count_b = count_b * -1;
		if (count_a < 0)
			count_a = count_a * -1;
		cur->score = count_a + count_b;
		cur = cur->next;
	}
}
