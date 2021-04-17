#include "push_swap.h"

t_list *ft_sa(t_list *empty, t_list *lst)
{
    t_list *tmp;

    if (!(lst || (lst && !lst->next)))
        return (1);
    while (lst->prec)
        lst = lst->prec;
    tmp = lst->next;
    tmp->prec = lst;
/*    printf("lst 1 %d\n", tmp);
     printf("lst 1 %d\n", tmp->prec);
      printf("lst 1 %d\n", tmp->next);*/
      printf("lst 1 %d\n", tmp->value);
    lst->next = tmp;
    lst->prec = 0;
//    lst->next = 0;
//    tmp = lst->prec;
/*    printf("lst 2 %d\n", lst);
    printf("lst 2 %d\n", lst->prec);
    printf("lst 2 %d\n", lst->next);*/
    printf("lst 2 %d\n", lst->value);
    write(1, "sa\n", 3);
    return (lst);
}

int ft_sb(t_list *empty, t_list *lst)
{
    t_list *tmp;

    if (!(empty->next))
        return (1);
    tmp = empty;
    empty = empty->next;
    empty->prec = tmp;
    empty->next = 0;
    write(1, "sb\n", 3);
    return (0);
}

int ss(t_list *empty, t_list *lst)
{
    ft_sa(empty, lst);
    ft_sb(empty, lst);
    write(1, "ss\n", 3);
    return (0);
}

int ft_pa(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;

    if (!(empty))
        return (1);
 //   if (!(tmp = malloc(sizeof(t_list))))
 //       return (0);
 //   lst = tmp;
    while (lst->prec)
        lst = lst->prec;
    tmp = (lst) ? lst : 0;
    ft_lstadd_front(&lst, ft_lstnew(empty, empty->value));
 /*   printf("empty %d\n", lst);
        printf("empty next %d\n", lst->next);
        printf("empty prec %d\n", lst->prec);*/
    while (empty->next)
        empty = empty->next;
    empty->prec->next = 0;
    ft_lstdelone(empty->next);
    while (lst->next)
    {
   /*     printf("empty %d\n", lst);
        printf("empty next %d\n", lst->next);
        printf("empty prec %d\n", lst->prec);*/
        printf("lst value %d\n", lst->value);
        tmp = lst;
        lst = lst->next;
        lst->prec = tmp;
    }
 /*    while (lst)
    {
        printf("hey%d\n", lst);
        printf("hey_next%d\n", lst->next);
        printf("hey_prec%d\n", lst->prec);
        lst = lst->next;
    }*/
    printf("lst value %d\n", lst->value);
/*    printf("empty next %d\n", lst->next);
    printf("empty prec %d\n", lst->prec);*/
    write(1, "pa\n", 3);
    return (lst);
}

t_list *ft_pb(t_list *empty, t_list *lst)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    if (!(lst))
        return (1);
 //   if (!(tmp = malloc(sizeof(t_list))))
 //       return (0);
    tmp = (empty) ?  empty : 0;
//    empty = tmp;
    ft_lstadd_front(&empty, ft_lstnew(lst, lst->value));
//    while (lst->next)
//        lst = lst->next;
//    lst->next->prec = 0;
    printf("lst to free value %d\n", lst->value);
    lst->next->prec = 0;
    tmp = lst;
    lst = lst->next;
    ft_lstdelone(tmp);
/*    while (lst)
    {
        printf("lst to free value %d\n", lst->value);
        printf("lst to free %d\n", lst);
        printf("lst to free next %d\n", lst->next);
        printf("lst to free prec%d\n", lst->prec);
        if (lst->prec == 0)
            lst->prec = 0;
        tmp = lst;
        lst = lst->next;
        ft_lstdelone(tmp);
    }*/
    printf("lst value %d\n", lst->value);
    printf("lst %d\n", lst);
    printf("lst to free next %d\n", lst->next);
    printf("lst to free prec%d\n", lst->prec);
//   while (lst->prec)
//    {
//        lst = lst->prec;
//    }
    while (empty->next)
    {
        printf("empty value %d\n", empty->value);
  /*      printf("empty next %d\n", empty->next);
        printf("empty prec %d\n", empty->prec);
        printf("empty VALUE %d\n", empty->value);*/
        tmp = empty;
        empty = empty->next;
        empty->prec = tmp;
    }
 /*    while (lst)
    {
        printf("hey%d\n", lst);
        printf("hey_next%d\n", lst->next);
        printf("hey_prec%d\n", lst->prec);
        lst = lst->next;
    }*/
/*    printf("empty %d\n", empty);
    printf("empty next %d\n", empty->next);
    printf("empty prec %d\n", empty->prec);*/
     printf("empty value %d\n", empty->value);
    write(1, "pb\n", 3);
    return (lst);
}

int ft_ra(t_list *empty, t_list *lst)
{
    t_list *tmp;

    ft_lstadd_back(&lst, ft_lstnew(lst, lst->value));
    ft_lstdelone(lst);
    while (lst->next)
        lst = lst->next;
    while (lst->prec)
    {
        tmp = lst;
        lst = lst->prec;
        lst->prec = tmp;
    }
    write(1, "ra\n", 3);
    return (0);
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
        printf("LST %d\n", lst);
     printf("LST %d\n", lst->prec);
        lst = lst->prec;
    }
    tmp = lst;
    while (lst->next)
    {
   /*     printf("heyhye%d\n", lst->value);
        printf("heyhey_next%d\n", lst->next);
        printf("heyhey_prec%d\n", lst->prec);*/
        lst = lst->next;
    }
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
    while (lst)
    {
    /*    printf("la%d\n", lst);
        printf("la_next%d\n", lst->next);
        printf("la_prec%d\n", lst->prec);*/
         printf("lst value %d\n", lst->value);
        lst = lst->next;
    }
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