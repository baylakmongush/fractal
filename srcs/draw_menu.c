/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:40 by npetrell          #+#    #+#             */
/*   Updated: 2020/02/10 04:07:25 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mouse_press1(int mouse, int x, int y, t_fract *struct_fract)
{
	if (x >= 0 && y >= 0 && x <= 200 && y <= 200)
	{
		struct_fract->params.win_ptr = mlx_new_window(struct_fract->params.mlx_ptr,
SIZE, SIZE, "fractol");
	}
	return (0);
}

static void		draw_pix(int x1, int y1, int x2, int y2, int color, t_fract *struct_fract)
{
	int			delta_x_y[2];
	int			sign_x_y[2];
	int			error1_2[2];

	delta_x_y[0] = abs(x2 - x1);
	delta_x_y[1] = abs(y2 - y1);
	sign_x_y[0] = x1 < x2 ? 1 : -1;
	sign_x_y[1] = y1 < y2 ? 1 : -1;
	error1_2[0] = delta_x_y[0] - delta_x_y[1];
	mlx_pixel_put(struct_fract->params.mlx_ptr, struct_fract->params.win_ptr, x2, y2, color);
	while ((x1 - x2) || (y1 - y2))
	{
		mlx_pixel_put(struct_fract->params.mlx_ptr, struct_fract->params.win_ptr, x1, y1, color);
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
    int j;
	int	color;

	//while (j < 800)
	//{
		i = 0;
		while (i < 200)
		{
			draw_pix(j, i, j + 200, i, 0xccccff, struct_fract);
			i++;
		}
		mlx_string_put(struct_fract->params.mlx_ptr, struct_fract->params.win_ptr, 50, 100, 0x000000, "mandelbrot");
		while (i < 400)
		{
			draw_pix(j, i, j + 200, i, 0x33cccc, struct_fract);
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
	int			z1;
	int			z2;

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
}

int main()
{
    t_fract *struct_fract;

    struct_fract = (t_fract*)malloc(sizeof(t_fract));
    struct_fract->params.mlx_ptr = mlx_init();
	struct_fract->params.win_ptr = mlx_new_window(struct_fract->params.mlx_ptr,
801, 401, "menu");
    draw_menu(struct_fract);
	mlx_string_put(struct_fract->params.mlx_ptr, struct_fract->params.win_ptr, 50, 100, 0x000000, "mandelbrot");
	mlx_string_put(struct_fract->params.mlx_ptr, struct_fract->params.win_ptr, 15, 300, 0xffffff, "celtic mandelbrot");
	mlx_string_put(struct_fract->params.mlx_ptr, struct_fract->params.win_ptr, 240, 80, 0xffffff, "perpendicular");
	mlx_string_put(struct_fract->params.mlx_ptr, struct_fract->params.win_ptr, 255, 110, 0xffffff, "mandelbrot");
	mlx_string_put(struct_fract->params.mlx_ptr, struct_fract->params.win_ptr, 270, 300, 0xffffff, "julia");
	mlx_mouse_hook(struct_fract->params.win_ptr, mouse_press1, struct_fract);
    mlx_loop(struct_fract->params.mlx_ptr);
}