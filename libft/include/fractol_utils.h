/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:41:22 by juan-aga          #+#    #+#             */
/*   Updated: 2022/12/20 16:08:55 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_UTILS_H
# define FRACTOL_UTILS_H

# include "libft.h"

/*			TEXT UTILS			*/
/*
		this is like strjoin, but with variatics arguments.
		at the momment it works with %ifs.
		returns the str or NULL if fails.
*/
char	*ft_strjoin_va(char const *s, ...);
/*
		this is like strjoin, but appends a char at the end 
		of the str.
		returns the new str or NULL if fails.
*/
char	*ft_chrjoin(char *s1, char c);
/*
		It converts a double number to a str, with 6 decimals..
		returns the str or NULL if fails.
*/
char	*ft_ftoa(double d);
/*
		It converts a str to a double.
*/
double	ft_atof(char *str);
/*			MATH UTILS			*/
/*
		this functions do the power of ten over an double
		pov is the numbers to do the power.
*/
double	ft_power_double(double n, int pov);

#endif
