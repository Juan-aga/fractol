/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan-aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:23:15 by juan-aga          #+#    #+#             */
/*   Updated: 2022/11/16 18:00:31 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_pf(unsigned long long n, int *len)
{
	ft_putstr_pf("0x", len);
	if (n == 0)
		ft_putchar_pf('0', len);
	else
		ft_putunnbr_pf(n, len, 16, 'x');
}

void	ft_putunnbr_pf(unsigned long long n, int *len, int base, char x)
{
	if (n >= (unsigned int) base)
	{
		ft_putunnbr_pf(n / base, len, base, x);
		ft_putunnbr_pf(n % base, len, base, x);
	}
	else
	{
		if (n < 10)
			ft_putchar_pf((n + '0'), len);
		else if (x == 'x')
			ft_putchar_pf((n - 10 + 'a'), len);
		else
			ft_putchar_pf((n - 10 + 'A'), len);
	}
}

void	ft_putnbr_pf(int n, int *len)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_pf(str, len);
	free(str);
}

void	ft_putchar_pf(const char c, int *len)
{
	int	i;

	i = 0;
	i = write(1, &c, 1);
	if (i < 0)
		*len = -1;
	else
		*len += 1;
}

void	ft_putstr_pf(char *str, int *len)
{
	int	i;

	i = 0;
	if (!(str))
		ft_putstr_pf("(null)", len);
	else if (str == NULL)
		*len = -1;
	else
	{
		while (str[i] && !(len < 0))
		{
			ft_putchar_pf(str[i], len);
			i++;
		}
	}
}
