/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:47:23 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/09 20:13:50 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	int				ret;

	ret = ft_strlen(src);
	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ret);
}
