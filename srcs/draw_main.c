/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:40 by npetrell          #+#    #+#             */
/*   Updated: 2020/02/12 22:28:23 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		name_main1(int x, int y, t_fract *struct_fract, int mouse)
{
	if (x >= 0 && y >= 0 && x <= 200 && y <= 200 && mouse == 1)
	{
		init("mandelbrot", struct_fract);
		func_init("mandelbrot", struct_fract);
	}
	if (x >= 0 && y >= 200 && x <= 200 && y <= 400 && mouse == 1)
	{
		init("celtic_mandelbrot", struct_fract);
		func_init("celtic_mandelbrot", struct_fract);
	}
	if (x >= 200 && y >= 0 && x <= 400 && y <= 200 && mouse == 1)
	{
		init("perpen_mandelbrot", struct_fract);
		func_init("perpen_mandelbrot", struct_fract);
	}
	if (x >= 400 && y >= 0 && x <= 600 && y <= 200 && mouse == 1)
	{
		init("celtic_mandelbar", struct_fract);
		func_init("celtic_mandelbar", struct_fract);
	}
}

static void		name_main2(int x, int y, t_fract *struct_fract, int mouse)
{
	if (x >= 600 && y >= 0 && x <= 800 && y <= 200 && mouse == 1)
	{
		init("perpen_burning_ship", struct_fract);
		func_init("perpen_burning_ship", struct_fract);
	}
	if (x >= 200 && y >= 200 && x <= 400 && y <= 400 && mouse == 1)
	{
		init("julia", struct_fract);
		func_init("julia", struct_fract);
	}
	if (x >= 400 && y >= 200 && x <= 600 && y <= 400 && mouse == 1)
	{
		init("mandelbar", struct_fract);
		func_init("mandelbar", struct_fract);
	}
	if (x >= 600 && y >= 200 && x <= 800 && y <= 600 && mouse == 1)
	{
		init("burning_ship", struct_fract);
		func_init("burning_ship", struct_fract);
	}
}

void			name(t_fract *struct_fract)
{
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	50, 100, 0xfff000, "mandelbrot");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	15, 300, 0xfff000, "celtic mandelbrot");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	240, 80, 0xfff000, "perpendicular");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	255, 110, 0xfff000, "mandelbrot");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	270, 301, 0xfff000, "julia");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	460, 110, 0xfff000, "mandelbar");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	475, 80, 0xfff000, "celtic");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	460, 300, 0xfff000, "mandelbar");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	645, 110, 0xfff000, "burning ship");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	640, 80, 0xfff000, "perpendicular");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win,
	640, 301, 0xfff000, "burning ship");
}

int				mouse_press1(int mouse, int x, int y, t_fract *struct_fract)
{
	name_main1(x, y, struct_fract, mouse);
	name_main2(x, y, struct_fract, mouse);
	draw(struct_fract);
	mlx_hook(struct_fract->params.win_ptr, 17, 1 << 0,
	ft_close, struct_fract);
	mlx_mouse_hook(struct_fract->params.win_ptr, mouse_press, struct_fract);
	mlx_key_hook(struct_fract->params.win_ptr, key_press, struct_fract);
	mlx_loop(struct_fract->params.mlx_ptr);
	return (0);
}

void			draw_menu(int i, int j, t_fract *struct_fract, t_coord xyz)
{
	draw_square(struct_fract);
	while (++j < 3)
	{
		i = -1;
		while (++i < 5)
		{
			struct_fract->color = 0xfff000;
			xyz.x1 = i * 200;
			xyz.y1 = j * 200;
			if (i < 4)
			{
				xyz.x2 = (i + 1) * 200;
				xyz.y2 = j * 200;
				draw_pix(xyz, struct_fract);
			}
			if (j < 2)
			{
				xyz.x2 = i * 200;
				xyz.y2 = (j + 1) * 200;
				draw_pix(xyz, struct_fract);
			}
		}
	}
	name(struct_fract);
}
