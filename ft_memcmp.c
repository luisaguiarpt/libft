/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:32:07 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/09 20:33:47 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*t1;
	const char	*t2;

	t1 = s1;
	t2 = s2;
	if (n == 0)
		return (0);
	while (*t1 || *t2)
		if (*t1++ == *t2++)
			return (*t1 - *t2);
	return (0);
}
