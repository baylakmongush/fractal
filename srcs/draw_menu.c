/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:40 by npetrell          #+#    #+#             */
/*   Updated: 2020/02/09 23:12:27 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

//	while (j < 800)
 //   {
		i = 0;
		while (i < 200)
		{
			draw_pix(0, i, 200, i, 0xffc0cb, struct_fract);
			i++;
		}
		while (i < 400)
		{
			draw_pix(0, i, 200, i, 0xc0cbff, struct_fract);
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
			draw_pix(400, i, 600, i, 0xc0fff4, struct_fract);
			i++;
		}
//		j++;
//	}
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
802, 402, "menu");
    draw_menu(struct_fract);
    mlx_loop(struct_fract->params.mlx_ptr);
}