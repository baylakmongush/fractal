/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:06:19 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/19 15:22:23 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*str1;
	char	*str2;

	str1 = (char*)haystack;
	str2 = (char*)needle;
	if (*str2 == '\0')
		return (str1);
	while (*str1 != '\0')
	{
		if ((*str1 == *str2) && (ft_strncmp(str1, str2, ft_strlen(str2)) == 0))
			return (str1);
		str1++;
	}
	return (NULL);
}
