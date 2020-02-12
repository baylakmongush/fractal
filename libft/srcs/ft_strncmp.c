/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:25:51 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/20 18:40:47 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*s1 || *s2))
	{
		if (*((unsigned char*)s1) != *((unsigned char*)s2))
			return (*((unsigned char*)(s1)) - *((unsigned char*)s2));
		s1++;
		s2++;
		i++;
	}
	return (0);
}
