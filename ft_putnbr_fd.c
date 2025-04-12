#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == FT_INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

int	main(void)
{
	int	n = FT_INT_MIN;

	ft_putnbr_fd(n, 1);
}
