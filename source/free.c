#include "get_next_line.h"

int free_leaks(t_vars *v)
{
    free(v->asset);
    v->asset = NULL;
    free(v->edges);
    v->edges = NULL;
    free(v->xpm);
    v->xpm = NULL;
    free(v);
    v = NULL;
    return(0);
}