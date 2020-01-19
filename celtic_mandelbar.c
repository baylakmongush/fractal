/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_mandelbar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:21:40 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/19 22:42:21 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			*celc_mandelbar_func(void *data)
{
    t_fract     *struct_fract;
	double      iter;
	double		c_re;
	double		c_im;
	double		Z_re;
	double		Z_im;
    double      tmp;

    struct_fract = (t_fract*)data;
    while (struct_fract->y < struct_fract->image_height)
    {
		struct_fract->x = 0;
        while (struct_fract->x < SIZE)
        {
			c_im = struct_fract->y / struct_fract->zoom + struct_fract->min_im;
            c_re = struct_fract->x / struct_fract->zoom + struct_fract->min_re;
			Z_re = c_re; 
			Z_im = c_im; 
			iter = 0;
            while (iter < struct_fract->max_iter && ((pow(Z_re, 2) + pow(Z_im, 2)) <= 4))
            {
                tmp = Z_re;
                Z_re = fabs(pow(Z_re, 2) - pow(Z_im, 2)) + c_re;
                Z_im = -2.0 * tmp * Z_im + c_im;
                iter++;
            }
            (iter == struct_fract->max_iter) ? put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, 0x000000)
            : put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, struct_fract->color * iter);
			struct_fract->x++;;
        }
		struct_fract->y++;
    }
    return (NULL);
}

void	celc_mandelbar_pthread(t_fract *struct_fract)
{
	t_fract     tab[160];
	pthread_t	t[160];
	int			i;

	i = 0;
	while (i < 160)
	{
		ft_memcpy((void*)&tab[i], (void*)struct_fract, sizeof(t_fract));
		tab[i].y = 5 * i;
		tab[i].image_height = 5 * (i + 1);
		pthread_create(&t[i], NULL, celc_mandelbar_func, &tab[i]);
		i++;
	}
    while (i--)
		pthread_join(t[i], NULL);
    mlx_put_image_to_window(struct_fract->mlx_ptr, struct_fract->win_ptr, struct_fract->img, 0, 0);
}