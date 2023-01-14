/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:13:15 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/14 13:13:47 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42.h"
# include "libft.h"

//# define HEIGHT 1000
# define WIDTH 750
# define WTEXT 500
# define STEXT 250
# define PRE 0.0078125

typedef struct s_com
{
	double	real;
	double	img;
}	t_com;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

typedef struct s_frac
{
	int							f;
	int							j;
	int							ac;
	char						**av;
	double						iter;
	double						limx;
	double						limy;
	double						paso;
	int							x;
	int							y;
	int							color;
	t_com						c;
	t_com						z;
	t_com						h;
	mlx_t						*mlx;
	mlx_image_t					*img;
	mlx_image_t					*help;
	mlx_image_t					*preview;
	struct mlx_key_data			key;
	int							mx;
	int							my;
	double						zoom;
}	t_frac;

/*	WINDOWS INFORMATION	*/
void	ft_text(t_frac *f);
void	ft_rename(t_frac *f);
//void	ft_create(t_frac *f);
void	ft_reset(t_frac *f);

/*			COLORS		*/
int		ft_change_color(t_frac *f, int i);
/*			0			*/
int		ft_black_white(t_frac *f, int i);
/*			0			*/
int		ft_pixel_bn(t_frac *f, int i);		
/*			1			*/
int		ft_pixel_nb(t_frac *f, int i);
/*			2			*/
int		ft_pixel_random(t_frac *f, int i);
/*			3			*/
int		ft_pixel(t_frac *f, int i);
/*						*/
int		ft_bernstein_color(t_frac *f, int i);
/*						*/
int		ft_bernstein_bw(t_frac *f, int i);
/*						*/
int		ft_four(t_frac *f, int i);
/*		HOOKS			*/
void	key_hook(void *f);
void	my_keyhook(mlx_key_data_t keydata, void *f);
void	my_scroll_hook(double x, double y, void *f);
/*		DRAW FRACTAL	*/
void	ft_fill_pixel(t_frac *f);
int		ft_mandel(t_frac *f, t_com *Z, t_com *C);
int		ft_burning_ship(t_frac *f, t_com *Z, t_com *C);
void	ft_move(t_frac *f, char *list);
void	ft_move_mouse(t_frac *f, char list);
/*		MATHS			*/
t_com	ft_mult_complex(t_com a, t_com b);
/*		PREVIEW			*/
void	ft_preview(t_frac *f);
/*		USAGE			*/
void	ft_usage(void);
#endif
