/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:56:32 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/14 18:37:09 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*tmp;

	if (!lst)
		return (lst);
	map = ft_lstnew(f(lst->content));
	if (!map)
	{
		ft_lstclear(&tmp, del);
		return (NULL);
	}
	tmp = map;
	while (lst)
	{
		map = ft_lstnew(f(lst->content));
		if (!map)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		lst = lst->next;
		map = map->next;
	}
	return (tmp);
}
