/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:44:57 by juan-aga          #+#    #+#             */
/*   Updated: 2022/12/21 08:55:14 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_com	ft_mult_complex(t_com a, t_com b)
{
	t_com	r;

	r.real = (a.real * b.real - a.img * b.img);
	r.img = (a.real * b.img) + (a.img * b.real);
	return (r);
}
