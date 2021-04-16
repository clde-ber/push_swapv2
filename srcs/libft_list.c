#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if (!new)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
	// check if next ? 
		new->prec = NULL;
	}
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
		new->next = NULL;
	}
}

void	ft_lstdelone(t_list *lst)
{
	t_list *tmp;

	if (lst)
	{
//		tmp = (lst->next) ? lst->next : lst->prec;
//		tmp->prec = NULL;
//		lst->value = 0;
        free(lst);
		lst = NULL;
    }
//	lst = tmp;
}

t_list	*ft_lstnew(t_list *lst, int value)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
    new->value = value;
	new->next = NULL;
    new->prec = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstiter(t_list *lst)
{
	if (!lst)
		return ;
	lst = lst->next;
}