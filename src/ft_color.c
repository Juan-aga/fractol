/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:31:11 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/12 15:30:34 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	ft_change_color(t_frac *f, int i)
{
	if (f->color == 0)
		return (ft_black_white(f, i));
	else if (f->color == 1)
		return (ft_pixel_bn(f, i));
	else if (f->color == 2)
		return (ft_pixel_nb(f, i));
	else if (f->color == 3)
		return (ft_pixel_random(f, i));
	else if (f->color == 4)
		return (ft_pixel(f, i));
	else if (f->color == 5)
		return (ft_bernstein_color(f, i));
	else if (f->color == 6)
		return (ft_bernstein_bw(f, i));
	else
		return (ft_four(f, i));
}

int	ft_pixel(t_frac *f, int i)
{
	double	c;

	c = i / f->iter;
	if (c >= 0.875)
		return (148 << 24 | 0 << 16 | 211 << 8 | 254);
	else if (c <= 0.125)
		return (255 << 24 | 0 << 16 | 0 << 8 | 254);
	else if (c <= 0.25)
		return (75 << 24 | 0 << 16 | 130 << 8 | 254);
	else if (c <= 0.375)
		return (0 << 24 | 0 << 16 | 255 << 8 | 254);
	else if (c <= 0.5)
		return (0 << 24 | 255 << 16 | 0 << 8 | 254);
	else if (c <= 0.625)
		return (255 << 24 | 255 << 16 | 0 << 8 | 254);
	else if (c <= 0.75)
		return (79 << 24 | 195 << 16 | 247 << 8 | 254);
	else
		return (255 << 24 | 127 << 16 | 0 << 8 | 254);
}

int	ft_pixel_bn(t_frac *f, int i)
{
	int	c;

	c = (255 / f->iter) * i;
	return (c << 24 | c << 16 | c << 8 | 254);
}

int	ft_pixel_nb(t_frac *f, int i)
{
	int	c;

	c = 255 - ((255 / f->iter) * i);
	return (c << 24 | c << 16 | c << 8 | 254);
}

int	ft_pixel_random(t_frac *f, int i)
{
	int	c;

	c = (255 / f->iter) * i;
	return (255 << 24 | (c - i) << 16 | 0 << 8 | 254);
}
