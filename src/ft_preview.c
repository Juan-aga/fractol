/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preview.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:00:14 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/14 13:26:08 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_show_mandel(t_frac *f);
static void	ft_show_julia(t_frac *f);
static void	ft_show_ship(t_frac *f);

void	ft_preview(t_frac *f)
{
	int	color;

	f->y = -1;
	while (++f->y < STEXT)
	{
		f->x = -1;
		while (++f->x < STEXT)
		{
			ft_show_mandel(f);
			color = ft_mandel(f, &f->z, &f->c);
			color = ft_bernstein_bw(f, color);
			mlx_put_pixel(f->preview, f->x, f->y, color);
			ft_show_julia(f);
			color = ft_mandel(f, &f->z, &f->c);
			color = ft_bernstein_bw(f, color);
			mlx_put_pixel(f->preview, f->x, (f->y + STEXT), color);
			ft_show_ship(f);
			color = ft_burning_ship(f, &f->z, &f->c);
			color = ft_bernstein_bw(f, color);
			mlx_put_pixel(f->preview, f->x, (f->y + STEXT + STEXT), color);
		}
	}
	mlx_image_to_window(f->mlx, f->preview, WTEXT + WIDTH, 0);
}

static void	ft_show_mandel(t_frac *f)
{
	f->c.real = (-2 + (f->x * (1.3 * 2 / STEXT)));
	f->c.img = (1.3 - (f->y * (1.3 * 2 / STEXT)));
	f->z.real = 0.0;
	f->z.img = 0.0;
}

static void	ft_show_julia(t_frac *f)
{
	f->z.real = (-1.6 + (f->x * (1.6 * 2 / STEXT)));
	f->z.img = (1.6 - (f->y * (1.6 * 2 / STEXT)));
	f->c.real = f->h.real + PRE * f->j;
	f->c.img = f->h.img + PRE * f->j;
}

static void	ft_show_ship(t_frac *f)
{
	f->c.real = (-1.2 + (f->x * (1.7 * 2 / STEXT)));
	f->c.img = (2.3 - (f->y * (1.7 * 2 / STEXT)));
	f->z.real = 0.0;
	f->z.img = 0.0;
}
