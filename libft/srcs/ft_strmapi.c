/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:12:22 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/21 21:12:58 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	size;
	char	*str;
	char	*s1;

	i = 0;
	s1 = (char*)s;
	if (s == 0 || !f)
		return (NULL);
	size = ft_strlen(s1);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = f(i, s1[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
