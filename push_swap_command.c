#include "push_swap.h"

void	sa(t_list **head, int flag)
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

void	pb(t_list **a, t_list **b, int flag)
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

void	ra(t_list **head)
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

void	rra(t_list **head)
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
