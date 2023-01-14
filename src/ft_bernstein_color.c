/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bernstein_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:06:45 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/13 21:52:00 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	ft_bernstein_color(t_frac *f, int iter)
{
	t_rgb	new;
	float	scape;
	float	norm;

	scape = (float) iter / f->iter;
	if (scape >= 1 || scape <= 0)
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
	norm = 1 - scape;
	new.g = 15 * (norm * norm) * (scape * scape) * 255;
	new.b = 8.5 * (norm * norm * norm) * scape * 255;
	return (0 << 24 | (int) new.g << 16 | (int) new.b << 8 | 255);
}

int	ft_bernstein_bw(t_frac *f, int iter)
{
	int		c;
	double	scape;

	scape = (255 / f->iter) * iter;
	if (scape <= 0)
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
	c = scape;
	return (c << 24 | c << 16 | c << 8 | 255);
}
