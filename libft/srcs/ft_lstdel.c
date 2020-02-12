/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 04:18:16 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/23 15:37:01 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!del)
		return ;
	if (*alst)
	{
		while (*alst != NULL)
		{
			tmp = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
			*alst = tmp;
		}
	}
}
