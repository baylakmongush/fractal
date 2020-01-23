/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_mandelbar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:21:40 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/23 18:53:15 by npetrell         ###   ########.fr       */
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
	put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, 0x000000) :
	put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y,
	struct_fract->color * struct_fract->iter);
}

void			*celc_mandelbar_func(void *data)
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

void			celc_mandelbar_pthread(t_fract *struct_fract)
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
		pthread_create(&t[i], NULL, celc_mandelbar_func, &tab[i]);
		i++;
	}
	i = 0;
	while (i < 160)
	{
		pthread_join(t[i], NULL);
		i++;
	}
	mlx_put_image_to_window(struct_fract->mlx_ptr, struct_fract->win_ptr,
struct_fract->img, 0, 0);
}
