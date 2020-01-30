/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:19:59 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/30 11:36:15 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

static int		get_color(t_color clr)
{
	return ((clr.r << 16) | (clr.g << 8) | clr.b);
}

void			put_pxl(t_fract *data, int x, int y)
{
	t_color		clr;

	printf("%d", clr.width);
	if (data->x < SIZE && data->y < SIZE)
	{
		clr.r = sin(0.25 * data->iter + 0) * clr.width + clr.center;
		clr.g = sin(0.25 * data->iter + 2) * clr.width + clr.center;
		clr.b = sin(0.25 * data->iter + 4) * clr.width + clr.center;
		*(int*)(data->img_ptr + (x + y * SIZE) * data->bpp / 8) =
get_color(clr);
		if (data->iter == data->max_iter)
			*(int*)(data->img_ptr + (x + y * SIZE) * data->bpp / 8) = 0x000000;
	}
}
