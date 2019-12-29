/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:37:30 by npetrell          #+#    #+#             */
/*   Updated: 2019/12/29 18:44:20 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define TRUE 1
# define FALSE 0
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

typedef struct	s_fract
{
	void		*mlx_ptr;
	void		*win_ptr;
	unsigned	ImageHeight;
	unsigned	ImageWidth;
}				t_fract;

int				key_press(int key, t_fract *struct_fract);
void			mandelbrot_func(t_fract *struct_fract);
int				mouse_press(int mouse, t_fract *struct_fract);

#endif
