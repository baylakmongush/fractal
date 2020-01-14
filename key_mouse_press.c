/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:40:55 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/14 17:56:38 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	key_press(int key, t_fract *struct_fract)
{
    if (key == 53)
        exit (0);
    mlx_clear_window(struct_fract->mlx_ptr, struct_fract->win_ptr);
    mandelbrot_pthread(struct_fract);
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
    mandelbrot_pthread(struct_fract);
    mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 5, 10, 0x3a8888, "iteration: ");
    mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 110, 10, 0xC5329F, ft_itoa(struct_fract->max_iter));
    return (0);
}