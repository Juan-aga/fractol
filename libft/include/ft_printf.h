/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:59:31 by juan-aga          #+#    #+#             */
/*   Updated: 2022/10/08 07:40:43 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int		ft_printf(char const *s, ...);
/*
	prints as hexadecimal the void * pinter given as argument.(in lower case).
	returns the numbers of 'n' printed.
   */
int		ft_putptr(unsigned long long n);
/*


   */
void	ft_putchar_pf(const char c, int *len);
void	ft_putstr_pf(char *str, int *len);
void	ft_putunnbr_pf(unsigned long long n, int *len, int base, char x);
void	ft_putptr_pf(unsigned long long n, int *len);
void	ft_putnbr_pf(int n, int *len);
/*		antiguas		*/
/*
	returns the base of number 'n' in bassse 'base'.	
   */
int		ft_basenbr(int long long n, int base);
/*
	prints an unsigned number in base -10
	returns the numbers of 'n'
   */
void	ft_putunnbr(unsigned int n, unsigned int base, char x);
/*

	prints 'n' as a hexadecimal.
	if 'x' is lowercase prints in lowercase, else in uppercase.
	returns the numbers printed of 'n'
   */
int		ft_puthex(unsigned long long n, char x);

#endif
