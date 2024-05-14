/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanir <btanir@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:46:42 by btanir            #+#    #+#             */
/*   Updated: 2023/12/14 17:47:48 by btanir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*ret;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	ret = new_lst;
	while (lst)
	{
		if (lst->next)
		{
			new_lst->next = ft_lstnew(f(lst->next->content));
			if (!new_lst)
			{
				ft_lstclear(&ret, del);
				return (0);
			}
			new_lst = new_lst->next;
		}
		lst = lst->next;
	}
	new_lst->next = NULL;
	return (ret);
}
