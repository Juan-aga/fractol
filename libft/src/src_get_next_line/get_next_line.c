/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:51:36 by juan-aga          #+#    #+#             */
/*   Updated: 2022/10/20 16:02:30 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*line;

	if (BUFFER_SIZE == 0 || fd < 0 || fd > 4095)
		return (0);
	str[fd] = gnl_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = gnl_line(str[fd]);
	str[fd] = gnl_next(str[fd]);
	return (line);
}

char	*gnl_read(int fd, char *str)
{
	char	*buff;
	int		buff_len;

	buff = (char *) malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	buff_len = 1;
	while (buff_len != 0 && !gnl_strchr(str, '\n'))
	{
		buff_len = read(fd, buff, BUFFER_SIZE);
		if (buff_len == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[buff_len] = '\0';
		str = gnl_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*gnl_strjoin(char *str, char *buff)
{
	int		str_l;
	char	*s;

	if (!str)
	{
		str = (char *) malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff || (!gnl_strlen(str) && !gnl_strlen(buff)))
	{
		free (str);
		return (NULL);
	}
	s = (char *) malloc(gnl_strlen(str) + gnl_strlen(buff) + 1 * sizeof(char));
	s = gnl_strcpy(str, s, 0);
	str_l = gnl_strlen(str);
	s = gnl_strcpy(buff, s, str_l);
	free(str);
	return (s);
}

char	*gnl_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *) malloc(i + 2 * sizeof(char));
	if (!line)
		return (NULL);
	i++;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_next(char *str)
{
	char	*s;
	int		i;
	int		l;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = (char *) malloc(gnl_strlen(str) - i + 1 * sizeof(char));
	if (!s)
		return (NULL);
	i++;
	l = 0;
	while (str[i + l])
	{
		s[l] = str[i + l];
		l++;
	}
	s[l] = '\0';
	free(str);
	return (s);
}
