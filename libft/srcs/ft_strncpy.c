/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:54:23 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/10 12:12:42 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	int			i;

	i = 0;
	while (i < (int)len && ((char*)src)[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
