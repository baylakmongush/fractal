/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:29:21 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/31 19:33:13 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				init(char *str, t_fract *struct_fract)
{
	struct_fract->params.mlx_ptr = mlx_init();
	struct_fract->params.win_ptr = mlx_new_window(struct_fract->params.mlx_ptr,
800, 800, str);
	struct_fract->params.img = mlx_new_image(struct_fract->params.mlx_ptr,
800, 800);
	struct_fract->params.img_ptr = mlx_get_data_addr(struct_fract->params.img,
	&struct_fract->params.bpp, &struct_fract->params.sl,
	&struct_fract->params.endian);
	struct_fract->min_re = -2.0;
	struct_fract->min_im = -1.2;
	struct_fract->max_iter = 40;
	struct_fract->zoom = 300;
	struct_fract->image_width = 800;
	struct_fract->clr.width = -35;
	struct_fract->clr.center = 200;
	struct_fract->clr.step = 0.01;
	return (0);
}

static void		func_init2(char *str, t_fract *struct_fract)
{
	if (ft_strcmp(str, "mandelbar") == 0)
	{
		fract_pthread_create(struct_fract);
		struct_fract->fractol = 4;
	}
	else if (ft_strcmp(str, "celtic_mandelbrot") == 0)
	{
		fract_pthread_create(struct_fract);
		struct_fract->fractol = 5;
	}
}

void			func_init(char *str, t_fract *struct_fract)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		fract_pthread_create(struct_fract);
		struct_fract->fractol = 1;
	}
	else if (ft_strcmp(str, "julia") == 0)
	{
		struct_fract->min_re = -1.4;
		struct_fract->min_im = -1.4;
		fract_pthread_create(struct_fract);
		mlx_hook(struct_fract->params.win_ptr, 6, 1L << 12,
julia_motion, struct_fract);
		struct_fract->fractol = 2;
	}
	else if (ft_strcmp(str, "celtic_mandelbar") == 0)
	{
		fract_pthread_create(struct_fract);
		struct_fract->fractol = 3;
	}
	func_init2(str, struct_fract);
}
