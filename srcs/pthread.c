/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:19:53 by npetrell          #+#    #+#             */
/*   Updated: 2020/01/30 18:04:03 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_error(void)
{
	ft_putendl("Error");
	exit(-1);
}

void			fract_pthread_create(t_fract *struct_fract)
{
	t_fract		tmp[160];
	pthread_t	thread[160];
	pthread_attr_t attr;
	int			i;
	int			rc;
	void		*status;

	i = -1;
	pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	while (++i < 160)
	{
		ft_memcpy((void*)&tmp[i], (void*)struct_fract, sizeof(t_fract));
		tmp[i].x = 5 * i;
		tmp[i].image_width = 5 * (i + 1);
		if (struct_fract->fractol == 1)
			rc = pthread_create(&thread[i], &attr, mandelbrot_func, &((void*)tmp)[i]);
		else if (struct_fract->fractol == 2)
			rc = pthread_create(&thread[i], &attr, julia_func, &((void*)tmp)[i]);
		else if (struct_fract->fractol == 3)
			rc = pthread_create(&thread[i], &attr, celt_mandelbar_func, &((void*)tmp)[i]);
		else if (struct_fract->fractol == 4)
			rc = pthread_create(&thread[i], &attr, mandelbar_func, &((void*)tmp)[i]);
	//	rc ? ft_error() : rc;
	}
	pthread_attr_destroy(&attr);
	while (i--)
	{
		rc = pthread_join(thread[i], &status);
	//	rc ? ft_error() : rc;
	}
	mlx_put_image_to_window(struct_fract->params.mlx_ptr,
struct_fract->params.win_ptr, struct_fract->params.img, 0, 0);
	pthread_exit(NULL);
}
