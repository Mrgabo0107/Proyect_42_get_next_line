#include "get_next_line.h"
#include <stdio.h>

int main ()
{
	char	*p;
	int	i;

	p = ft_calloc(8, 1);
	i = 0;
	while (i < 9)
	{
		printf("%c ", *(p + i) + '0');
		i++;
	}
	return (0);
}
