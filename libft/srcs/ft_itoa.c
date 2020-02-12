/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:36:01 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/18 22:21:23 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../libft.h"

static int				ft_size(int n)
{
	int					i;
	int					nb;

	i = 0;
	nb = n;
	if (n < 0)
		n = n * (-1);
	while (n > 0)
	{
		if (nb < 0 && (nb / 10) == 0)
			i++;
		n = n / 10;
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char				*ft_result(char *str, int nb)
{
	if (nb < 0)
		str[0] = '-';
	return (str);
}

static char				*ft_null(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char					*ft_itoa(int n)
{
	int					nb;
	int					len;
	char				*str;
	char				*min;

	nb = n;
	if (nb == 0)
		return (ft_null(ft_strnew(1)));
	if (nb == -2147483648)
	{
		min = ft_strnew(12);
		return (ft_strcpy(min, "-2147483648"));
	}
	len = ft_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
		n = n * (-1);
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (ft_result(str, nb));
}
