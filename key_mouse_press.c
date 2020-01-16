/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:40:55 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/16 17:12:24 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	key_press(int key)
{
    if (key == 53)
        exit (0);
 //   mlx_clear_window(struct_fract->mlx_ptr, struct_fract->win_ptr);
//    mandelbrot_pthread(struct_fract);
    return (0);
}

int	mouse_press(int mouse, int x, int y, t_fract *struct_fract)
{
    if (mouse == 4)
    {
        struct_fract->MinRe = (x / struct_fract->zoom + struct_fract->MinRe) - (x / (struct_fract->zoom * 1.2));
	    struct_fract->MinIm = (y / struct_fract->zoom + struct_fract->MinIm) - (y / (struct_fract->zoom * 1.2));
	    struct_fract->zoom *= 1.2;
	    struct_fract->max_iter++;
    }
    if (mouse == 5)
    {
        struct_fract->MinRe = (x / struct_fract->zoom + struct_fract->MinRe) - (x / (struct_fract->zoom / 1.2));
	    struct_fract->MinIm = (y / struct_fract->zoom + struct_fract->MinIm) - (y / (struct_fract->zoom / 1.2));
	    struct_fract->zoom /= 1.2;
	    struct_fract->max_iter--;
    }
    if (mouse == 1)
    {
        struct_fract->k_re = 4 * ((double)x / SIZE - 0.5);
        struct_fract->k_im = 4 * ((double)(SIZE - y) / SIZE - 0.5);
        julia_pthread(struct_fract);
    }
    struct_fract->fractol == 1 ? mandelbrot_pthread(struct_fract) : julia_pthread(struct_fract);
    mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 5, 10, 0x3a8888, "iteration: ");
    mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 110, 10, 0xC5329F, ft_itoa(struct_fract->max_iter));
    return (0);
}

int julia_motion(int x, int y, t_fract *fractol)
{
    if (x > 0 && x < fractol->ImageWidth && y > 0 && y < fractol->ImageWidth)
    {
        fractol->k_re = 4 * ((double)x / SIZE - 0.5);
        fractol->k_im = 4 * ((double)(SIZE - y) / SIZE - 0.5);
        julia_pthread(fractol);
    }
    return (0);
}