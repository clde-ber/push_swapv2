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

int find_max(t_list *max)
{
    int max_value;

    max_value = max->value;
    while (max->prec)
        max = max->prec;
    while (max->next)
    {
        if (max_value < max->value)
            max_value = max->value;
        max = max->next;
    }
    if (max_value < max->value)
        max_value = max->value;
    return (max_value);
}

int find_next_max(t_list *max, int cmp)
{
    int max_value;

    max_value = max->value;
    while (max->prec)
        max = max->prec;
    while (max->next)
    {
        if (max_value < max->value && max_value < cmp)
            max_value = max->value;
        max = max->next;
    }
    if (max_value < max->value && max_value < cmp)
        max_value = max->value;
    return (max_value);
}

int ra_o_rra(t_list *s_lst, int max)
{
    int i;
    
    i = 0;
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next)
    {
        if (s_lst->value == max)
            return (i);
        s_lst = s_lst->next;
        i++;
    }
    return (i);
}

t_list *push_run_to_a(int max, t_list *empty, t_list *s_lst, int k, int j, t_count *ct)
{
    while (ct->max && empty)
    {
        while (s_lst->prec)
            s_lst = s_lst->prec;
        while (empty->prec)
            empty = empty->prec;
        s_lst = ft_pb(empty, s_lst);
        ct->count++;
        ct->max--;
    }
    while (s_lst->prec)
        s_lst = s_lst->prec;
    return (s_lst);
}

int find_min_run(int j)
{
    int run;

    run = j / 100;
    if (run == 0)
    {
        run = 1;
        return (run);
    }
    return (run);
}

t_list *push_biggest_runs(int run, t_list *empty, t_list *s_lst, int cmp, int j, t_count *ct)
{
//    printf("max %d\n", cmp);
//    printf("ct->max %d\n", ct->max);
    ct->max++;
    empty = ft_pa(empty, s_lst);
    ct->count++;
    ct->index++;
    if (empty)
    {
        while (empty->prec)
            empty = empty->prec;
        while (empty->next)
        {
//            printf("empty %d\n", empty->value);
            empty = empty->next;
        }
//        printf("empty %d\n", empty->value);
        while (empty->prec)
            empty = empty->prec;
    }
    return (empty);
}

t_list *find_index(int run, t_list *empty, t_list *s_lst, int cmp, int j, t_count *ct)
{
    int sup;
    int inf;
    int cmp_i;
    int cmp_s;
    int i;
    int index;

    sup = 0;
    inf = 0;
    cmp_i = 1;
    cmp_s = 1;
    i = 0;
    index = 0;
//    printf ("cmpppppppp %d\n", cmp);
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next && cmp_s != cmp && cmp_i != cmp)
    {
        while (s_lst->next && s_lst->value > s_lst->next->value && cmp_s != cmp && cmp_i != cmp)
        {
            cmp_s++;
            i++;
            s_lst = s_lst->next;
        }
        while (s_lst->next && s_lst->value < s_lst->next->value && cmp_i != cmp && cmp_s != cmp)
        {
            cmp_i++;
            i++;
            s_lst = s_lst->next;
        }
//        printf("cmp_s %d\n", cmp_s);
//        printf("cmp_i %d\n", cmp_i);
        if (cmp_i != cmp && cmp_s != cmp)
            cmp_i = 1;
        if (cmp_s != cmp && cmp_i != cmp)
            cmp_s = 1;
    }
    while (s_lst->prec)
        s_lst = s_lst->prec;
    return (++i - cmp);
}

int find_biggest_runs(t_list *s_lst, int run)
{
    int sup;
    int inf;
    int max;

    sup = 1;
    inf = 1;
    max = 0;
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next)
    {
        while (s_lst->next && s_lst->value > s_lst->next->value)
        {
            sup++;
            if (max < sup)
                max = sup;
            s_lst = s_lst->next;
        }
        while (s_lst->next && s_lst->value < s_lst->next->value)
        {
            inf++;
            if (max < inf)
                max = inf;
            s_lst = s_lst->next;
        }
        sup = 1;
        inf = 1;
    }
//    printf("max! %d\n", max);
    return (max);
}

t_list *push_swap2(t_list *empty, t_list *s_lst, int i, int j, t_count *count)
{
    int x;
    int k;
    int max;
    int boolean;

    boolean = 0;
    x = 0;
    k = j;
    max = find_max(s_lst);
    while (j > 2)
    {
        while (s_lst->next)
            s_lst = s_lst->next;
        s_lst = s_lst->prec;
        if (is_max(s_lst->next->value, max) == 0 && s_lst->value > s_lst->next->value)
        {
            s_lst = ft_sa(empty, s_lst);
            count->count++;
        }
        if (j == 2 && x == j - 1)
            break ;
        while (s_lst->next)
            s_lst = s_lst->next;
        s_lst = s_lst->prec;
        if ((is_max(s_lst->next->value, max) && j > 2) || (x == j - 1 && j > 2))
        {
            empty = ft_pa(empty, s_lst);
            max = find_next_max(s_lst, max);
            boolean = 1;
            while (s_lst->next)
                s_lst = s_lst->next;
            s_lst = s_lst->prec;
            count->count++;
            while (empty->prec)
                empty = empty->prec;
            if (j == 3)
                break;
            if (is_max(s_lst->next->value, max) == 0 && s_lst->value > s_lst->next->value)
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
        if (is_max(s_lst->next->value, max) == 0 && x < j - 1)
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
    if (is_max(s_lst->next->value, max) || s_lst->value < s_lst->next->value)
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

int cmp_first_a_last(t_list *s_lst, int cmp)
{
    int tmp;
    int tmp2;

    tmp = 0;
    tmp2 = 0;
    while (s_lst->prec)
        s_lst = s_lst->prec;
    tmp = s_lst->value;
    while (s_lst->next)
        s_lst = s_lst->next;
    tmp2 = s_lst->value;
    if (cmp < tmp && cmp > tmp2)
        return (1);
    return (0);
}

t_list *push_swap(t_list *empty, t_list *s_lst, int i, int j, t_count *count)
{
    int x;
    int k;
    int run;
    int max;
    int boolean;
    int index;
    int counte;
    int l;
    int essai;
    int last_ind;

    essai = 0;
    boolean = -1;
    l = 0;
    x = 0;
    k = j;
    counte = 0;
    last_ind = 0;
    count->index = 0;
    run = find_min_run(j);
    max = find_biggest_runs(s_lst, run);
    count->emp = 0;
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (max > 2)
    {
        max = find_biggest_runs(s_lst, run);
        printf("max %d\n", max);
        index = find_index(run, empty, s_lst, max, j, count);
        index = j - max - index;
        printf("index %d\n", index);
        while (s_lst->prec)
            s_lst = s_lst->prec;
        while (index && s_lst && s_lst->next)
        {
            while (s_lst->prec)
                s_lst = s_lst->prec;
            ft_rra(empty, s_lst);
            index--;
        }
        if (max == 2)
            break ;
        last_ind = max;
        while (s_lst->prec)
            s_lst = s_lst->prec;
        while (last_ind && s_lst && s_lst->next)
        {
            while (s_lst->prec)
            s_lst = s_lst->prec;
            empty = ft_pa(empty, s_lst);
            j--;
            last_ind--;
        }
        if (empty)
        {
            while (empty->prec)
                empty = empty->prec;
            while (empty->next)
            {
                printf("empty %d\n", empty->value);
                empty = empty->next;
            }
            printf("empty %d\n", empty->value);
            while (empty->prec)
                empty = empty->prec;
        }
        while (s_lst->prec)
            s_lst = s_lst->prec;
        while (s_lst->next)
        {
            printf("s_lst %d\n", s_lst->value);
            s_lst = s_lst->next;
        }
        printf("s_lst %d\n", s_lst->value);
        while (s_lst->prec)
            s_lst = s_lst->prec;
    }
      /*  last_ind = j - max;
        while (last_ind)
        {
            while (s_lst->prec)
                s_lst = s_lst->prec;
            empty = ft_pa(empty, s_lst);
            last_ind--;
            j--;
        }
        if (empty)
        {
            while (empty->prec)
                empty = empty->prec;
            while (empty->next)
            {
                printf("empty %d\n", empty->value);
                empty = empty->next;
            }
            printf("empty %d\n", empty->value);
            while (empty->prec)
                empty = empty->prec;
        }*/
 //   }
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
    t_list lst;
    t_list *empty;
    t_list *max;
    t_list *s_lst;
    t_count *count;

    value = 0;
    i = ac - 1;
    count = malloc(sizeof(t_count));
    empty = NULL;
    count->max = 0;
//    count->count = 0;
//    lst = create_list(lst, value, i, av);
//    empty = NULL;
//    lst = create_max(empty, lst, 0, ac - 1, count);
//    ft_lstdelone(empty);
    count->count = 0;
    s_lst = create_list(s_lst, value, i, av);
    if (ac - 1 > 4)
    {
        s_lst = push_swap(empty, s_lst, 0, ac - 1, count);
    }
    else
        s_lst = push_swap2(empty, s_lst, 0, ac - 1, count);
    if (!checker(s_lst))
        write(1, "KO", 2);
    else
        write(1, "OK", 2);
    printf("FINAL :");
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next)
    {
        printf("%d ", s_lst->value);
        s_lst = s_lst->next;
    }
    printf("%d ", s_lst->value);
//    printf("\n");
    printf("%d\n", count->count);
    return (0);
}