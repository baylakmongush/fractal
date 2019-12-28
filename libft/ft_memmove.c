/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:03:39 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/19 14:35:25 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				size;
	int				i;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	size = (int)len;
	i = 0;
	if (str1 == str2 || len == 0)
		return (str1);
	if (str2 < str1)
		while (size > 0)
		{
			size--;
			str1[i + size] = str2[i + size];
		}
	else
		while (i < size)
		{
			str1[i] = str2[i];
			i++;
		}
	return (str1);
}
