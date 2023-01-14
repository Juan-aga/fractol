/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:20:42 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/14 13:00:23 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_complex_calc(t_frac *f);
static void	ft_complex2(t_frac *f, t_com *Z, t_com *C);
static void	ft_complex(t_frac *f, t_com *Z, t_com *C);

void	ft_fill_pixel(t_frac *f)
{
	int	color;
	int	cont;

	f->y = -1;
	while (++f->y < WIDTH)
	{
		f->x = -1;
		while (++f->x < (WIDTH))
		{
			cont = 0;
			ft_complex_calc(f);
			if (f->f == 2)
				color = ft_burning_ship(f, &f->z, &f->c);
			else
				color = ft_mandel(f, &f->z, &f->c);
			color = ft_change_color(f, color);
			mlx_put_pixel(f->img, f->x, f->y, color);
		}
	}
}

static void	ft_complex_calc(t_frac *f)
{
	if (f->f != 1)
		ft_complex(f, &f->z, &f->c);
	else
		ft_complex2(f, &f->z, &f->c);
}

static void	ft_complex(t_frac *f, t_com *Z, t_com *C)
{
	C->real = (f->limx + (f->x * f->paso));
	C->img = (f->limy - (f->y * f->paso));
	Z->real = 0.0;
	Z->img = 0.0;
}

static void	ft_complex2(t_frac *f, t_com *Z, t_com *C)
{
	Z->real = (f->limx + (f->x * f->paso));
	Z->img = (f->limy - (f->y * f->paso));
	C->real = f->h.real + PRE * f->j;
	C->img = f->h.img + PRE * f->j;
}
