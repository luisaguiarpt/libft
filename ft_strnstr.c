/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:34:11 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/09 20:49:41 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(const char *hay, const char *nee);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*little))
		return ((char *)big);
	while (*big && i++ < len)
	{
		if (is_match(big, little))
			return ((char *)big);
	}
	return (NULL);
}

static int	is_match(const char *hay, const char *nee)
{
	size_t	len;

	len = ft_strlen(nee);
	while (*hay && len)
	{
		if (*hay++ != *nee++)
			return (0);
		len--;
	}
	return (1);
}
