/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:00:03 by juan-aga          #+#    #+#             */
/*   Updated: 2022/12/18 10:59:49 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Liist control for the movement:
 * U is up
 * D is down
 * L is left
 * R is right
 * A is for zoom in
 * S is for zoom out
*/
void	ft_move(t_frac *f, char *list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (list[i] == 'u')
			f->limy -= f->paso * f->zoom * WIDTH / 2;
		else if (list[i] == 'd')
			f->limy += f-> paso * f->zoom * WIDTH / 2;
		if (list[i] == 'l')
			f->limx += f->paso * f->zoom * WIDTH / 2;
		else if (list[i] == 'r')
			f->limx -= f->paso * f->zoom * WIDTH / 2;
		if (list[i] == 'a')
			f->paso -= f->paso * f->zoom;
		else if (list[i] == 's')
			f->paso += f->paso * f->zoom;
		i++;
	}
}

/* List control for the zoom to the mouse position
 * i is for zoom in
 * o is for zoom out
 */
void	ft_move_mouse(t_frac *f, char list)
{
	if (list == 'i')
	{
		f->limx += f->paso * f->zoom * WIDTH * ((double)f->mx - WTEXT) / WIDTH;
		f->limy -= f->paso * f->zoom * WIDTH * (double)f->my / WIDTH;
		ft_move(f, "a");
	}
	else if (list == 'o')
	{
		f->limx -= f->paso * f->zoom * WIDTH * ((double)f->mx - WTEXT) / WIDTH;
		f->limy += f->paso * f->zoom * WIDTH * (double)f->my / WIDTH;
		ft_move(f, "s");
	}
}
