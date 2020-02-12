/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:42:19 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/23 20:30:17 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t			ft_count_word(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
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
