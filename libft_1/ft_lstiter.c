#include"libft.h"

void	ft_lstiter(t_list *lst)
{
	t_list	*cur;

	cur = lst;
	if (lst == NULL)
		return ;
	while (cur)
	{
		cur = cur -> next;
	}
}
