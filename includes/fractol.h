/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:37:30 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/30 15:00:05 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE 800
# include <stdlib.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "math.h"
# include "pthread.h"

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			center;
	int			width;
	double		step;
}				t_color;

typedef struct	s_prms
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
}				t_prms;

typedef struct	s_fract
{
	t_prms		params;
	t_color		clr;
	double		min_re;
	double		min_im;
	int			x;
	int			y;
	double		zoom;
	int			image_width;
	double		iter;
	double		max_iter;
	double		k_im;
	double		k_re;
	double		c_re;
	double		c_im;
	int			fractol;
	pthread_t	pthread;
}				t_fract;

int				key_press(int key, t_fract *struct_fract);
int				key_press2(int key, t_color *clr, t_fract *struct_fract);
int				mouse_press(int mouse, int x, int y, t_fract *struct_fract);
void			put_pxl(t_fract *data, int x, int y);
int				julia_motion(int x, int y, t_fract *fractol);
void			draw(t_fract *struct_fract);
void			fract_pthread_create(t_fract *struct_fract);
int				ft_close(void);
void			*mandelbrot_func(void *data);
void			*julia_func(void *data);
void			*mandelbar_func(void *data);
void			*celt_mandelbar_func(void *data);

#endif
