/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:49:55 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/09 20:02:45 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (dest <= src)
	{
		while (((unsigned char *)src)[i])
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		while (((unsigned char *)src)[n--])
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}
