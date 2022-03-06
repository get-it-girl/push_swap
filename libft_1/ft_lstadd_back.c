#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*longo;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	longo = (*lst);
	while (longo-> next)
		longo = longo-> next;
	longo-> next = new;
}
