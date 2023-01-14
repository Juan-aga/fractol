/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:04:08 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/14 13:14:06 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol_utils.h"
#include <math.h>

int	ft_mandel(t_frac *f, t_com *Z, t_com *C)
{
	int		i;

	i = -1;
	while (++i < f->iter)
	{
		if ((Z->real * Z->real) + (Z->img * Z->img) >= 4)
			return (i);
		(*Z) = ft_mult_complex((*Z), (*Z));
		Z->real += C->real;
		Z->img += C->img;
	}
	return (i);
}

int	ft_burning_ship(t_frac *f, t_com *Z, t_com *C)
{
	int		i;
	t_com	temp;

	i = -1;
	while (++i < f->iter)
	{
		if ((Z->real * Z->real) + (Z->img * Z->img) >= 4)
			return (i);
		temp = ft_mult_complex((*Z), (*Z));
		Z->img = fabs(2 * Z->real * Z->img);
		Z->real = fabs(temp.real - C->real);
		Z->img -= C->img;
	}
	return (i);
}

void	ft_reset(t_frac *f)
{
	if (f->mx > WTEXT + WIDTH)
	{
		f->limx = -2;
		f->limy = 2;
		f->paso = (f->limy * 2) / WIDTH;
		f->iter = 50;
		f->j = 0;
		if (f->ac == 4)
		{
			f->h.real = ft_atof(f->av[2]);
			f->h.img = ft_atof(f->av[3]);
		}
		else
			f->h = (t_com){-0.835, -0.2321};
		if (f->my < WIDTH / 3)
			f->f = 0;
		else if (f->my < WIDTH - WIDTH / 3)
			f->f = 1;
		else
			f->f = 2;
		ft_rename(f);
	}
}

void	ft_rename(t_frac *f)
{
	if (f->f == 0)
		mlx_set_window_title(f->mlx, "MANDELBROT");
	else if (f->f == 1)
		mlx_set_window_title(f->mlx, "JULIA");
	else
		mlx_set_window_title(f->mlx, "BURNING SHIP");
}
