/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:29:43 by juan-aga          #+#    #+#             */
/*   Updated: 2022/11/16 08:57:42 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(size_t num, int len);
static	char	*ft_fill(char *str, int n, int len, size_t num);

char	*ft_itoa(int n)
{
	size_t	num;
	char	*str;
	int		len;

	len = 1;
	if (n < 0)
	{
		len += 1;
		if (n == -2147483648)
			num = 2147483648;
		else
			num = n * -1;
	}
	else
		num = n;
	len = ft_len(num, len);
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	return (ft_fill(str, n, len - 1, num));
}

static	int	ft_len(size_t num, int len)
{
	while (num > 9)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_fill(char *str, int n, int len, size_t num)
{
	if (n < 0)
		str[0] = '-';
	while (num > 9)
	{
		str[len] = (num % 10) + 48;
		num /= 10;
		len--;
	}
	str[len] = (num % 10) + 48;
	return (str);
}
