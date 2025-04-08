#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "error_msg.h"

#ifdef USE_FT
# include "../../libft.h"
#endif

int	main(int ac, char **av)
{
	if (ac != 2)
		return (3);
	printf("%s", FT(av[1]));
	return (0);
}
