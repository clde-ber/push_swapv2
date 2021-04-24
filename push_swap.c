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

int is_max(int lst, int max)
{
    if (lst == max)
        return (1);
    return (0);
}

int ra_o_rra(t_list *s_lst, t_list *max)
{
    int i;
    
    i = 0;
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next)
    {
        if (s_lst->value == max->value)
            return (i);
        s_lst = s_lst->next;
        i++;
    }
    return (i);
}

t_list *push_swap(t_list *empty, t_list *s_lst, int i, int j, t_count *count, t_list *max)
{
    int x;
    int k;

    x = 0;
    k = j;
    while (j > 2)
    {
        while (s_lst->next)
            s_lst = s_lst->next;
        s_lst = s_lst->prec;
        if (s_lst->value > s_lst->next->value && is_max(s_lst->next->value, max->value) == 0)
        {
            s_lst = ft_sa(empty, s_lst);
            count->count++;
        }
        if (j == 2 && x == j - 1)
            break ;
        while (s_lst->next)
            s_lst = s_lst->next;
        s_lst = s_lst->prec;
        if ((x == j - 1 && j > 2) || (is_max(s_lst->next->value, max->value) && j > 2))
        {
            if (is_max(s_lst->next->value, max->value) && max->next)
                max = max->next;
            empty = ft_pa(empty, s_lst);
            while (s_lst->next)
                s_lst = s_lst->next;
            s_lst = s_lst->prec;
            count->count++;
            while (empty->prec)
                empty = empty->prec;
            if (j == 3)
                break;
            if (s_lst->value > s_lst->next->value && is_max(s_lst->next->value, max->value) == 0)
            {
                count->count++;
                s_lst = ft_sa(empty, s_lst);
            }
            while (s_lst->next)
                s_lst = s_lst->next;
            s_lst = s_lst->prec;
            j -= 1;
            x = 0;
        }
        while (s_lst->next)
            s_lst = s_lst->next;
        s_lst = s_lst->prec;
        if (x == 0 && j == 2)
            break ;
        if (x < j - 1 && is_max(s_lst->next->value, max->value) == 0)
        {
            count->count++;
            if (ra_o_rra(s_lst, max) > k / 2)
                ft_rra(empty, s_lst);
            else
                ft_ra(empty, s_lst);
        }
        x++;
    }
    while (s_lst->next)
        s_lst = s_lst->next;
    s_lst = s_lst->prec;
    if (s_lst->value < s_lst->next->value || is_max(s_lst->next->value, max->value))
    {
        count->count++;
        s_lst = ft_sa(empty, s_lst);
    }
    while (k > 2)
    {
        while (s_lst->prec)
            s_lst = s_lst->prec;
        count->count++;
        s_lst = ft_pb(empty, s_lst);
        k--;
    }
    while (s_lst->prec)
        s_lst = s_lst->prec;
    return (s_lst);
}

t_list *create_max(t_list *empty, t_list *lst, int i, int j, t_count *count)
{
    int x;
    int k;

    x = 0;
    k = j;
    while (j > 2)
    {
        while (lst->next)
            lst = lst->next;
        lst = lst->prec;
        if (lst->value > lst->next->value)
        {
            lst = ft_sa(empty, lst);
            count->count++;
        }
        if (j == 2 && x == j - 1)
            break ;
        if (x == j - 1 && j > 2)
        {
            while (lst->prec)
                lst = lst->prec;
            empty = ft_pa(empty, lst);
            count->count++;
            while (empty->prec)
                empty = empty->prec;
            if (j == 3)
                break;
            while (lst->next)
                lst = lst->next;
            lst = lst->prec;
            if (lst->value > lst->next->value)
            {
                count->count++;
                lst = ft_sa(empty, lst);
            }
            j -= 1;
            x = 0;
        }
        while (lst->prec)
            lst = lst->prec;
        if (x == 0 && j == 2)
            break ;
        if (x < j - 1)
        {
            count->count++;
            ft_ra(empty, lst);
        }
        x++;
    }
    while (lst->next)
        lst = lst->next;
        lst = lst->prec;
    if (lst->value < lst->next->value)
    {
        count->count++;
        lst = ft_sa(empty, lst);
    }
    while (k > 2)
    {
        while (lst->prec)
            lst = lst->prec;
        count->count++;
        lst = ft_pb(empty, lst);
        k--;
    }
    while (lst->prec)
        lst = lst->prec;
    return (lst);
}

t_list *create_list(t_list *lst, int value, int i, char **av)
{
    t_list *tmp;

    tmp = 0;
    lst = ft_lstnew(lst, (value = ft_atoi(av[i])));
    i--;
    while (i > 0)
    {
        tmp = lst;
        ft_lstadd_front(&lst, ft_lstnew(lst, (value = ft_atoi(av[i]))));
        ft_lstiter(lst);
        tmp->prec = lst;
        i--;
    }
    while (lst->prec)
        lst = lst->prec;
    while (lst->next)
        lst  = lst->next;
    return (lst);
}

int main(int ac, char **av)
{
    int i;
    int value;
    t_list *lst;
    t_list *empty;
    t_list *max;
    t_list *s_lst;
    t_count *count;

    value = 0;
    i = ac - 1;
    count = malloc(sizeof(t_count));
    count->count = 0;
    lst = create_list(lst, value, i, av);
    empty = NULL;
    lst = create_max(empty, lst, 0, ac - 1, count);
    ft_lstdelone(empty);
    count->count = 0;
    s_lst = create_list(s_lst, value, i, av);
    s_lst = push_swap(empty, s_lst, 0, ac - 1, count, lst);
    while (s_lst)
    {
    //    printf("%d\n", s_lst->value);
        s_lst = s_lst->next;
    }
//    printf("\n");
    printf("%d\n", count->count);
    return (0);
}