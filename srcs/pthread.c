/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:19:53 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/30 15:49:24 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_error(void)
{
	ft_putendl("ERROR from pthread_create()");
	exit(-1);
}

void			fract_pthread_create(t_fract *struct_fract)
{
	t_fract		tmp[160];
	pthread_t	thread[160];
	int			i;
	int			rc;

	i = -1;
	while (++i < 160)
	{
		ft_memcpy((void*)&tmp[i], (void*)struct_fract, sizeof(t_fract));
		tmp[i].x = 5 * i;
		tmp[i].image_width = 5 * (i + 1);
		if (struct_fract->fractol == 1)
			rc = pthread_create(&thread[i], NULL, mandelbrot_func, &tmp[i]);
		else if (struct_fract->fractol == 2)
			rc = pthread_create(&thread[i], NULL, julia_func, &tmp[i]);
		else if (struct_fract->fractol == 3)
			rc = pthread_create(&thread[i], NULL, celt_mandelbar_func, &tmp[i]);
		else if (struct_fract->fractol == 4)
			rc = pthread_create(&thread[i], NULL, mandelbar_func, &tmp[i]);
		rc ? ft_error() : rc;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(struct_fract->params.mlx_ptr,
struct_fract->params.win_ptr, struct_fract->params.img, 0, 0);
}
