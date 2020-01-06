/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:13:47 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/06 20:40:47 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int         init(t_fract *struct_fract)
{
    struct_fract->ImageHeight = 800;
    struct_fract->ImageWidth = 800;
    struct_fract->MinRe = -4.0;
    struct_fract->MaxRe = 0.6;
    struct_fract->MinIm = -0.6;
    struct_fract->MaxIm = struct_fract->MinIm + (struct_fract->MaxRe
    - struct_fract->MinRe) * struct_fract->ImageHeight / struct_fract->ImageWidth;
    struct_fract->max_iter = 20;
    return (0);
}

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
        struct_fract->win_ptr = mlx_new_window(struct_fract->mlx_ptr, 1000, 1000, av[1]);
        init(struct_fract);
        mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 900, 900, 0xC5329F, ft_itoa(struct_fract->max_iter));
        mandelbrot_func(struct_fract);
        mlx_key_hook(struct_fract->win_ptr, key_press, struct_fract);
        mlx_mouse_hook(struct_fract->win_ptr, mouse_press, struct_fract);
        mlx_loop(struct_fract->mlx_ptr);
    }
    else if (ft_strcmp(av[1], "julia") == 0)
    {
        struct_fract = (t_fract*)malloc(sizeof(t_fract));
        struct_fract->mlx_ptr = mlx_init();
        struct_fract->win_ptr = mlx_new_window(struct_fract->mlx_ptr, 1000, 1000, av[1]);
        init(struct_fract);
        mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 900, 900, 0xC5329F, ft_itoa(struct_fract->max_iter));
        julia_func(struct_fract);
        mlx_loop(struct_fract->mlx_ptr);
    }
}