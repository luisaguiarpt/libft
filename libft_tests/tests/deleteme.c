#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	i = 0;
	char	*s = "abcdefghijklmnopqrstuvwxyz";
	while (*s)
	{
		i = isalpha(*s);
		printf("%i\n", i);
		s++;
	}
}
