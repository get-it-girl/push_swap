#include "push_swap.h"
#include "get_next_line.h"

void	sa_1(t_list **head, int flag)
{
	t_list	*cur;

	if ((*head) && (*head)->next)
	{
		cur = (*head)->next;
		(*head)->next = cur -> next;
		ft_lstadd_front(head, cur);
	}
	if (flag != 'l')
	{
		if (flag == 'a')
			write(1, "sa\n", 3);
		if (flag == 'b')
			write(1, "sb\n", 3);
	}
}

void	pb_1(t_list **a, t_list **b, int flag)
{
	t_list	*cur;

	if (*a)
	{
		cur = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, cur);
	}
	if (flag != 'l')
	{
		if (flag == 'a')
			write(1, "pa\n", 3);
		if (flag == 'b')
			write(1, "pb\n", 3);
	}
}

void	ra_1(t_list **head)
{
	t_list	*cur;

	if (*head)
	{
		cur = *head;
		if ((*head)->next)
		{
			*head = (*head)->next;
			cur->next = NULL;
			ft_lstadd_back(head, cur);
		}
	}
}

void	rra_1(t_list **head)
{
	t_list	*cur;
	t_list	*extra;

	if (*head != NULL && (*head)->next != NULL)
	{
		cur = (*head);
		while (cur->next && cur->next->next != NULL)
			cur = cur -> next;
		extra = cur->next;
		cur->next = NULL;
		ft_lstadd_front(head, extra);
	}
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
