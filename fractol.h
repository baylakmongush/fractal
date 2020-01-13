/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:37:30 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/13 17:34:23 by npetrell         ###   ########.fr       */
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
}				t_fract;

int				key_press(int key, t_fract *struct_fract);
void			*mandelbrot_func(void *data);
int				mouse_press(int mouse, int x, int y, t_fract *struct_fract);
void			julia_func(t_fract *struct_fract);
void			mandelbrot_pthread(t_fract *data);
#endif
