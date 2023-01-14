/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcolors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:40:34 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/13 22:08:24 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int		ft_color_rgba(t_rgb color);
static double	ft_new_color(double start, double end, double dif);

int	ft_black_white(t_frac *f, int iter)
{
	t_rgb	new;
	t_rgb	*palette;
	double	l;

	palette = (t_rgb[8]){{148, 0, 211}, {255, 0, 0}, {75, 0, 130},
	{0, 0, 255}, {0, 255, 0}, {255, 255, 0}, {79, 195, 247},
	{255, 127, 0}};
	if (iter < f->iter)
		l = iter + 1 - log(log2(sqrt(f->z.real * f->z.real
						+ f->z.img * f->z.img))) / log(2);
	else if (iter > 0)
		l = f->iter;
	else
		l = 0.0;
	new.r = ft_new_color(palette[(int)floor(l) % 8].r,
			palette[((int)floor(l)+1) % 8].r, l - floor(l));
	new.g = ft_new_color(palette[(int)floor(l) % 8].g,
			palette[((int)floor(l)+1) % 8].g, l - floor(l));
	new.b = ft_new_color(palette[(int)floor(l) % 8].b,
			palette[((int)floor(l)+1) % 8].b, l - floor(l));
	return (ft_color_rgba(new));
}

int	ft_four(t_frac *f, int iter)
{
	t_rgb	new;
	t_rgb	*palette;
	double	l;

	palette = (t_rgb[5]){{171, 194, 112}, {254, 200, 104}, {253, 167, 105},
	{71, 60, 51}, {171, 194, 112}};
	if (iter < f->iter)
		l = iter + 1 - log(log2(sqrt(f->z.real * f->z.real
						+ f->z.img * f->z.img))) / log(2);
	if (iter <= 0)
		l = 0.0;
	new.r = ft_new_color(palette[(int)floor(l) % 5].r,
			palette[((int)floor(l)+1) % 5].r, l - floor(l));
	new.g = ft_new_color(palette[(int)floor(l) % 5].g,
			palette[((int)floor(l)+1) % 5].g, l - floor(l));
	new.b = ft_new_color(palette[(int)floor(l) % 5].b,
			palette[((int)floor(l)+1) % 5].b, l - floor(l));
	return (ft_color_rgba(new));
}

static double	ft_new_color(double start, double end, double iter)
{
	int	dif;

	dif = start - end;
	if (dif < 0)
		return (start + (int)(iter * -dif));
	else
		return (start - (int)(iter * dif));
}

static int	ft_color_rgba(t_rgb color)
{
	int	r;
	int	g;
	int	b;

	r = color.r;
	g = color.g;
	b = color.b;
	return (r << 24 | g << 16 | b << 8 | 255);
}
