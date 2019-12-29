/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:13:47 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/29 19:01:24 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
    t_fract	*struct_fract;

    if (ac == 1)
    {
        write(1, "error\n", 6);
        exit (0);
    }
    if (ft_strcmp(av[1], "mandelbrot") == 0)
    {
        struct_fract = (t_fract*)malloc(sizeof(t_fract));
        struct_fract->mlx_ptr = mlx_init();
        struct_fract->ImageHeight = 1000;
        struct_fract->ImageWidth = 1000;
        struct_fract->win_ptr = mlx_new_window(struct_fract->mlx_ptr, 1000, 1000, av[1]);
        mandelbrot_func(struct_fract);
        mlx_key_hook(struct_fract->win_ptr, key_press, struct_fract);
        mlx_mouse_hook(struct_fract->win_ptr, mouse_press, struct_fract);
        mlx_loop(struct_fract->mlx_ptr);
    }
}