/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:35:56 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/18 18:45:39 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*sub;
	size_t	i;

	i = 0;
	str = (char*)s;
	if (s == 0)
		return (NULL);
	if (!(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		sub[i] = str[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
