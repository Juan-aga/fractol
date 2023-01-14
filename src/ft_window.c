/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:57:29 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/14 13:18:38 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "ft_printf.h"

static void	ft_background(t_frac *f);

void	ft_text(t_frac *f)
{
	mlx_image_t	*frac;
	char		*str;
	int			cont;
	int			fd;

	cont = 0;
	ft_background(f);
	frac = mlx_put_string(f->mlx, "FRACT'OL", WTEXT / 2 - 80, 20);
	fd = open("src/instructions.h", O_RDONLY);
	while (cont++ <= 12)
	{
		str = get_next_line(fd);
		free(str);
	}
	cont = 9;
	str = get_next_line(fd);
	while (str)
	{
		mlx_put_string(f->mlx, str, 20, cont * 20);
		free(str);
		cont++;
		str = get_next_line(fd);
	}
	close(fd);
	ft_preview(f);
}

static void	ft_background(t_frac *f)
{
	int	x;
	int	y;
	int	c;

	x = -1;
	y = -1;
	c = 0 << 24 | 0 << 16 | 0 << 8 | 255;
	while (++y < WIDTH)
	{
		while (++x < WTEXT)
			mlx_put_pixel(f->help, x, y, c);
		x = -1;
	}
	y = -1;
	while (++y < WIDTH)
	{
		while (++x < STEXT)
			mlx_put_pixel(f->preview, x, y, c);
		x = -1;
	}
	mlx_image_to_window(f->mlx, f->help, 0, 0);
	ft_rename(f);
}

void	ft_usage(void)
{
	ft_printf("\n\tFractOL usage:\n\n\tNumber:\tFractal:\n");
	ft_printf("\t0\tMandelbrot\n\t1\tJulia\n\t2\tBurningship\n");
	ft_printf("\n\tFor Julia you con enter the start position\n");
	ft_printf("\tFor example:\n\t\t./fractol 1 -0.835 -0.2321\n");
	ft_printf("\t\t./fractol 1 0.285 0.01\n");
}
