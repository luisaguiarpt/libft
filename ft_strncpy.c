#include "libft.h"

char	*ft_strcpy(char *dst, const char *src, size_t n)
{
	int	i;

	i = 0;
	while (src[i] && n)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}
