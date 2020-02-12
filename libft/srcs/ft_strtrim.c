/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:41:01 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/23 20:49:04 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../libft.h"

static char		*ft_copy(char const *s, char *str, size_t i, size_t j)
{
	size_t		p;

	p = 0;
	while (i <= j)
	{
		str[p] = s[i];
		i++;
		p++;
	}
	str[p] = '\0';
	return (str);
}

static char		*ft_copytab(char const *s)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	if (i == ft_strlen(s))
		return (ft_copytab(s));
	while (s[j] != '\0')
		j++;
	j--;
	while (s[j] == '\n' || s[j] == '\t' || s[j] == ' ')
		j--;
	len = j - i + 1;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (ft_copy(s, str, i, j));
}
