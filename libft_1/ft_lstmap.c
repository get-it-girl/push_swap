#include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(int))
// {
// 	t_list	*new;
// 	t_list	*head;

// 	if (!f || !lst)
// 	{
// 		return (NULL);
// 	}
// 	head = NULL;
// 	while (lst)
// 	{
// 		new = ft_lstnew(f(lst.content));
// 		if (!new)
// 		{
// 			ft_lstclear(&head);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&head, new);
// 		lst = lst -> next;
// 	}
// 	return (head);
// }
