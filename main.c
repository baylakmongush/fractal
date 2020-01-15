/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:13:47 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/15 21:08:00 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_motion(int mouse, int x, int y, t_fract *fractol)
{
    if (mouse == 1)
    {
        fractol->k_re = 4 * ((double)x / SIZE - 0.5);
        fractol->k_im = 4 * ((double)(SIZE - y) / SIZE - 0.5);
        julia_pthread(fractol);
    }
    return (0);
}

int         init(t_fract *struct_fract)
{
    struct_fract->MinRe = -2.0;
    struct_fract->MinIm = -1.2;
    struct_fract->max_iter = 40;
    struct_fract->zoom = 300;
    struct_fract->color = 265;
    struct_fract->ImageWidth = 800;
    return (0);
}

int			main(int ac, char **av)
{
    t_fract	*struct_fract;

    if (ac == 1)
    {
        ft_putendl("Usage: ./fractal 'mandelbrot' | 'julia'");
        exit (0);
    }
    if (ft_strcmp(av[1], "mandelbrot") == 0)
    {
        struct_fract = (t_fract*)malloc(sizeof(t_fract));
        struct_fract->mlx_ptr = mlx_init();
        struct_fract->win_ptr = mlx_new_window(struct_fract->mlx_ptr,  struct_fract->ImageWidth,  struct_fract->ImageWidth, av[1]);
        struct_fract->img = mlx_new_image(struct_fract->mlx_ptr,  struct_fract->ImageWidth,  struct_fract->ImageWidth);
	    struct_fract->img_ptr = mlx_get_data_addr(struct_fract->img, &struct_fract->bpp, &struct_fract->sl, &struct_fract->endian);
        init(struct_fract);
        mandelbrot_pthread(struct_fract);
        mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 5, 10, 0x3a8888, "iteration: ");
        mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 110, 10, 0xC5329F, ft_itoa(struct_fract->max_iter));
        mlx_mouse_hook(struct_fract->win_ptr, mouse_press, struct_fract);
        mlx_key_hook(struct_fract->win_ptr, key_press, struct_fract);
        mlx_loop(struct_fract->mlx_ptr);
    }
    if (ft_strcmp(av[1], "julia") == 0)
    {
        struct_fract = (t_fract*)malloc(sizeof(t_fract));
        struct_fract->mlx_ptr = mlx_init();
        struct_fract->win_ptr = mlx_new_window(struct_fract->mlx_ptr, 800,  800, av[1]);
        struct_fract->img = mlx_new_image(struct_fract->mlx_ptr, 800, 800);
	    struct_fract->img_ptr = mlx_get_data_addr(struct_fract->img, &struct_fract->bpp, &struct_fract->sl, &struct_fract->endian);
        init(struct_fract);
        julia_pthread(struct_fract);
        mlx_mouse_hook(struct_fract->win_ptr, julia_motion, struct_fract);
        mlx_key_hook(struct_fract->win_ptr, key_press, struct_fract);
        mlx_loop(struct_fract->mlx_ptr);
    }
}
