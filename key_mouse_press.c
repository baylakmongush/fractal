/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:40:55 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/06 20:02:56 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	key_press(int key, t_fract *struct_fract)
{
    if (key == 53)
        exit (0);
    if (key == 24)
    {
        struct_fract->max_iter += 10;
    }
    if (key == 27 && struct_fract->max_iter > 0)
    {
        struct_fract->max_iter -= 10;
    }
    mlx_clear_window(struct_fract->mlx_ptr, struct_fract->win_ptr);
    mandelbrot_func(struct_fract);
    mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 900, 900, 0xC5329F,ft_itoa(struct_fract->max_iter));
    return (0);
}

int	mouse_press(int mouse, int x, int y, t_fract *struct_fract)
{
    x = 0;
    y = 0;
    if (mouse == 4)
    {
        struct_fract->MinRe *= 2.3;
        struct_fract->MaxRe = fabs(struct_fract->MinRe);
        struct_fract->MinIm = -struct_fract->MaxRe;
	    struct_fract->MaxIm = struct_fract->MinIm + (struct_fract->MaxRe
- struct_fract->MinRe) * struct_fract->ImageHeight / struct_fract->ImageWidth;
        mlx_clear_window(struct_fract->mlx_ptr, struct_fract->win_ptr);
        mandelbrot_func(struct_fract);
    }
    if (mouse == 5)
    {
        struct_fract->MinRe /= 2.3;
        struct_fract->MaxRe = fabs(struct_fract->MinRe);
        struct_fract->MinIm = -struct_fract->MaxRe;
	    struct_fract->MaxIm = struct_fract->MinIm + (struct_fract->MaxRe
- struct_fract->MinRe) * struct_fract->ImageHeight / struct_fract->ImageWidth;
        mlx_clear_window(struct_fract->mlx_ptr, struct_fract->win_ptr);
        mandelbrot_func(struct_fract);
    }
    mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 900, 900, 0xC5329F, ft_itoa(struct_fract->max_iter));
    return (0);
}