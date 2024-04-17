#include "get_next_line.h"

char *ft_itoa(int n)
{
	int len;
	int tmp;
	char *str;

	len = 1;
	tmp = n;
	while (tmp /= 10)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
void print_moves(t_vars *v)
{
	char *str;
	str = ft_itoa(v->moves);
	str = ft_strjoin("Moves: ",str);
	mlx_string_put(v->mlx,v->win,10,10,0xFFFFFF,str);
	free(str);
}