/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:00:20 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/21 21:12:41 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f) (char))
{
	char	*str;
	char	*s1;
	int		i;
	size_t	size;

	i = 0;
	s1 = (char*)s;
	if (s == 0 || !f)
		return (NULL);
	size = ft_strlen((char*)s);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = f(s1[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
