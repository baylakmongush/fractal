/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:32:32 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/23 15:17:57 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*sp;

	if (!(sp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		sp->content_size = content_size;
		if (!(sp->content = malloc(sizeof(content_size))))
		{
			free(sp);
			return (NULL);
		}
		ft_memcpy(sp->content, content, content_size);
		sp->next = NULL;
	}
	else
	{
		sp->content_size = 0;
		sp->content = NULL;
		sp->next = NULL;
	}
	return (sp);
}
