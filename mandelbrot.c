/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:43:44 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/15 19:56:58 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define THREAD_WIDTH 5

//gcc -I minilibx_macos minilibx_macos/libmlx.a -framework OpenGL -framework Appkit main.c mandelbrot.c key_mouse_press.c  libft/libft.a

void	put_pxl_to_img(t_fract *data, int x, int y, int color)
{
	if (data->x < SIZE && data->y < SIZE)
	{
		color = mlx_get_color_value(data->mlx_ptr, color);
		ft_memcpy(data->img_ptr + 4 * SIZE * y + x * 4, &color, sizeof(int));
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
	double		Z_im2;

    struct_fract = (t_fract*)data;
    while (struct_fract->y < struct_fract->ImageHeight)
    {
		struct_fract->x = 0;
        while (struct_fract->x < SIZE)
        {
			c_im = struct_fract->y / struct_fract->zoom + struct_fract->MinIm;
            c_re = struct_fract->x / struct_fract->zoom + struct_fract->MinRe;
			Z_re = c_re; 
			Z_im = c_im; 
			iter = 0;
            while (iter < struct_fract->max_iter && ((pow(Z_re, 2) + pow(Z_im, 2)) <= 4))
            {
				Z_im2 = pow(Z_im, 2);
                Z_im = 2 * Z_re * Z_im + c_im;
                Z_re = pow(Z_re, 2) - Z_im2 + c_re;
                iter++;
            }
            (iter == struct_fract->max_iter) ? put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, 0x000000)
            : put_pxl_to_img(struct_fract, struct_fract->x, struct_fract->y, struct_fract->color * iter);
			struct_fract->x++;;
        }
		struct_fract->y++;
    }
    return (NULL);
}

void	mandelbrot_pthread(t_fract *struct_fract)
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
		pthread_create(&t[i], NULL, mandelbrot_func, &tab[i]);
		i++;
	}
    while (i--)
		pthread_join(t[i], NULL);
    mlx_put_image_to_window(struct_fract->mlx_ptr, struct_fract->win_ptr, struct_fract->img, 0, 0);
}
