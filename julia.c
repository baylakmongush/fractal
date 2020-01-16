/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:27:06 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/16 17:11:57 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void			*julia_func(void *data)
{
    t_fract     *struct_fract;
	double      iter;
	double		Z_re;
	double		Z_im;
	double		Z_im2;
    
    struct_fract = (t_fract*)data;
    struct_fract->MinRe = -1.4;
    struct_fract->MinIm = -1.4;
    while (struct_fract->y < struct_fract->ImageHeight)
    {
		struct_fract->x = 0;
        while (struct_fract->x < struct_fract->ImageWidth)
        {
			Z_re =  struct_fract->x / struct_fract->zoom + struct_fract->MinRe; 
			Z_im =  struct_fract->y / struct_fract->zoom + struct_fract->MinIm;
			iter = 0;
            while (iter < struct_fract->max_iter && ((pow(Z_re, 2) + pow(Z_im, 2)) < 4))
            {
				Z_im2 = pow(Z_im, 2);
                Z_im = 2 * Z_re * Z_im + struct_fract->k_im;
                Z_re = pow(Z_re, 2) - Z_im2 + struct_fract->k_re;
                iter++;
            }
            (iter == struct_fract->max_iter) ? put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, 0x000000)
            : put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, struct_fract->color * iter);
			struct_fract->x++;
        }
		struct_fract->y++;
    }
    return (NULL);
}

void	julia_pthread(t_fract *struct_fract)
{
	t_fract     tab[160];
	pthread_t	t[160];
	int			i;

	i = 0;
	while (i < 160)
	{
		ft_memcpy((void*)&tab[i], (void*)struct_fract, sizeof(t_fract));
		tab[i].y = 5 * i;
		tab[i].ImageHeight = 5 * (i + 1);
		pthread_create(&t[i], NULL, julia_func, &tab[i]);
		i++;
	}
    while (i--)
		pthread_join(t[i], NULL);
    mlx_put_image_to_window(struct_fract->mlx_ptr, struct_fract->win_ptr, struct_fract->img, 0, 0);
}
