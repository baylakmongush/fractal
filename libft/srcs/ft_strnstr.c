/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:19:21 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/16 17:16:34 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft.h"

static size_t	ft_cmp(char *str1, char *str2, size_t len)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (ft_strncmp(str1, str2, ft_strlen(str2)) == 0)
		{
			while (i < len && *str2)
			{
				i++;
				count++;
				str2++;
			}
		}
		str1++;
		i++;
	}
	return (count);
}

char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len)
{
	char		*str1;
	char		*str2;
	size_t		count;

	str1 = (char*)haystack;
	str2 = (char*)needle;
	count = ft_cmp(str1, str2, len);
	if (count != ft_strlen(str2))
		return (NULL);
	if (str2 == 0 || *str2 == '\0')
		return ((char*)haystack);
	while (*str1 != '\0')
	{
		if ((*str1 == *str2) && (ft_strncmp(str1, str2, ft_strlen(str2)) == 0))
			return (str1);
		str1++;
	}
	return (NULL);
}
