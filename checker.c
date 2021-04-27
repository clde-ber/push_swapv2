#include "./srcs/push_swap.h"

void checker(t_list *s_lst)
{
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next)
    {
        if (s_lst->value < s_lst->next->value)
        {
            write(1, "KO", 2);
            return (0);
        }
        s_lst = s_lst->next;
    }
    write(1, "OK", 2);
    return (1);
}