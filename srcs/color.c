/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:19:59 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/30 14:56:51 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		get_color(t_color clr)
{
	return ((clr.r << 16) | (clr.g << 8) | clr.b);
}

void			put_pxl(t_fract *data, int x, int y)
{
	if (data->x < SIZE && data->y < SIZE)
	{
		data->clr.r = sin(0.25 * data->iter + 0 + data->clr.step) *
		data->clr.width + data->clr.center;
		data->clr.g = sin(0.25 * data->iter + 2 + data->clr.step) *
		data->clr.width + data->clr.center;
		data->clr.b = sin(0.25 * data->iter + 4 + data->clr.step) *
		data->clr.width + data->clr.center;
		*(int*)(data->params.img_ptr + (x + y * SIZE) *
		data->params.bpp / 8) = get_color(data->clr);
		if (data->iter == data->max_iter)
			*(int*)(data->params.img_ptr + (x + y * SIZE) *
			data->params.bpp / 8) = 0xb2b2ff;
	}
}
