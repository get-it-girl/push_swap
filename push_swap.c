/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:51:20 by wmika             #+#    #+#             */
/*   Updated: 2021/12/27 14:52:46 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	separate(t_list **a, t_list **b, int *mmm)
{
	while (ft_lstsize(*a) > 2)
	{
		if ((*a)->content != mmm[1] && (*a)->content != mmm[0])
			pb(a, b, 'b');
		else
		{
			ra(a);
			write(1, "ra\n", 3);
		}
		if (*b && (*b)->content > mmm[2])
		{
			ra(b);
			write(1, "rb\n", 3);
		}
	}
}

int	main(int argc, char	*argv[])
{
	int			*mmm;
	t_all_list	lists;

	if (argc == 1)
		return (0);
	mmm = malloc (sizeof(int) * 3);
	if (!mmm)
		return (0);
	if (midl(argv, &mmm, &(lists.head)) == 1)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (ft_lstsize(lists.head) > 5)
	{
		separate(&(lists.head), &(lists.b), mmm);
		sortir(&lists, mmm[2]);
	}
	else if (ft_lstsize(lists.head) == 2)
		sort_2(&lists);
	else if (ft_lstsize(lists.head) != 1)
		small_sort(&lists);
	ft_lstclear(&lists.head);
	free(mmm);
	return (0);
}
