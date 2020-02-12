/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:17:15 by npetrell          #+#    #+#             */
/*   Updated: 2020/02/12 22:13:04 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			draw_pix(t_coord xyz, t_fract *s)
{
	int			delta_x_y[2];
	int			sign_x_y[2];
	int			error1_2[2];

	delta_x_y[0] = abs(xyz.x2 - xyz.x1);
	delta_x_y[1] = abs(xyz.y2 - xyz.y1);
	sign_x_y[0] = xyz.x1 < xyz.x2 ? 1 : -1;
	sign_x_y[1] = xyz.y1 < xyz.y2 ? 1 : -1;
	error1_2[0] = delta_x_y[0] - delta_x_y[1];
	mlx_pixel_put(s->params.mlx, s->params.win, xyz.x2, xyz.y2, s->color);
	while ((xyz.x1 - xyz.x2) || (xyz.y1 - xyz.y2))
	{
		mlx_pixel_put(s->params.mlx, s->params.win, xyz.x1, xyz.y1, s->color);
		error1_2[1] = error1_2[0] * 2;
		if (error1_2[1] > -delta_x_y[1])
		{
			error1_2[0] -= delta_x_y[1];
			xyz.x1 += sign_x_y[0];
		}
		if (error1_2[1] < delta_x_y[0])
		{
			error1_2[0] += delta_x_y[0];
			xyz.y1 += sign_x_y[1];
		}
	}
}

void			draw_square(t_fract *struct_fract)
{
	first(struct_fract);
	second(struct_fract);
	third(struct_fract);
	fourth(struct_fract);
}

void			init_main(t_fract *struct_fract)
{
	t_coord		xyz;
	int			i;
	int			j;

	j = -1;
	i = 0;
	struct_fract->params.mlx = mlx_init();
	struct_fract->params.win = mlx_new_window(struct_fract->params.mlx,
801, 401, "main");
	xyz.x1 = 1;
	draw_menu(i, j, struct_fract, xyz);
	mlx_hook(struct_fract->params.win, 17, 1 << 0,
	ft_close, struct_fract);
	mlx_mouse_hook(struct_fract->params.win, mouse_press1, struct_fract);
	mlx_loop(struct_fract->params.mlx);
}
