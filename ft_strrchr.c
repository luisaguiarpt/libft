/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:36:26 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/09 20:27:08 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	char	*tmp;

	while (*s)
	{
		if (*s == c)
			tmp = (char *)s;
		s++;
	}
	if (*s == c)
		tmp = (char *)s;
	return ((char *)s);
}
