/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:29:27 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/20 23:55:18 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

static char		**ft_free(size_t n, char **str)
{
	while (n > 0)
	{
		str[n] = NULL;
		free(str[n]);
		n--;
	}
	str[n] = NULL;
	free(str[n]);
	return (NULL);
}

static char		**ft_putwords(char **str, char const *s, char c, size_t count)
{
	size_t		n;
	size_t		index;
	size_t		i;
	size_t		p;

	n = 0;
	i = 0;
	while (n < count)
	{
		while (s[i] == c)
			i++;
		index = i;
		p = 0;
		while (s[i] != c && s[i] && ++i)
			p++;
		if (!(str[n] = (char*)malloc((p + 1) * sizeof(char))))
			return (ft_free(n, &str[n]));
		p = 0;
		while (index < i)
			str[n][p++] = s[index++];
		str[n++][p] = '\0';
	}
	str[n] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		count;

	if (s == 0)
		return (NULL);
	count = ft_count(s, c);
	if (!(str = (char**)malloc((count + 1) * sizeof(char*))))
		return (NULL);
	ft_putwords(str, s, c, count);
	return (str);
}
