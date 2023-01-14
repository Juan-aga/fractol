/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:16:33 by juan-aga          #+#    #+#             */
/*   Updated: 2022/12/20 15:03:11 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"

static char	*ft_fill_rest(char *str, int size);

char	*ft_ftoa(double d)
{
	char	*str;
	char	*num;
	char	*rest;
	int		n;

	n = (int) d;
	num = ft_itoa(n);
	if (!num)
		return (NULL);
	d = d - (double) n;
	d = ft_power_double(d, 6);
	rest = ft_itoa(d);
	rest = ft_fill_rest(rest, 6);
	if (!rest)
	{
		free(num);
		return (NULL);
	}
	str = ft_strjoin_va("%s.%s", num, rest);
	free(num);
	free(rest);
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_fill_rest(char *str, int size)
{
	int		len;
	int		i;
	char	*tmp;

	len = ft_strlen(str);
	if (len < size)
	{
		tmp = ft_calloc(size + 1, sizeof(char));
		if (!tmp)
		{
			free(str);
			return (NULL);
		}
		i = -1;
		while (++i < size - len)
			tmp[i] = '0';
		while (i < size)
		{
			tmp[i] = str[i - (size - len)];
			i++;
		}
		free(str);
		return (tmp);
	}
	return (str);
}
