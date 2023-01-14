/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 02:45:24 by juan-aga          #+#    #+#             */
/*   Updated: 2022/12/15 20:27:04 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_utils.h"

double	ft_power_double(double n, int pov)
{
	int	i;
	int	num;

	i = -1;
	num = 1;
	if (n < 0)
		n *= -1;
	while (++i < pov)
		num *= 10;
	return (n * num);
}
