/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:35:35 by juan-aga          #+#    #+#             */
/*   Updated: 2022/10/11 11:03:38 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*gnl_read(int fd, char *str);
char	*gnl_strjoin(char *str, char *buff);
char	*gnl_line(char *str);
int		gnl_strchr(char *str, const char c);
int		gnl_strlen(char *s);
char	*gnl_strcpy(char *src, char *dst, int start);
char	*gnl_next(char *str);

#endif
