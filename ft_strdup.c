#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	len;
	int		i;

	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
