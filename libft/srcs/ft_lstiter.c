/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:03:29 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/23 16:30:11 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!f)
		return ;
	if (lst)
	{
		while (lst != NULL)
		{
			f(lst);
			lst = lst->next;
		}
	}
}
