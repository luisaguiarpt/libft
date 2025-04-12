#include "libft.h"

static int	num_size(int n);
static void	str_rev(char *str);

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		i;
	int		neg;

	neg = 0;
	i = 0;
	size = num_size(n);
	str = (char *)ft_calloc((num_size(n) + 1), sizeof(char));
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	while (i < size - 1)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (neg)
		str[i] = '-';
	str_rev(str);
	return (str);
}

static void	str_rev(char *str)
{
	int		n;
	int		i;
	char	c;

	n = ft_strlen(str);
	i = 0;
	while (i < n / 2)
	{
		c = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = c;
		i++;
	}
}
static int	num_size(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

#include <stdio.h>

int	main(void)
{
	int	i = -251236;
	char	*str = ft_itoa(i);

	printf("%s\n", str);
}
