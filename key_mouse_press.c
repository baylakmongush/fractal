/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:40:55 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/23 16:55:27 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw(t_fract *struct_fract)
{
	char	*nb;

	if (struct_fract->fractol == 1)
		mandelbrot_pthread(struct_fract);
	if (struct_fract->fractol == 2)
		julia_pthread(struct_fract);
	if (struct_fract->fractol == 3)
		celc_mandelbar_pthread(struct_fract);
	nb = ft_itoa(struct_fract->max_iter);
	mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 5,
10, 0x3a8888, "iteration: ");
	mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 110, 10,
0xC5329F, nb);
	free(nb);
	mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 5,
	30, 0x3a8888, "colors change key: 1, 2, 3");
	mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 5,
50, 0x3a8888, "zoom up/down: mouse's scroll wheel");
	mlx_string_put(struct_fract->mlx_ptr, struct_fract->win_ptr, 5,
70, 0x3a8888, "iteration up/down key: +, -");
}

int			key_press(int key, t_fract *struct_fract)
{
	if (key == 53)
		exit(0);
	if (key == 18)
		struct_fract->color = 265;
	if (key == 19)
		struct_fract->color = 2065;
	if (key == 20)
		struct_fract->color = 2605;
	if (key == 27)
		struct_fract->max_iter--;
	if (key == 24)
		struct_fract->max_iter++;
	mlx_clear_window(struct_fract->mlx_ptr, struct_fract->win_ptr);
	draw(struct_fract);
	return (0);
}

int			mouse_press(int mouse, int x, int y, t_fract *struct_fract)
{
	if (mouse == 4)
	{
		struct_fract->min_re = (x / struct_fract->zoom +
struct_fract->min_re) - (x / (struct_fract->zoom * 1.2));
		struct_fract->min_im = (y / struct_fract->zoom +
struct_fract->min_im) - (y / (struct_fract->zoom * 1.2));
		struct_fract->zoom *= 1.2;
	}
	if (mouse == 5)
	{
		struct_fract->min_re = (x / struct_fract->zoom +
struct_fract->min_re) - (x / (struct_fract->zoom / 1.2));
		struct_fract->min_im = (y / struct_fract->zoom +
struct_fract->min_im) - (y / (struct_fract->zoom / 1.2));
		struct_fract->zoom /= 1.2;
	}
	if (mouse == 1)
	{
		struct_fract->k_re = 4 * ((double)x / SIZE - 0.5);
		struct_fract->k_im = 4 * ((double)(SIZE - y) / SIZE - 0.5);
	}
	draw(struct_fract);
	return (0);
}

int			julia_motion(int x, int y, t_fract *fractol)
{
	if (x > 0 && x < fractol->image_width && y > 0 && y < fractol->image_width)
	{
		fractol->k_re = 4 * ((double)x / SIZE - 0.5);
		fractol->k_im = 4 * ((double)(SIZE - y) / SIZE - 0.5);
		julia_pthread(fractol);
	}
	return (0);
}
