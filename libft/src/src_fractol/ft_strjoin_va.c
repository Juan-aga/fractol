/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_va.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:50:37 by juan-aga          #+#    #+#             */
/*   Updated: 2022/12/20 14:57:45 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"
#include <stdarg.h>

static char	*ft_strjoin_free(char *s1, char *s2);
static char	*ft_check_args_to_join(va_list args, char c, char *join);

char	*ft_strjoin_va(char const *s, ...)
{
	int		i;
	va_list	args;
	char	*join;

	i = 0;
	va_start(args, s);
	join = ft_calloc(sizeof(char), 1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			join = ft_check_args_to_join(args, s[i], join);
		}
		else
			join = ft_chrjoin(join, s[i]);
		if (!join)
			break ;
		i++;
	}
	va_end(args);
	return (join);
}

static char	*ft_check_args_to_join(va_list args, char c, char *join)
{
	char	*str;

	if (c == 'i')
	{
		str = (ft_itoa(va_arg(args, int)));
		join = ft_strjoin_free(join, str);
	}
	if (c == 'f')
	{
		str = (ft_ftoa(va_arg(args, double)));
		join = ft_strjoin_free(join, str);
	}
	else if (c == 's')
	{
		str = ft_strdup(va_arg(args, char *));
		join = ft_strjoin_free(join, str);
	}
	return (join);
}

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (s3);
}
