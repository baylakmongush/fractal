/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:37:30 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/19 22:50:01 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE 800
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "math.h"
# include "pthread.h"

typedef struct	s_fract
{
	double		min_re;
	double		min_im;
	int			x;
	int			y;
	double		zoom;
	int			color;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			image_height;
	int			image_width;
	double		iter;
	double		max_iter;
	double		k_im;
	double		k_re;
	int			fractol;
}				t_fract;

int				key_press(int key, t_fract *struct_fract);
int				mouse_press(int mouse, int x, int y, t_fract *struct_fract);
void			mandelbrot_pthread(t_fract *data);
void			put_pxl_to_img(t_fract *data, int x, int y, int color);
void			julia_pthread(t_fract *struct_fract);
int				julia_motion(int x, int y, t_fract *fractol);
void			*celc_mandelbar_func(void *data);
void			celc_mandelbar_pthread(t_fract *struct_fract);
#endif
