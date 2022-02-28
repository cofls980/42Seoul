#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> //delete
#include <unistd.h>
#include <stdlib.h> //malloc free

typedef struct		s_list
{
	int		value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_info
{
	int pivot1;
	int pivot2;
	int ra;
	int rb;
	int pb;
	int pa;
}					t_info;

void    stack_push(t_list **st, t_list *new);
t_list     *new_item(int val);
void    print_all(t_list **st);
t_list    *stack_pop(t_list **st);
void    delete_item(t_list *item);
void    swap(t_list **lst, char stack_name, int *cnt);
void    push_ab(t_list **from, t_list **to, char stack_name, int *cnt);
void    rotate(t_list **lst, char stack_name, int *cnt);
void    reverse_rotate(t_list **lst, char stack_name, int *cnt);
int is_empty(t_list **st);
void    atob(t_list **a, t_list **b, int n, int *cnt);
void    btoa(t_list **b, t_list **a, int n, int *cnt);
//void    sorting(t_list **st, int n, char flag, int *cnt);
void    sorting_under_three_a(t_list **st, int n, int *cnt);
void    sorting_under_three_b(t_list **st, int n, int *cnt);
int find_max(t_list **st, int n);
int find_min(t_list **st, int n);
void    sorting_five_a(t_list **from, t_list **to, int *cnt);
void    sorting_five_b(t_list **from, t_list **to, int *cnt);
void    display(char *command, char stack_name);
void    rrr(t_list **a, t_list **b, int ra, int rb, int *cnt);
void    sort_1(t_list **st, int *cnt, char stack_name);
void    sort_2(t_list **st, int *cnt, char stack_name);
void    sort_3(t_list **st, int *cnt, char stack_name);
void    sort_4(t_list **st, int *cnt, char stack_name);
void    sort_5(t_list **st, int *cnt, char stack_name);
void    sorting_five(t_list **from, t_list **to, int *cnt, char stack_name);
char	**ft_split(char const *s, char c);
int is_sorted(t_list **st, int n);
int is_duplicated(t_list **st);
int ft_cnt(char **str);
int is_number(char *str);
long long make_number(char *str);
void    free_stack(t_list **a, t_list **b);
void    free_str(char **str);
//int is_all_large(t_list **st, int n, int pivot);
int find_max(t_list **st, int n);
int find_min(t_list **st, int n);
int find_pivot(int min, int max, double op);
int check_atob(t_list **st1, t_list **st2, int n, int *cnt);
int check_btoa(t_list **st1, t_list **st2, int n, int *cnt);

#endif