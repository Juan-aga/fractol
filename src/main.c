/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:40:24 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/14 13:30:49 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include "MLX42.h"
#include "fractol.h"
#include "libft.h"
#include "fractol_utils.h"

static void	ft_create(t_frac *f);
static void	ft_image(t_frac *f);
static void	ft_check_args(int ac, char **av);

int	main(int ac, char **av)
{
	t_frac	*f;

	ft_check_args(ac, av);
	f = (t_frac *) malloc(sizeof(t_frac));
	if (!f)
		exit (1);
	f->f = av[1][0] - '0';
	if (f->f == 1 && ac == 4)
	{
		f->h.real = ft_atof(av[2]);
		f->h.img = ft_atof(av[3]);
	}
	else
		f->h = (t_com){-0.835, -0.2321};
	f->ac = ac;
	f->av = av;
	ft_create(f);
	ft_image(f);
	free(f);
	return (0);
}

static void	ft_create(t_frac *f)
{
	f->limx = -2;
	f->limy = 2;
	f->paso = (f->limy * 2) / WIDTH;
	f->iter = 75;
	f->color = 6;
	f->zoom = PRE * 4;
	f->j = 0;
}

static void	ft_image(t_frac *f)
{
	f->mlx = mlx_init(WIDTH + WTEXT + STEXT, WIDTH, "FractOL", false);
	if (!f->mlx)
		exit (EXIT_FAILURE);
	f->img = mlx_new_image(f->mlx, WIDTH, WIDTH);
	if (!f->img)
		exit (EXIT_FAILURE);
	f->help = mlx_new_image(f->mlx, WTEXT, WIDTH);
	if (!f->help)
		exit (EXIT_FAILURE);
	f->preview = mlx_new_image(f->mlx, STEXT, WIDTH);
	if (!f->preview)
		exit (EXIT_FAILURE);
	ft_text(f);
	ft_preview(f);
	ft_fill_pixel(f);
	mlx_image_to_window(f->mlx, f->img, WTEXT, 0);
	mlx_loop_hook(f->mlx, key_hook, &f);
	mlx_key_hook(f->mlx, &my_keyhook, &f);
	mlx_scroll_hook(f->mlx, my_scroll_hook, &f);
	mlx_loop(f->mlx);
	mlx_terminate(f->mlx);
}

static void	ft_check_args(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac != 4 || (av[1][0] - 48) != 1)
		{
			ft_usage();
			exit(EXIT_FAILURE);
		}
	}
	else if (av[1][0] > '2')
	{
		ft_usage();
		exit(EXIT_FAILURE);
	}	
}
