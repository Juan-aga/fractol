/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:28:40 by juan-aga          #+#    #+#             */
/*   Updated: 2022/11/16 17:47:48 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkarg(char const c, va_list args, int *len);

int	ft_printf(char const *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i] && !(len < 0))
	{
		if (s[i] != '%')
			ft_putchar_pf(s[i], &len);
		else if (s[i + 1] != '%')
		{
			ft_checkarg(s[i +1], args, &len);
			i++;
		}
		else
		{
			ft_putchar_pf('%', &len);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

void	ft_checkarg(char const c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar_pf(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr_pf(va_arg(args, char *), len);
	else if (c == 'p')
		ft_putptr_pf(va_arg(args, unsigned long long), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr_pf(va_arg(args, int), len);
	else if (c == 'u')
		ft_putunnbr_pf(va_arg(args, unsigned int), len, 10, 'x');
	else if (c == 'x' || c == 'X')
		ft_putunnbr_pf(va_arg(args, unsigned int), len, 16, c);
}
