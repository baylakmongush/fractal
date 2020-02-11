/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:40 by npetrell          #+#    #+#             */
/*   Updated: 2020/02/10 04:07:25 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
 //gcc -framework OpenGL -framework Appkit -lmlx srcs/draw_menu.c srcs/color.c

/*  static void			put_pxl1(t_fract *data, int x, int y)
{
	if (data->x < SIZE && data->y < SIZE)
	{
		*(int*)(data->params.img) = 0xfff000;
	}
} */

int			mouse_press1(int mouse, int x, int y, t_fract *struct_fract)
{
	char		*nb;

	if (x >= 0 && y >= 0 && x <= 200 && y <= 200 && mouse == 1)
	{
		init("mandelbrot", struct_fract);
		func_init("mandelbrot", struct_fract);
	}
	if (x >= 0 && y >= 200 && x <= 200 && y <= 400)
	{
		init("celtic_mandelbrot", struct_fract);
		func_init("celtic_mandelbrot", struct_fract);
	}
 	if (x >= 200 && y >= 0 && x <= 400 && y <= 200)
	{
		init("perpen_mandelbrot", struct_fract);
		func_init("perpen_mandelbrot", struct_fract);
	}
	if (x >= 400 && y >= 0 && x <= 600 && y <= 200)
	{
		init("celtic_mandelbar", struct_fract);
		func_init("celtic_mandelbar", struct_fract);
	}
	if (x >= 600 && y >= 0 && x <= 800 && y <= 200)
	{
		init("perpen_burning_ship", struct_fract);
		func_init("perpen_burning_ship", struct_fract);
	}
	if (x >= 200 && y >= 200 && x <= 400 && y <= 400)
	{
		init("julia", struct_fract);
		func_init("julia", struct_fract);
	}
	if (x >= 400 && y >= 200 && x <= 600 && y <= 400)
	{
		init("mandelbar", struct_fract);
		func_init("mandelbar", struct_fract);
	}
	if (x >= 600 && y >= 200 && x <= 800 && y <= 600)
	{
		init("burning_ship", struct_fract);
		func_init("burning_ship", struct_fract);
	}
	nb = ft_itoa(struct_fract->max_iter);
	draw(struct_fract);
	/* mlx_hook(struct_fract->params.win_ptr, 17, 1 << 0,
	ft_close, struct_fract); */
	mlx_mouse_hook(struct_fract->params.win_ptr, mouse_press, struct_fract);
	mlx_key_hook(struct_fract->params.win_ptr, key_press, struct_fract);
	mlx_loop(struct_fract->params.mlx_ptr);
	return (0);
}

 void			draw_pix(int x1, int y1, int x2, int y2, int color, t_fract *struct_fract)
{
	int			delta_x_y[2];
	int			sign_x_y[2];
	int			error1_2[2];

	delta_x_y[0] = abs(x2 - x1);
	delta_x_y[1] = abs(y2 - y1);
	sign_x_y[0] = x1 < x2 ? 1 : -1;
	sign_x_y[1] = y1 < y2 ? 1 : -1;
	error1_2[0] = delta_x_y[0] - delta_x_y[1];
	//put_pxl1(struct_fract, x2, y2);
	mlx_pixel_put(struct_fract->params.mlx, struct_fract->params.win, x2, y2, color);
	while ((x1 - x2) || (y1 - y2))
	{
		//put_pxl1(struct_fract, x1, y1);
		mlx_pixel_put(struct_fract->params.mlx, struct_fract->params.win, x1, y1, color);
		error1_2[1] = error1_2[0] * 2;
		if (error1_2[1] > -delta_x_y[1])
		{
			error1_2[0] -= delta_x_y[1];
			x1 += sign_x_y[0];
		}
		if (error1_2[1] < delta_x_y[0])
		{
			error1_2[0] += delta_x_y[0];
			y1 += sign_x_y[1];
		}
	}
}

static void     draw_square(t_fract *struct_fract)
{
    int i;

	i = 0;
	while (i < 200)
	{
		draw_pix(0, i, 200, i, 0xffb6c1, struct_fract);
		i++;
	}
	while (i < 400)
	{
		draw_pix(0, i, 200, i, 0xffddf4, struct_fract);
		i++;
	}
	i = 0;
	while (i < 200)
	{
		draw_pix(200, i, 400, i, 0xebd3b7, struct_fract);
		i++;
	}
	while (i < 400)
	{
		draw_pix(200, i, 400, i, 0xcbffc0, struct_fract);
		i++;
	}
	i = 0;
	while (i < 200)
	{
		draw_pix(400, i, 600, i, 0xc0fff4, struct_fract);
		i++;
	}
	while (i < 400)
	{
		draw_pix(400, i, 600, i, 0xff99cc, struct_fract);
		i++;
	}
	i = 0;
	while (i < 200)
	{
		draw_pix(600, i, 800, i, 0xffffcc, struct_fract);
		i++;
	}
	while (i < 400)
	{
		draw_pix(600, i, 800, i, 0xccff99, struct_fract);
		i++;
	}
} 

void			draw_menu(t_fract *struct_fract)
{
	int			i;
	int			j;

	draw_square(struct_fract);
	j = 0;
	while (j < 3)
	{
		i = 0;
		while (i < 5)
		{
			if (i < 4)
				draw_pix(i * 200, j * 200,
				(i + 1) * 200, j * 200, 0xfff000, struct_fract);
			if (j < 2)
				draw_pix(i * 200, j * 200,
				i * 200, (j + 1) * 200, 0xfff000, struct_fract);
			i++;
		}
		j++;
	}
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 50, 100, 0xfff000, "mandelbrot");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 15, 300, 0xfff000, "celtic mandelbrot");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 240, 80, 0xfff000, "perpendicular");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 255, 110, 0xfff000, "mandelbrot");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 270, 301, 0xfff000, "julia");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 460, 110, 0xfff000, "mandelbar");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 475, 80, 0xfff000, "celtic");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 460, 300, 0xfff000, "mandelbar");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 645, 110, 0xfff000, "burning ship");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 640, 80, 0xfff000, "perpendicular");
	mlx_string_put(struct_fract->params.mlx, struct_fract->params.win, 640, 301, 0xfff000, "burning ship");
}
