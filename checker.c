#include "./srcs/push_swap.h"

int checker(t_list *s_lst)
{
    while (s_lst->prec)
        s_lst = s_lst->prec;
    while (s_lst->next)
    {
        if (s_lst->value < s_lst->next->value)
        {
            return (0);
        }
        s_lst = s_lst->next;
    }
    return (1);
}