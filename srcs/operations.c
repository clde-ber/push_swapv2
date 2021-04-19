#include "push_swap.h"

void swap(t_list **a, t_list **b)
{
    t_list *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

t_list *ft_sa(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    if (!(lst || (lst && !lst->next)))
        return (1);
    while (lst->next)
        lst = lst->next;
    lst = lst->prec;
    swap(lst, lst->next);
//    lst = tmp->prec;
//    lst->next = 0;
//    tmp = lst->prec;
/*    printf("lst 2 %d\n", lst);
    printf("lst 2 %d\n", lst->prec);
    printf("lst 2 %d\n", lst->next);*/
    while (lst->next)
    {
        printf("value %d\n", lst->value);
        lst = lst->next;
    }
    printf("value %d\n", lst->value);
    write(1, "sa\n", 3);
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
//    lst = tmp->prec;
//    lst->next = 0;
//    tmp = lst->prec;
/*    printf("lst 2 %d\n", lst);
    printf("lst 2 %d\n", lst->prec);
    printf("lst 2 %d\n", lst->next);*/
    printf("lst 2 %d\n", empty->value);
    while (empty->next)
    {
        printf("value %d\n", empty->value);
        empty = empty->next;
    }
    write(1, "sb\n", 3);
    return (empty);
}

int ss(t_list *empty, t_list *lst)
{
    ft_sa(empty, lst);
    ft_sb(empty, lst);
    write(1, "ss\n", 3);
    return (0);
}

t_list *ft_pb(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    if (!(empty))
    {
        write(1, "pb\n", 3);
        return (lst);
    }
    tmp = (lst) ? 0 : lst;
    while (empty->next)
        empty = empty->next;
     printf("**empty%d\n", empty);
   printf("**empty  PREC %d\n", empty->prec);
   printf("**empty NEXT %d\n", empty->next);
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
//    printf("lst to free value %d\n", tmp->value);
   printf("lst VALUE %d\n", lst);
   printf("lst PREC %d\n", lst->prec);
   printf("lst NEXT %d\n", lst->next);
/*    printf("EMPTY VALUE %d\n", empty);
   printf("EMPTY PREC %d\n", empty->prec);
   printf("EMPTY NEXT %d\n", empty->next);*/
    write(1, "pb\n", 3);
    return (lst);
}

t_list *ft_pa(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    if (!(lst))
    {
        write(1, "pa\n", 3);
        return (empty);
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
    {
        printf("empty VALUE %d\n", empty);
   printf("empty PREC %d\n", empty->prec);
   printf("empty NEXT %d\n", empty->next);
        empty = empty->prec;
    }
     printf("empty VALUE %d\n", empty);
   printf("empty PREC %d\n", empty->prec);
   printf("empty NEXT %d\n", empty->next);
//    printf("lst to free value %d\n", tmp->value);
    write(1, "pa\n", 3);
    return (empty);
}

int ft_ra(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;

    while (lst->prec)
    {
     //   printf("LST %d\n", lst->value);
        lst = lst->prec;
    }
    tmp = lst;
    lst = lst->next;
    lst->prec = 0;
    while (lst->next)
        lst = lst->next;
    tmp2 = lst;
    lst = lst->prec;
    lst->next = tmp2;
 //   tmp2 = lst;
    ft_lstadd_front(&lst, tmp);
    ft_lstiter(lst);
    lst->prec = tmp2;
    tmp2->next = lst;
    lst->next = 0;
//    lst->next = 0;
    while (lst->prec)
    {
        lst = lst->prec;
    }
    while (lst->next)
    {
        printf("lst value %d\n", lst->value);
        printf("lst %d\n", lst);
        printf("lst prec %d\n", lst->prec);
        printf("lst next %d\n", lst->next);
        lst = lst->next;
    }
    printf("lst value %d\n", lst->value);
    printf("lst %d\n", lst);
    printf("lst prec %d\n", lst->prec);
    printf("lst next %d\n", lst->next);
    while (lst->prec)
        lst = lst->prec;
    write(1, "ra\n", 4);
    return (lst);
}

int ft_rb(t_list *empty, t_list *lst)
{
    t_list *tmp;

    ft_lstadd_back(&empty, ft_lstnew(empty, empty->value));
    ft_lstdelone(empty);
    while (empty->next)
        empty = empty->next;
    while (empty->prec)
    {
        tmp = empty;
        empty = empty->prec;
        empty->prec = tmp;
    }
    write(1, "rb\n", 3);
    return (0);
}

int rr(t_list *empty, t_list *lst)
{
    ft_ra(empty, lst);
    ft_rb(empty, lst);
    write(1, "rr\n", 3);
    return (0);
}

/*void	ps_ft_rev_rotate_a(t_list *lst_a, t_list *lst_b)
{
	t_node	*elem;
	if (lst_a->head != NULL && lst_a->head != lst_a->tail)
	{
		elem = lst_a->head;
		while (elem->next != lst_a->tail)
			elem = elem->next;
		elem->next->next = lst_a->head;
		lst_a->head = elem->next;
		elem->next = NULL;
		lst_a->tail = elem;
		ps_ft_buf("rra ", lst_a, lst_b);
	}
}*/

t_list *ft_rra(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;

    while (lst->prec)
    {
     //   printf("LST %d\n", lst->value);
        lst = lst->prec;
    }
//    printf("LST %d\n", lst->value);
    tmp = lst;
    while (lst->next)
        lst = lst->next;
    lst->prec->next = 0;
    tmp2 = lst;
 /*   printf("heyhye%d\n", lst);
    printf("heyhey_next%d\n", lst->next);
    printf("heyhey_prec%d\n", lst->prec);*/
    ft_lstadd_front(&lst, tmp2);
    ft_lstiter(tmp);
     tmp2->prec = 0;
     tmp2->next = tmp;
     tmp->prec = tmp2;
//     tmp2->next->next = 0;
//     printf("tmp2 %d\n", tmp2);
//      printf("tmp %d\n", tmp);
//    printf("lstnnnvalue %d\n", lst->next->next->next);
//    ft_lstdelone(lst);
    lst = tmp;
    while (lst->prec)
        lst = lst->prec;
    while (lst->next)
    {
         printf("lst value %d\n", lst->value);
        lst = lst->next;
    }
    printf("lst value %d\n", lst->value);
    while (lst->prec)
        lst = lst->prec;
    write(1, "rra\n", 4);
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
    {
    /*    printf("heyhye%d\n", empty);
        printf("heyhey_next%d\n", empty->next);
        printf("heyhey_prec%d\n", empty->prec);*/
        empty = empty->next;
    }
    empty->prec->next = 0;
    tmp2 = empty;
 /*   printf("heyhye%d\n", lst);
    printf("heyhey_next%d\n", lst->next);
    printf("heyhey_prec%d\n", lst->prec);*/
    ft_lstadd_front(&empty, tmp2);
    ft_lstiter(tmp);
     tmp2->prec = 0;
     tmp2->next = tmp;
     tmp->prec = tmp2;
//     tmp2->next->next = 0;
//     printf("tmp2 %d\n", tmp2);
//      printf("tmp %d\n", tmp);
//    printf("lstnnnvalue %d\n", lst->next->next->next);
//    ft_lstdelone(lst);
    empty = tmp;
    while (empty->prec)
        empty = empty->prec;
    while (empty)
    {
    /*    printf("la%d\n", empty);
        printf("la_next%d\n", empty->next);
        printf("la_prec%d\n", empty->prec);*/
         printf("empty value%d\n", empty->value);
        empty = empty->next;
    }
    write(1, "rrb\n", 4);
    return (0);
}

int ft_rrr(t_list *empty, t_list *lst)
{
    ft_rra(empty, lst);
    ft_rrb(empty, lst);
    write(1, "rrr\n", 4);
    return (0);
}