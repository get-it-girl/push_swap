#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		count;

	count = 1;
	cur = lst;
	if (cur == NULL)
		return (0);
	while (cur -> next != NULL)
	{
		cur = cur -> next;
		count++;
	}
	return (count);
}
