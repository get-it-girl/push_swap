#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>

void	sa(t_list **head, int flag);
void	pb(t_list **a, t_list **b, int flag);
void	ra(t_list **head);
void	rra(t_list **head);
void	rotate_b(t_list *value, int **ras);
int		get_b_score(t_all_list *lists, int value);
int		get_a_score_1(t_all_list *lists, int value);
int		get_a_score_2(t_all_list *lists, int value);
void	fill_score(t_all_list *lists);
t_list	*get_score_value(t_all_list *lists);
int		check_last(t_list **head, int value);
void	sortir(t_all_list *lists, int mid);
void	sort(int *num, int argc);
int		midl(char *argv[], int **mmm, t_list **head);
void	separate(t_list **a, t_list **b, int *mmm);
void	rotate_a(t_list *value, int **ras);
void	get_ras_2(t_all_list *lists, int **ras);
void	get_ras_1(t_all_list *lists, int **ras);
int		get_min(int a, int b);
void	int_get_ra(t_all_list *lists);
void	int_get_rra(t_all_list *lists);
void	small_sort(t_all_list *lists);
void	get_push_back(t_all_list *lists);
void	search_max(t_all_list *lists);
void	write_com(int i, int count, int min, t_all_list *lists);
void	write_com_max(int i, int count, int max, t_all_list *lists);
int		get_swap(t_list **head);
void	sort_2(t_all_list *lists);
int		check_integer(char *c);
int		check_repeat(int *num, int size);
char	**arg_oper(char *argv[]);
int		get_count(char *argv[]);
int		get_command(char *c, t_all_list *lists);
void	sa_1(t_list **head, int flag);
void	pb_1(t_list **a, t_list **b, int flag);
void	ra_1(t_list **head);
void	rra_1(t_list **head);
int		dop(int **num, int *i, t_list **head, char **argv);
int		extra_push(char *c, t_all_list *lists);
void	rrr_1(t_all_list *lists);
void	rr_1(t_all_list *lists);
int		extra_main(char **c, t_all_list *lists);

#endif