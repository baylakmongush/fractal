/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:05:22 by npetrell          #+#    #+#             */
/*   Updated: 2020/02/12 22:14:49 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		first(t_fract *struct_fract)
{
	int		i;
	t_coord	xyz;

	i = -1;
	while (++i < 200)
	{
		xyz.x1 = 0;
		xyz.y1 = i;
		xyz.x2 = 200;
		xyz.y2 = i;
		struct_fract->color = 0xffb6c1;
		draw_pix(xyz, struct_fract);
	}
	while (++i < 400)
	{
		xyz.x1 = 0;
		xyz.y1 = i;
		xyz.x2 = 200;
		xyz.y2 = i;
		struct_fract->color = 0xffddf4;
		draw_pix(xyz, struct_fract);
	}
}

void		second(t_fract *struct_fract)
{
	int		i;
	t_coord	xyz;

	i = -1;
	while (++i < 200)
	{
		xyz.x1 = 200;
		xyz.y1 = i;
		xyz.x2 = 400;
		xyz.y2 = i;
		struct_fract->color = 0xebd3b7;
		draw_pix(xyz, struct_fract);
	}
	while (++i < 400)
	{
		xyz.x1 = 200;
		xyz.y1 = i;
		xyz.x2 = 400;
		xyz.y2 = i;
		struct_fract->color = 0xcbffc0;
		draw_pix(xyz, struct_fract);
	}
}

void		third(t_fract *struct_fract)
{
	int		i;
	t_coord	xyz;

	i = -1;
	while (++i < 200)
	{
		xyz.x1 = 400;
		xyz.y1 = i;
		xyz.x2 = 600;
		xyz.y2 = i;
		struct_fract->color = 0xc0fff4;
		draw_pix(xyz, struct_fract);
	}
	while (++i < 400)
	{
		xyz.x1 = 400;
		xyz.y1 = i;
		xyz.x2 = 600;
		xyz.y2 = i;
		struct_fract->color = 0xff99cc;
		draw_pix(xyz, struct_fract);
	}
}

void		fourth(t_fract *struct_fract)
{
	int		i;
	t_coord	xyz;

	i = -1;
	while (++i < 200)
	{
		xyz.x1 = 600;
		xyz.y1 = i;
		xyz.x2 = 800;
		xyz.y2 = i;
		struct_fract->color = 0xffffcc;
		draw_pix(xyz, struct_fract);
	}
	while (++i < 400)
	{
		xyz.x1 = 600;
		xyz.y1 = i;
		xyz.x2 = 800;
		xyz.y2 = i;
		struct_fract->color = 0xccff99;
		draw_pix(xyz, struct_fract);
	}
}
