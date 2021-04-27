#include "push_swap.h"

void swap(t_list **a, t_list **b)
{
    t_list *tmp;
    t_list *tmp2;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

t_list *ft_sa(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    if ((!lst || (lst && !lst->next)))
        return (lst);
    while (lst->next)
        lst = lst->next;
    lst = lst->prec;
    swap(lst, lst->next);
    while (lst->prec)
        lst = lst->prec;
    while (lst->next)
    {
        lst = lst->next;
    }
    return (lst);
}

int ft_sb(t_list *empty, t_list *lst)
{
     t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    if (!(empty || (empty && !empty->next)))
        return (1);
    while (empty->prec)
        empty = empty->prec;
    swap(empty, empty->next);
    while (empty->next)
        empty = empty->next;
    return (empty);
}

int ss(t_list *empty, t_list *lst)
{
    ft_sa(empty, lst);
    ft_sb(empty, lst);
    return (0);
}

t_list *ft_pb(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    if (!(empty))
        return (lst);
    tmp = (lst) ? 0 : lst;
    while (empty->next)
        empty = empty->next;
    if (empty->prec || empty->next)
    {
        tmp3 = empty->prec;
        tmp2 = empty;
        tmp2->prec = tmp;
        tmp2->next = lst;
        empty = tmp3;
        empty->next = 0;
        ft_lstadd_front(&lst, tmp2);
        ft_lstiter(lst);
        lst->prec = tmp;
    }
    else
    {
        tmp2 = empty;
        tmp2->prec = 0;
        tmp2->next = 0;
        ft_lstadd_front(&lst, tmp2);
        ft_lstiter(lst);
        lst->prec = 0;
    }
    return (lst);
}

t_list *ft_pa(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    if (!(lst))
        return (empty);
    if (empty)
    {
        while (empty->next)
            empty = empty->next;
    }
    tmp = (empty) ? empty : 0;
    while (lst->next)
        lst = lst->next;
    tmp3 = lst->prec;
    tmp2 = lst;
    tmp2->prec = 0;
    tmp2->next = tmp;
    lst = tmp3;
    lst->next = 0;
    ft_lstadd_front(&empty, tmp2);
    ft_lstiter(empty);
    empty->prec = tmp;
    empty->next = 0;
    if (tmp)
    tmp->next = empty;
    while (empty->prec)
        empty = empty->prec;
    return (empty);
}

int ft_ra(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;

    while (lst->prec)
        lst = lst->prec;
    tmp = lst;
    lst = lst->next;
    lst->prec = 0;
    while (lst->next)
        lst = lst->next;
    tmp2 = lst;
    lst = lst->prec;
    lst->next = tmp2;
    ft_lstadd_front(&lst, tmp);
    ft_lstiter(lst);
    lst->prec = tmp2;
    tmp2->next = lst;
    lst->next = 0;
    while (lst->prec)
        lst = lst->prec;
    while (lst->next)
        lst = lst->next;
    while (lst->prec)
        lst = lst->prec;
    return (lst);
}

int ft_rb(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;

    while (empty->prec)
        empty = empty->prec;
    tmp = empty;
    empty = empty->next;
    empty->prec = 0;
    while (empty->next)
        empty = empty->next;
    tmp2 = empty;
    empty = empty->prec;
    empty->next = tmp2;
    ft_lstadd_front(&empty, tmp);
    ft_lstiter(empty);
    empty->prec = tmp2;
    tmp2->next = lst;
    empty->next = 0;
    while (empty->prec)
        empty = empty->prec;
    while (empty->next)
        empty = empty->next;
    while (empty->prec)
        empty = empty->prec;
    return (empty);
}

int ft_rr(t_list *empty, t_list *lst)
{
    ft_ra(empty, lst);
    ft_rb(empty, lst);
    return (0);
}

t_list *ft_rra(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;

    while (lst->prec)
        lst = lst->prec;
    tmp = lst;
    while (lst->next)
        lst = lst->next;
    lst->prec->next = 0;
    tmp2 = lst;
    ft_lstadd_front(&lst, tmp2);
    ft_lstiter(tmp);
     tmp2->prec = 0;
     tmp2->next = tmp;
     tmp->prec = tmp2;
    lst = tmp;
    while (lst->prec)
        lst = lst->prec;
    while (lst->next)
        lst = lst->next;
    while (lst->prec)
        lst = lst->prec;
    return (lst);
}

int ft_rrb(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;

    while (empty->prec)
        empty = empty->prec;
    tmp = empty;
    while (empty->next)
        empty = empty->next;
    empty->prec->next = 0;
    tmp2 = empty;
    ft_lstadd_front(&empty, tmp2);
    ft_lstiter(tmp);
     tmp2->prec = 0;
     tmp2->next = tmp;
     tmp->prec = tmp2;
    empty = tmp;
    while (empty->prec)
        empty = empty->prec;
    while (empty->next)
        empty = empty->next;
    while (empty->prec)
        empty = empty->prec;
    return (empty);
}

int ft_rrr(t_list *empty, t_list *lst)
{
    ft_rra(empty, lst);
    ft_rrb(empty, lst);
    return (0);
}