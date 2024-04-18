#include "get_next_line.h"

void  *ft_malloc(int size, t_free *lst)
{
    void *ptr;

    ptr = malloc(size);
    if (!ptr)
        exit(0);
    // lst_add_front(&lst, lst_new(ptr));
    return (ptr);
    
}