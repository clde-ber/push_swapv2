#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int value;
    struct s_list *prec;
    struct s_list *next;
}               t_list;

t_list *push_swap(t_list *empty, t_list *lst, int i, int j);
t_list *ft_sa(t_list *empty, t_list *lst);
int ft_sb(t_list *empty, t_list *lst);
int ss(t_list *empty, t_list *lst);
t_list *ft_pa(t_list *empty, t_list *lst);
t_list *ft_pb(t_list *empty, t_list *lst);
int ft_ra(t_list *empty, t_list *lst);
int ft_rb(t_list *empty, t_list *lst);
int rr(t_list *empty, t_list *lst);
t_list *ft_rra(t_list *empty, t_list *lst);
int ft_rrb(t_list *empty, t_list *lst);
int ft_rrr(t_list *empty, t_list *lst);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void	ft_lstiter(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lstnew(t_list *lst, int value);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list *create_list(t_list *lst, int value, int i, char **av);

#endif