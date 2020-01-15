/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:37:30 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/15 20:47:00 by npetrell         ###   ########.fr       */
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
	double		MinRe;
    double		MinIm;
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
	int			ImageHeight;
	int			ImageWidth;
	double		max_iter;
	double		k_im;
	double		k_re;
}				t_fract;

int				key_press(int key);
int				mouse_press(int mouse, int x, int y, t_fract *struct_fract);
void			mandelbrot_pthread(t_fract *data);
void			put_pxl_to_img(t_fract *data, int x, int y, int color);
void			julia_pthread(t_fract *struct_fract);
#endif
