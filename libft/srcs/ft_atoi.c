/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:00:09 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/23 21:07:20 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long int	res;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * neg;
	if (res < -2147483648 || res > 2147483647)
		return (0);
	return (res);
}
