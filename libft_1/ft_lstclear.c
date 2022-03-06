#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*cur;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		cur = (*lst)-> next;
		ft_lstdelone(*lst);
		(*lst) = cur;
	}
}
