/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:11:44 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/09 20:27:47 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}
