/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:25:33 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/06 20:39:37 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int color_1(double n, int i, t_fract *struct_fract)
{
    double         t;
    int             mass[3];
    
    t = n / struct_fract->max_iter;
    mass[0] = (int)(9 * (1 - t) * pow(t, 3) * 255);
    mass[1] = (int)(15 * pow(1 - t, 2) * pow(t, 2) * 255);
    mass[2] = (int)(8.5 * pow(1 - t, 3) * t * 255);
    return (mass[i]);
}

void			julia_func(t_fract *struct_fract)
{
    double		Re_factor;
    double		Im_factor;
	unsigned	y;
	unsigned	x;
	int			isInside;
	double      n;
	double		k_re;
	double		k_im;
	double		Z_re;
	double		Z_im;
	double 		Z_re2;
	double		Z_im2;

	Re_factor = (struct_fract->MaxRe - struct_fract->MinRe) / (struct_fract->ImageWidth - 1);
	Im_factor = (struct_fract->MaxIm - struct_fract->MinIm) / (struct_fract->ImageHeight - 1);
	y = 0;
    int i = 0;
    while (y++ < struct_fract->ImageHeight)
    {
        k_im = struct_fract->MaxIm - y * Im_factor;
		x = 0;
        while (x++ < struct_fract->ImageWidth)
        {
            k_re = struct_fract->MinRe + x * Re_factor;
			Z_re = k_re; // инициализация действ части
			Z_im = k_im; // инициализация мнимой части 
            isInside = TRUE;
			n = 0;
            while (n++ < struct_fract->max_iter)
            {
                Z_re2 = pow(Z_re, 2); // квадрат действительной части 
				Z_im2 = pow(Z_im, 2); // квадрат мнимой части
                if (Z_re2 + Z_im2 > 4) // проверка, принадлежит ли точка кругу с радиусом 2.
                {
                    isInside = FALSE;
                    break;
                }
                Z_im = 2 * Z_re * Z_im + k_im; // основная формула Мандельброта
                Z_re = Z_re2 - Z_im2 + k_re;
            }
            if (i < 2)
                i++;
            isInside ? mlx_pixel_put(struct_fract->mlx_ptr, struct_fract->win_ptr, x, y, 0x000000) : mlx_pixel_put(struct_fract->mlx_ptr, struct_fract->win_ptr, x, y, color_1(n, i, struct_fract));
        }
    }
}