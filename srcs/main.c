/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:13:47 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/30 11:35:32 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

static void		ft_out(void)
{
	ft_putendl("Usage: ./fractal 'mandelbrot' | 'julia' | 'celtic_mandelbar' | 'mandelbar'");
	exit(0);
}

static int		check_valid(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0 || ft_strcmp(str, "julia") == 0
	|| ft_strcmp(str, "celtic_mandelbar") == 0 || ft_strcmp(str, "mandelbar") == 0)
		return (0);
	ft_out();
	return (0);
}

static int		init(char *str, t_fract *struct_fract)
{
	struct_fract->mlx_ptr = mlx_init();
	struct_fract->win_ptr = mlx_new_window(struct_fract->mlx_ptr,
800, 800, str);
	struct_fract->img = mlx_new_image(struct_fract->mlx_ptr, 800, 800);
	struct_fract->img_ptr = mlx_get_data_addr(struct_fract->img,
&struct_fract->bpp, &struct_fract->sl, &struct_fract->endian);
	struct_fract->min_re = -2.0;
	struct_fract->min_im = -1.2;
	struct_fract->max_iter = 40;
	struct_fract->zoom = 300;
	struct_fract->image_width = 800;
	return (0);
}

static void		func_init(char *str, t_fract *struct_fract)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		mandelbrot_pthread(struct_fract);
		struct_fract->fractol = 1;
	}
	else if (ft_strcmp(str, "julia") == 0)
	{
		struct_fract->min_re = -1.4;
		struct_fract->min_im = -1.4;
		julia_pthread(struct_fract);
		mlx_hook(struct_fract->win_ptr, 6, 1L < 6, julia_motion, struct_fract);
		struct_fract->fractol = 2;
	}
	else if (ft_strcmp(str, "celtic_mandelbar") == 0)
	{
		celt_mandelbar_pthread(struct_fract);
		struct_fract->fractol = 3;
	}
	else if (ft_strcmp(str, "mandelbar") == 0)
	{
		celt_mandelbar_pthread(struct_fract);
		struct_fract->fractol = 4;
	}
}

int				main(int ac, char **av)
{
	t_fract		*struct_fract;
	char		*nb;
	t_color		clr;

	if (ac == 1)
		ft_out();
	else
	{
		clr.width = 127;
		clr.center = 128;
		check_valid(av[1]);
		struct_fract = (t_fract*)malloc(sizeof(t_fract));
		init(av[1], struct_fract);
		func_init(av[1], struct_fract);
		nb = ft_itoa(struct_fract->max_iter);
		draw(struct_fract);
		mlx_hook(struct_fract->win_ptr, 17, 0L, ft_close, struct_fract);
		mlx_mouse_hook(struct_fract->win_ptr, mouse_press, struct_fract);
		mlx_key_hook(struct_fract->win_ptr, key_press, struct_fract);
		mlx_loop(struct_fract->mlx_ptr);
	}
}