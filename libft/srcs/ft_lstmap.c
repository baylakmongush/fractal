/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:18:55 by npetrell          #+#    #+#             */
/*   Updated: 2019/09/23 20:29:46 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	head = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
		{
			while (head)
			{
				tmp = head->next;
				free(head->content);
				free(head);
				head = tmp;
			}
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (head);
}
