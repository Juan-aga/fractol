/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:49:24 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/13 21:54:23 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	ft_key_hook2(void *f);

void	key_hook(void *f)
{
	t_frac	**f2;

	f2 = (t_frac **) f;
	if (mlx_is_key_down((*f2)->mlx, MLX_KEY_ESCAPE))
		mlx_close_window((*f2)->mlx);
	if ((*f2)->key.key == MLX_KEY_C)
	{
		if ((*f2)->color == 7)
			(*f2)->color = 0;
		else
			(*f2)->color++;
		(*f2)->key.key = 0;
	}
	if (mlx_is_key_down((*f2)->mlx, MLX_KEY_J))
		(*f2)->j += 1;
	if (mlx_is_key_down((*f2)->mlx, MLX_KEY_H))
		(*f2)->j -= 1;
	if (mlx_is_key_down((*f2)->mlx, MLX_KEY_UP))
		ft_move((*f2), "u\0");
	else if (mlx_is_key_down((*f2)->mlx, MLX_KEY_DOWN))
		ft_move((*f2), "d\0");
	ft_key_hook2(f);
}

static void	ft_key_hook2(void *f)
{
	t_frac	**f2;

	f2 = (t_frac **) f;
	if (mlx_is_key_down((*f2)->mlx, MLX_KEY_LEFT))
		ft_move((*f2), "l\0");
	else if (mlx_is_key_down((*f2)->mlx, MLX_KEY_RIGHT))
		ft_move((*f2), "r\0");
	if (mlx_is_key_down((*f2)->mlx, MLX_KEY_KP_ADD))
		ft_move((*f2), "ula");
	else if (mlx_is_key_down((*f2)->mlx, MLX_KEY_KP_SUBTRACT))
		ft_move((*f2), "drs");
	if (mlx_is_key_down((*f2)->mlx, MLX_KEY_KP_MULTIPLY))
		(*f2)->iter *= 1.1;
	else if (mlx_is_key_down((*f2)->mlx, MLX_KEY_KP_DIVIDE))
		(*f2)->iter /= 1.1;
	ft_fill_pixel((*f2));
	mlx_get_mouse_pos((*f2)->mlx, &(*f2)->mx, &(*f2)->my);
	if (mlx_is_mouse_down((*f2)->mlx, MLX_MOUSE_BUTTON_LEFT))
		ft_reset((*f2));
	mlx_image_to_window((*f2)->mlx, (*f2)->img, WTEXT, 0);
}

void	my_keyhook(mlx_key_data_t keydata, void *f)
{
	t_frac	**f2;

	f2 = (t_frac **) f;
	if (keydata.action == MLX_RELEASE)
		(*f2)->key.key = keydata.key;
}

void	my_scroll_hook(double x, double y, void *f)
{
	t_frac	**f2;

	f2 = (t_frac **) f;
	(void) x;
	(void) y;
	if (y < 0)
	{
		if ((*f2)->mx > WTEXT && (*f2)->mx < WTEXT + WIDTH)
			ft_move_mouse((*f2), 'i');
		else
			ft_move((*f2), "ula");
	}
	else if (y > 0)
	{
		if ((*f2)->mx > WTEXT && (*f2)->mx < WTEXT + WIDTH)
			ft_move_mouse((*f2), 'o');
		else
			ft_move((*f2), "drs");
	}
}
