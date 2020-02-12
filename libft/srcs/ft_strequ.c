/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:26:13 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/18 18:45:57 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
