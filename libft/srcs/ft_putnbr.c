/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:04:21 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/12 15:29:56 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft.h"

void	ft_putnbr(int n)
{
	int	negative;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n == 0)
		write(1, "0", 1);
	else if (n < 0)
	{
		write(1, "-", 1);
		negative = -1;
		n = n * negative;
		ft_putnbr(n);
	}
	else if (n > 9 && n <= 2147483647)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
