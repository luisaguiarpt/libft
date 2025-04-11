/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:29:27 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/11 19:59:10 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c);
static char	*ft_strdupx(const char *s, char c);
static char	**free_array(char **str_array, int j);

char	**ft_split(const char *s, char c)
{
	char	**str_array;
	int		j;
	int		i;

	j = -1;
	i = 0;
	str_array = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!str_array)
		return (NULL);
	while (++j < count_words(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			str_array[j] = ft_strdupx(&s[i], c);
			if (!str_array[j])
				return (free_array(str_array, j - 1));
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (str_array);
}

static char	*ft_strdupx(const char *s, char c)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	dup = ft_calloc((i + 1), sizeof(char));
	if (!dup)
		return (NULL);
	while (--i >= 0)
	{
		dup[i] = s[i];
	}
	return (dup);
}

static char	**free_array(char **str_array, int j)
{
	while (j >= 0)
		free(str_array[j--]);
	free(str_array);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "split  ||this|for|me|||||!|" ;
	char	**array;

	array = ft_split(str, '|');
	printf("%i\n", count_words(str, '|'));
	while (*array)
	{
		printf("%s\n", *array);
		array++;
	}
}
*/
