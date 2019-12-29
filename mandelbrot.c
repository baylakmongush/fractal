/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:43:44 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/29 18:27:29 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int color(double n, double max_iter, int i)
{
    double         t;
    int             mass[3];
    
    t = n / max_iter;
    mass[0] = (int)(9 * (1 - t) * t * t * t * 255);
    mass[1] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    mass[2] = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (mass[i]);
}

void			mandelbrot_func(t_fract *struct_fract)
{
    double		MinRe;
    double		MaxRe;
    double		MinIm;
    double		MaxIm;
    double		Re_factor;
    double		Im_factor;
    unsigned	MaxIterations;
	unsigned	y;
	unsigned	x;
	int			isInside;
	double	n;
	double		c_re;
	double		c_im;
	double		Z_re;
	double		Z_im;
	double 		Z_re2;
	double		Z_im2;

    MinRe = -2.0;
    MaxRe = 2.0;
    MinIm = -2.0;
	MaxIm = MinIm + (MaxRe - MinRe) * struct_fract->ImageHeight / struct_fract->ImageWidth;
	Re_factor = (MaxRe - MinRe) / (struct_fract->ImageWidth - 1);
	Im_factor = (MaxIm - MinIm) / (struct_fract->ImageHeight - 1);
	MaxIterations = 30;
	y = 0;
    int i = 0;
    while (y++ < struct_fract->ImageHeight)
    {
        c_im = MaxIm - y * Im_factor;
		x = 0;
        while (x++ < struct_fract->ImageWidth)
        {
            c_re = MinRe + x * Re_factor;
			Z_re = c_re; // инициализация действ части
			Z_im = c_im; // инициализация мнимой части 
            isInside = TRUE;
			n = 0;
            while (n++ < MaxIterations)
            {
                Z_re2 = Z_re * Z_re; // квадрат действительной части 
				Z_im2 = Z_im * Z_im; // квадрат мнимой части
                if (Z_re2 + Z_im2 > 4) // проверка, принадлежит ли точка кругу с радиусом 2.
                {
                    isInside = FALSE;
                    break;
                }
                Z_im = 2 * Z_re * Z_im + c_im; // основная формула Мандельброта
                Z_re = Z_re2 - Z_im2 + c_re;
            }
            if (i < 2)
            i++;
            isInside ? mlx_pixel_put(struct_fract->mlx_ptr, struct_fract->win_ptr, x, y, 0x000000) : mlx_pixel_put(struct_fract->mlx_ptr, struct_fract->win_ptr, x, y, color(n, MaxIterations, i));
        }
    }
}
