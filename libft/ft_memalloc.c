/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:49:17 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/23 21:09:00 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	str = malloc(size);
	if (str == NULL)
		return (0);
	while (i < size)
	{
		((unsigned char*)str)[i] = '\0';
		i++;
	}
	return (str);
}
