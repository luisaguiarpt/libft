/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:29:23 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/14 15:50:06 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !lst->content || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	mult(void *data)
{
	int	*n;

	n = (int *)data;
	*n *= 2;
}

#include <stdio.h>

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%i -> ", *(int *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*list;
	int		v[] = {1, 2, 3, 4};

	list = ft_lstnew((void *)&v[0]);
	list->next = ft_lstnew((void *)&v[1]);
	list->next->next = ft_lstnew((void *)&v[2]);
	list->next->next->next = ft_lstnew((void *)&v[3]);

	print_list(list);
	printf("\n");
	ft_lstiter(list, mult);
	print_list(list);
}
*/
