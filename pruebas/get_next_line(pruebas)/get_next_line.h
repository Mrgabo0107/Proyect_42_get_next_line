/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:36:34 by gamoreno          #+#    #+#             */
/*   Updated: 2022/07/12 04:07:22 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*-----------------------------------librerias--------------------------------*/
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/*----------------------------------Prototipos--------------------------------*/
char	*get_next_line(int fd);
char	*read_file(int fd, char *static_buffer);
char	*free_join(char *static_buffer, char *temp_buffer);
char	*do_line(char *static_buffer);
char	*fix_buffer(char *static_buffer);

/*------------------------------------Utils-----------------------------------*/
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
