/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:37:30 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/30 01:09:35 by baylak           ###   ########.fr       */
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

typedef struct	s_color
{
  int	r;
  int	g;
  int	b;
} 				t_color;

typedef struct	s_fract
{
	int			id;
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
	double		c_re;
	double		c_im;
	int			fractol;
	pthread_t	pthread;
}				t_fract;

int				key_press(int key, t_fract *struct_fract);
int				mouse_press(int mouse, int x, int y, t_fract *struct_fract);
void			mandelbrot_pthread(t_fract *data);
void			put_pxl(t_fract *data, int x, int y);
void			julia_pthread(t_fract *struct_fract);
int				julia_motion(int x, int y, t_fract *fractol);
void			celt_mandelbar_pthread(t_fract *struct_fract);
void			draw(t_fract *struct_fract);
void			mandelbar_pthread(t_fract *struct_fract);
int				ft_close(void);
#endif
