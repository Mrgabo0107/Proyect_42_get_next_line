#include "get_next_line.h"
#include <stdio.h>

char    *do_line(char *static_buffer)
{
        char    *retrn;
        int             i;  

        i = 0;
        if (!static_buffer[i])
                return (NULL);
        while (static_buffer[i] && static_buffer[i] != '\n')
                i++;
        retrn = ft_calloc(i + 2, sizeof(char));
        i = 0;
        while (static_buffer[i] && static_buffer[i] != '\n')
        {
                retrn[i] = static_buffer[i];
                i++;
        }
        if (static_buffer[i] && static_buffer[i] == '\n')
                retrn[i] = '\n';
        return (retrn);
}

int	main(void)
{
	char	*buffer_prueba;
	char	*line;

	buffer_prueba = "hola, mundo.\n";
	line = do_line(buffer_prueba);
	printf("%s", line);
	return (0);
}
