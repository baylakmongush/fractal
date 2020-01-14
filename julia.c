/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:27:06 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/14 18:27:53 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void			julia_func(t_fract *struct_fract)
{
	double      iter;
	double		Z_re;
	double		Z_im;
	double		Z_im2;

   // mlx_put_image_to_window(struct_fract->mlx_ptr, struct_fract->win_ptr, struct_fract->img, 0, 0);
    struct_fract->y = 0;
    while (struct_fract->y < SIZE)
    {
         struct_fract->k_im = 0.6;
        struct_fract->k_re = -0.4;
		struct_fract->x = 0;
        while (struct_fract->x < SIZE)
        {
			Z_re = struct_fract->k_re; 
			Z_im = struct_fract->k_im; 
			iter = 0;
            while (iter < struct_fract->max_iter && ((pow(Z_re, 2) + pow(Z_im, 2)) < 4))
            {
				Z_im2 = pow(Z_im, 2);
                Z_im = 2 * Z_re * Z_im + struct_fract->k_im;
                Z_re = pow(Z_re, 2) - Z_im2 + struct_fract->k_re;
                iter++;
            }
           // (iter == struct_fract->max_iter) ? put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, 0x000000)
          //  : put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, struct_fract->color * iter);
          (iter == struct_fract->max_iter) ? mlx_pixel_put(struct_fract->mlx_ptr, struct_fract->win_ptr, struct_fract->x, struct_fract->y, 0x000000)
            : mlx_pixel_put(struct_fract->mlx_ptr, struct_fract->win_ptr, struct_fract->x, struct_fract->y, 0xffffff);
			struct_fract->x++;
        }
		struct_fract->y++;
    }
}