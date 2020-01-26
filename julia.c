/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:27:06 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/26 16:16:29 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_color f, t_fract *data, int color)
{
	int t;
	
	t = data->iter / data->max_iter;
	f.r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	f.g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	f.b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	f.pixel = color;
	return (f.r, f.g, f.b, f.pixel);
}

void			put_pxl(t_fract *data, int x, int y, int color)
{
	t_color		f;
	int			clr;

	if (data->x < SIZE && data->y < SIZE)
	{
		clr = get_color(f, data, color);
		*(int*)(data->img_ptr + (x + y * SIZE) * 4) = clr;
	}
}

static void		draw_julia(t_fract *struct_fract)
{
	double		z_re;
	double		z_im;
	double		z_im2;

	z_re = struct_fract->x / struct_fract->zoom + struct_fract->min_re;
	z_im = struct_fract->y / struct_fract->zoom + struct_fract->min_im;
	struct_fract->iter = 0;
	while (struct_fract->iter < struct_fract->max_iter &&
((pow(z_re, 2) + pow(z_im, 2)) < 4))
	{
		z_im2 = pow(z_im, 2);
		z_im = 2 * z_re * z_im + struct_fract->k_im;
		z_re = pow(z_re, 2) - z_im2 + struct_fract->k_re;
		struct_fract->iter++;
	}
	(struct_fract->iter == struct_fract->max_iter) ?
put_pxl(struct_fract, struct_fract->x, struct_fract->y, 0x000000) :
put_pxl(struct_fract, struct_fract->x,
	struct_fract->y, struct_fract->color * struct_fract->iter);
}

void			*julia_func(void *data)
{
	t_fract		*struct_fract;
	double		tmp;

	struct_fract = (t_fract*)data;
	struct_fract->y = 0;
	tmp = struct_fract->x;
	while (struct_fract->y < SIZE)
	{
		struct_fract->x = tmp;
		while (struct_fract->x < struct_fract->image_width)
		{
			draw_julia(struct_fract);
			struct_fract->x++;
		}
		struct_fract->y++;
	}
	return (NULL);
}

void			julia_pthread(t_fract *struct_fract)
{
	t_fract		tmp[5];
	pthread_t	thread[5];
	int			i;

	i = 0;
	while (i < 5)
	{
		ft_memcpy((void*)&tmp[i], (void*)struct_fract, sizeof(t_fract));
		tmp[i].x = ((1.00 / 5) * SIZE) * i;
		tmp[i].image_width = ((1.00 / 5) * SIZE) * (i + 1);
		pthread_create(&thread[i], NULL, julia_func, &tmp[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(struct_fract->mlx_ptr, struct_fract->win_ptr,
struct_fract->img, 0, 0);
}
