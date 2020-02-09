/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:19:53 by npetrell          #+#    #+#             */
/*   Updated: 2020/02/09 19:33:52 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_error(void)
{
	ft_putendl("Error");
	exit(-1);
}

void			create(int i, t_fract tmp[160], pthread_t thread[160],
t_fract *struct_fract)
{
	int			rc;

	rc = 0;
	if (struct_fract->fractol == 1)
		rc = pthread_create(&thread[i], NULL, mandelbrot_func, &tmp[i]);
	else if (struct_fract->fractol == 2)
		rc = pthread_create(&thread[i], NULL, julia_func, &tmp[i]);
	else if (struct_fract->fractol == 3)
		rc = pthread_create(&thread[i], NULL, celt_mandelbar_func, &tmp[i]);
	else if (struct_fract->fractol == 4)
		rc = pthread_create(&thread[i], NULL, mandelbar_func, &tmp[i]);
	else if (struct_fract->fractol == 5)
		rc = pthread_create(&thread[i], NULL, celt_mandelbrot_func, &tmp[i]);
	else if (struct_fract->fractol == 6)
		rc = pthread_create(&thread[i], NULL, perpen_burning_ship_func,
		&tmp[i]);
	else if (struct_fract->fractol == 7)
		rc = pthread_create(&thread[i], NULL, burning_ship_func, &tmp[i]);
	else if (struct_fract->fractol == 8)
		rc = pthread_create(&thread[i], NULL, perpen_mandelbrot_func, &tmp[i]);
	rc ? ft_error() : rc;
}

void			fract_pthread_create(t_fract *struct_fract)
{
	t_fract		tmp[160];
	pthread_t	thread[160];
	int			i;

	i = -1;
	while (++i < 160)
	{
		ft_memcpy((void*)&tmp[i], (void*)struct_fract, sizeof(t_fract));
		tmp[i].x = (SIZE / 160) * i;
		tmp[i].image_width = (SIZE / 160) * (i + 1);
		create(i, tmp, thread, struct_fract);
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(struct_fract->params.mlx_ptr,
	struct_fract->params.win_ptr, struct_fract->params.img, 0, 0);
}
