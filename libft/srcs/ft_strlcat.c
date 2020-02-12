/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:05:33 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/16 14:37:30 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (i < size)
	{
		if (i == size - 1 || *src == '\0')
		{
			dst[i] = '\0';
			break ;
		}
		else
		{
			dst[i] = *src;
			i++;
			src++;
		}
	}
	return (i + ft_strlen(src));
}
