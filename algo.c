#include "get_next_line.h"

int    wich_edge(t_vars *v,int x, int y)
{
    int up = 0;
    int down = 0;
    int right = 0;
    int left = 0;
    if (v->map[x] && v->map[x][y] == '0')
    {
        int i = 0;
        if (v->map[x][y + 1] && v->map[x][y + 1] == '1')
            right = 1;
        if ( v->map[x - 1][y] && v->map[x - 1][y] == '1')
            up = 2;
        if (v->map[x][y - 1] && v->map[x][y - 1] == '1')
            left = 4;
        if (v->map[x + 1][y] && v->map[x + 1][y] == '1')
            down = 8;
        i = left + right + down + up;
        return (i);
    }
    return (-1);
}