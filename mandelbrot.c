/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:43:44 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/13 04:21:35 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define THREAD_WIDTH 9

//gcc -I minilibx_macos minilibx_macos/libmlx.a -framework OpenGL -framework Appkit main.c mandelbrot.c key_mouse_press.c  libft/libft.a

void	put_pxl_to_img(t_fract *data, int x, int y, int color)
{
	if (data->x < 600 && data->y < 600)
	{
		color = mlx_get_color_value(data->mlx_ptr, color);
		ft_memcpy(data->img_ptr + 4 * 600 * y + x * 4,
				&color, sizeof(int));
	}
}

void			*mandelbrot_func(void *data)
{
    t_fract     *struct_fract;
	double      iter;
	double		c_re;
	double		c_im;
	double		Z_re;
	double		Z_im;
	double 		Z_re2;
	double		Z_im2;

    struct_fract = (t_fract*)data;
    while (struct_fract->y < struct_fract->ImageHeight)
    {
		struct_fract->x = 0;
        while (struct_fract->x < 600)
        {
            c_im = struct_fract->y / struct_fract->zoom + struct_fract->MinIm;
            c_re = struct_fract->x / struct_fract->zoom + struct_fract->MinRe;
			Z_re = c_re; // инициализация действ части
			Z_im = c_im; // инициализация мнимой части 
			iter = 0;
            Z_re2 = 0;
            Z_im2 = 0;
            while (iter < struct_fract->max_iter && Z_re2 + Z_im2 < 4)
            {
                Z_re2 = pow(Z_re, 2); // квадрат действительной части 
				Z_im2 = pow(Z_im, 2); // квадрат мнимой части
                Z_im = 2 * Z_re * Z_im + c_im; // основная формула Мандельброта
                Z_re = Z_re2 - Z_im2 + c_re;
                iter++;
            }
            (iter == struct_fract->max_iter) ? put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, 0x000000)
            : put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, struct_fract->color * iter);
            struct_fract->x++;
        }
        struct_fract->y++;
    }
    return (data);
}

void	mandelbrot_pthread(t_fract *data)
{
	t_fract     tab[120];
	pthread_t	t[120];
	int			i;

	i = 0;
	while (i < 120)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_fract));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].ImageHeight = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot_func, &tab[i]);
		i++;
	}
    while (i--)
		pthread_join(t[i], NULL);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
