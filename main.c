/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:13:47 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/13 02:51:09 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int         init(t_fract *struct_fract)
{
    struct_fract->ImageHeight = 600;
    struct_fract->ImageWidth = 600;
    struct_fract->MinRe = -2.0;
    struct_fract->MinIm = -2.0;
    struct_fract->max_iter = 40;
    struct_fract->zoom = 300;
    struct_fract->color = 265;
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
        struct_fract->win_ptr = mlx_new_window(struct_fract->mlx_ptr, 600, 600, av[1]);
        struct_fract->img = mlx_new_image(struct_fract->mlx_ptr, 600, 600);
	    struct_fract->img_ptr = mlx_get_data_addr(struct_fract->img, &struct_fract->bpp, &struct_fract->sl, &struct_fract->endian);
        init(struct_fract);
    //    mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 500, 500, 0xC5329F, ft_itoa(struct_fract->max_iter));
        mandelbrot_pthread(struct_fract);
     //   mlx_key_hook(struct_fract->win_ptr, key_press, struct_fract);
        mlx_mouse_hook(struct_fract->win_ptr, mouse_press, struct_fract);
        mlx_loop(struct_fract->mlx_ptr);
    }
  /*  else if (ft_strcmp(av[1], "julia") == 0)
    {
        struct_fract = (t_fract*)malloc(sizeof(t_fract));
        struct_fract->mlx_ptr = mlx_init();
        struct_fract->win_ptr = mlx_new_window(struct_fract->mlx_ptr, 1000, 1000, av[1]);
        init(struct_fract);
        mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 900, 900, 0xC5329F, ft_itoa(struct_fract->max_iter));
        julia_func(struct_fract);
        mlx_loop(struct_fract->mlx_ptr);
    }*/
}
