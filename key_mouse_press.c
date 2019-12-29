/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:40:55 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/29 19:00:50 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	key_press(int key, t_fract *struct_fract)
{
    if (key == 53)
        exit (0);
    if (key == 18)
    {
        struct_fract->ImageHeight += 100;
        struct_fract->ImageWidth += 100;
    }
    mlx_clear_window(struct_fract->mlx_ptr, struct_fract->win_ptr);
    mandelbrot_func(struct_fract);
    return (0);
}

int	mouse_press(int mouse, t_fract *struct_fract)
{
    if (mouse == 4 && struct_fract->ImageHeight)
    {
        struct_fract->ImageHeight += 0.5;
        struct_fract->ImageWidth += 0.5;
    }
    if (mouse == 5)
    {
        struct_fract->ImageWidth -= 0.5;
        struct_fract->ImageHeight -= 0.5;
    }
    mlx_clear_window(struct_fract->mlx_ptr, struct_fract->win_ptr);
    mandelbrot_func(struct_fract);
    return (0);
}