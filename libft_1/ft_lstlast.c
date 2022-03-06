#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur;

	cur = lst;
	if (cur == NULL)
		return (NULL);
	while (cur -> next != NULL)
		cur = cur -> next;
	return (cur);
}
