/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:13:47 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/28 22:36:14 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main()
{
    t_fract	*struct_fract;

    struct_fract = (t_fract*)malloc(sizeof(t_fract));
    struct_fract->mlx_ptr = mlx_init();
    struct_fract->ImageHeight = 600;
    struct_fract->ImageWidth = 600;
    struct_fract->win_ptr = mlx_new_window(struct_fract->mlx_ptr, struct_fract->ImageWidth, struct_fract->ImageHeight, "FRACTOL");
    mandelbrot_func(struct_fract);
    mlx_key_hook(struct_fract->win_ptr, key_press, struct_fract);
    mlx_loop(struct_fract->mlx_ptr);
}