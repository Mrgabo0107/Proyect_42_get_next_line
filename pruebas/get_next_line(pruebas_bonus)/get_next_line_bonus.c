/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:46:50 by gamoreno          #+#    #+#             */
/*   Updated: 2022/07/12 04:20:31 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Parametros: -Un entero (file descriptor) 'fd'.
 *
 * Esta funcion toma uno o varios archivos referenciados por sus respectivos 
 * file descriptors pasados por parametro como 'fd' y sin importar el
 * BUFFER_SIZE dado lee e imprime en pantalla la primera linea de cada
 * archivo ayudado de la funcion read, asi, cada vez que se invoque la funcion
 * devolvera la linea siguiente hasta terminar cada archivo.
 *
 * Devuelve: La primera linea leida correspondiente o NULL si no hay nada mas
 * que leer o si ocurrio un error. */

#include "get_next_line_bonus.h"

/* Funcion principal */

char	*get_next_line(int fd)
{
	static char	*static_buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	static_buffer[fd] = read_file(fd, static_buffer[fd]);
	line = do_line(static_buffer[fd]);
	static_buffer[fd] = fix_buffer(static_buffer[fd]);
	return (line);
}

/* Esta funcion llena el static buffer de la funcion original con una linea 
 * completa terminando en el final o en algun retorno a la linea. */

char	*read_file(int fd, char *static_buffer)
{
	char	*temp_buffer;
	int		return_read;

	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (NULL);
	return_read = 1;
	while (return_read > 0)
	{
		return_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (return_read < 0)
		{
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[return_read] = 0;
		static_buffer = free_join(static_buffer, temp_buffer);
		if (ft_strchr(temp_buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (static_buffer);
}

/* Esta funcion concatena el static buffer con el temp buffer mientras 
 * libera lo que habia en static buffer y deja solo la concatenacion
 * asignada a esta variable estatica. */

char	*free_join(char *static_buffer, char *temp_buffer)
{
	char	*join;

	join = ft_strjoin(static_buffer, temp_buffer);
	free(static_buffer);
	return (join);
}

/* Esta funcion extrae del static buffer la linea que se desea retornar. */

char	*do_line(char *static_buffer)
{
	char	*retrn;
	int		i;

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

/* Esta funcion prepara el buffer para que al aplicar get_next_line
 * de nuevo, el retorno sea la linea esperada. */

char	*fix_buffer(char *static_buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free (static_buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(static_buffer) - i + 1, sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (static_buffer[i])
		new_buffer[j++] = static_buffer[i++];
	free (static_buffer);
	return (new_buffer);
}
