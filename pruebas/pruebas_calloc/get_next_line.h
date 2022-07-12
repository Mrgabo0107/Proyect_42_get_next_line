/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:36:34 by gamoreno          #+#    #+#             */
/*   Updated: 2022/07/12 00:33:47 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*-----------------------------------librerias--------------------------------*/
# include <stdlib.h>
# include <fcntl.h>

/*-------------------------------Buffer_por_defecto---------------------------*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*----------------------------------Prototipos--------------------------------*/
char	*get_next_line(int fd);
char	*read_file(int fd, char *static_buffer);

/*------------------------------------Utils-----------------------------------*/
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
