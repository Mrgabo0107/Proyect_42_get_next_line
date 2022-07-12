/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:36:07 by gamoreno          #+#    #+#             */
/*   Updated: 2022/07/12 00:37:36 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Crea un malloc de tamano nmemb * size cuyos bytes seran todos cero */

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	if (size != 0 && nmemb * size / size != nmemb)
		return (NULL);
	p = (void *)malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return ((void *)p);
}

/* Esta funcion toma un puntero y escribe el caracter cero n veces a partir de
 * este. */

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
