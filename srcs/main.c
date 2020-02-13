/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:13:47 by npetrell          #+#    #+#             */
/*   Updated: 2020/02/12 22:29:42 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		ft_out(void)
{
	ft_putendl("Usage: ./fractal 'mandelbrot' | 'julia' | \
'celtic_mandelbar' | 'mandelbar' | 'celtic_mandelrot' | \
'perpen_burning_ship' | 'burning_ship' | 'perpen_mandelbrot'");
	exit(0);
}

static int		check_valid(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0 || ft_strcmp(str, "julia") == 0
	|| ft_strcmp(str, "celtic_mandelbar") == 0 ||
ft_strcmp(str, "mandelbar") == 0 || ft_strcmp(str, \
"celtic_mandelbrot") == 0 || ft_strcmp(str, "perpen_burning_ship") == 0 || \
ft_strcmp(str, "burning_ship") == 0 || \
ft_strcmp(str, "perpen_mandelbrot") == 0)
		return (0);
	ft_out();
	return (0);
}

int				main(int ac, char **av)
{
	t_fract		*struct_fract;
	char		*nb;

	if (ac == 1)
		ft_out();
	else
	{
		check_valid(av[1]);
		if (!(struct_fract = (t_fract*)malloc(sizeof(t_fract))))
			return (0);
		init(av[1], struct_fract);
		func_init(av[1], struct_fract);
		nb = ft_itoa(struct_fract->max_iter);
		draw(struct_fract);
		free(nb);
		mlx_mouse_hook(struct_fract->params.win_ptr, mouse_press, struct_fract);
		mlx_hook(struct_fract->params.win_ptr, 2, 1 << 0,
		key_press, struct_fract);
		mlx_loop(struct_fract->params.mlx_ptr);
	}
}
