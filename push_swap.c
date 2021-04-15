#include "./srcs/push_swap.h"
/*
sa : swap a- swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
sb :swap b- swap the first 2 elements at the top of stack b. Do nothing if thereis only one or no elements.
ss :sa and sb at the same time.
pa :push a- take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb :push b- take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra :rotate a- shift up all elements of stackaby 1. The first element becomes the last one.
rb :rotate b- shift up all elements of stackbby 1. The first element becomes the last one.
rr :ra and rb at the same time.
rra :reverse rotate a- shift down all elements of stack a by 1. The last element becomes the first one.
rrb :reverse rotate b- shift down all elements of stack b by 1. The last element becomes the first one.
rrr :rra and rrb at the same time.
*/

int push_swap(t_list *empty, t_list *lst, int i, int j)
{
    if (lst > lst->next)
        ft_sa(empty, lst);
    empty = ft_pb(empty, lst);
    ft_rra(empty, lst);
    if (lst > lst->next)
        ft_sa(empty, lst);
    ft_pb(empty, lst);
    if (empty && empty < empty->next)
        ft_rrr(empty, lst);
    else
        ft_rra(empty, lst);
    ft_pa(empty, lst);
    ft_pa(empty, lst);
 //   while (lst->prec)
 //       lst = lst->prec;
    return (0);
}

t_list *create_list(t_list *lst, int value, int i, char **av)
{
    t_list *tmp;

    tmp = 0;
    lst = ft_lstnew(lst, (value = ft_atoi(av[i])));
    printf("lst->value %d\n", lst->value);
    i--;
    while (i > 0)
    {
        tmp = lst;
        ft_lstadd_front(&lst, ft_lstnew(lst, (value = ft_atoi(av[i]))));
        printf("lst->value %d\n", lst->value);
        ft_lstiter(lst);
        tmp->prec = lst;
        i--;
    }
    return (lst);
}

int main(int ac, char **av)
{
    int i;
    int value;
    t_list *lst;
    t_list *empty;
    t_list *tmp;
    t_list *new;

    value = 0;
    new = 0;
    i = ac - 1;
    lst = create_list(lst, value, i, av);
//    if (!(empty = malloc (sizeof(t_list))))
//        return (0);
    empty = NULL;
/*    while (lst)
    {
        printf("lst%d\n", lst);
        printf("lst_next%d\n", lst->next);
        printf("lst_prec%d\n", lst->prec);
        lst = lst->next;
    }*/
    push_swap(empty, lst, 0, ac - 1);
    while (lst)
    {
        printf("lst->value %d\n", lst->value);
        lst = lst->next;
    }
    return (0);
}