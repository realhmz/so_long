#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct s_free
{
	char		*ptr;
	struct s_free	*next;
}			t_free;

void *lst_new(void *content)
{
    t_free *new;

    new = malloc(sizeof(t_free));
    if (!new)
        return (0);
    new->ptr = content;
    new->next = 0;
    return (new);
}
void lst_add_front(t_free **alst, t_free *new)
{
    if (!alst)
        alst = &new;
    if (alst && new)
    {
        new->next = *alst;
        *alst = new;
    }
}
void ft_free(t_free *lst)
{
    t_free *tmp;

    while (lst)
    {
        tmp = lst->next;
        free(lst->ptr);
        free(lst);
        lst = tmp;
    }
}
ft_printf(t_free **lst)
{
    while (*lst)
    {
        printf("%s\n", *lst->ptr);
        lst = *lst->next;
    }
}

int main()
{
    t_free **lst;
    lst = NULL;
    lst_add_front(lst, lst_new("World"));
    ft_free(lst);
    return 0;
}