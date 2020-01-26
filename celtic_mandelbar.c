/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_mandelbar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:21:40 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/26 15:19:27 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		celt_mand_put(t_fract *struct_fract)
{
	double		z_re;
	double		z_im;
	double		tmp;

	struct_fract->c_im = struct_fract->y / struct_fract->zoom +
struct_fract->min_im;
	struct_fract->c_re = struct_fract->x / struct_fract->zoom +
struct_fract->min_re;
	z_re = struct_fract->c_re;
	z_im = struct_fract->c_im;
	struct_fract->iter = 0;
	while (struct_fract->iter < struct_fract->max_iter &&
((pow(z_re, 2) + pow(z_im, 2)) <= 4))
	{
		tmp = z_re;
		z_re = fabs(pow(z_re, 2) - pow(z_im, 2)) + struct_fract->c_re;
		z_im = -2.0 * tmp * z_im + struct_fract->c_im;
		struct_fract->iter++;
	}
	(struct_fract->iter == struct_fract->max_iter) ?
	put_pxl(struct_fract, struct_fract->x, struct_fract->y, 0x000000) :
	put_pxl(struct_fract, struct_fract->x, struct_fract->y,
	struct_fract->color * struct_fract->iter);
}

void			*celt_mandelbar_func(void *data)
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
			celt_mand_put(struct_fract);
			struct_fract->x++;
		}
		struct_fract->y++;
	}
	return (NULL);
}

void			celt_mandelbar_pthread(t_fract *struct_fract)
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
		pthread_create(&thread[i], NULL, celt_mandelbar_func, &tmp[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(struct_fract->mlx_ptr, struct_fract->win_ptr,
struct_fract->img, 0, 0);
}
