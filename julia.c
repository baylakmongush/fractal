/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:27:06 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/23 18:41:18 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pxl_to_img(t_fract *data, int x, int y, int color)
{
	if (data->x < SIZE && data->y < SIZE)
	{
		color = mlx_get_color_value(data->mlx_ptr, color);
		ft_memcpy(data->img_ptr + 4 * SIZE * y + x * 4, &color, sizeof(int));
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
put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, 0x000000) :
put_pxl_to_img(struct_fract, struct_fract->x,
	struct_fract->y, struct_fract->color * struct_fract->iter);
}

void			*julia_func(void *data)
{
	t_fract		*struct_fract;
	double		tmp;

	struct_fract = (t_fract*)data;
	struct_fract->min_re = -1.4;
	struct_fract->min_im = -1.4;
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
	t_fract		tab[160];
	pthread_t	t[160];
	int			i;

	i = 0;
	while (i < 160)
	{
		ft_memcpy((void*)&tab[i], (void*)struct_fract, sizeof(t_fract));
		tab[i].x = 5 * i;
		tab[i].image_width = 5 * (i + 1);
		pthread_create(&t[i], NULL, julia_func, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(struct_fract->mlx_ptr, struct_fract->win_ptr,
	struct_fract->img, 0, 0);
}
