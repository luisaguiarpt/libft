#include "error_msg.h"	// error messages for int_gen
#include <stdio.h>	// printf
#include <stdlib.h>	// exit
#include <unistd.h>	// read, close
#include <fcntl.h>	// open
#include <stdint.h>	// uint8_t

int	gen_rand_int(int order)
{
	int			i = 0; 
	int			urandom_fd;
	const char	charset[] = "0123456789";
	int			charset_len = 10;
	int			nbr = 0;
	uint8_t		byte = 0;

	if (!(urandom_fd = open("/dev/urandom", O_RDONLY)))
	{
		perror("open /dev/urandom");
		exit(URAND_OPEN_FAILURE);
	}
	while (i < order + 1)
	{
		if (read(urandom_fd, &byte, sizeof(byte)) != sizeof(byte))
		{
			perror("read /dev/urandom");
			close(urandom_fd);
			exit(URAND_READ_FAILURE);
		}
		nbr = (nbr * 10) + (charset[byte % charset_len] - '0');
		i++;
	}
	close(urandom_fd);
	return (nbr);

}

int	main(int ac, char **av)
{
	int		order;
	int		nbr;

	if (ac == 1)
	{
		fprintf(stderr, "No argument passed.\nCorrect usage: gen_rand_int <number's order of magnitude>\n");	
		return (INT_GEN_NO_ARG);
	}
	else if (ac > 2)
	{
		fprintf(stderr, "Too many arguments passed.\nCorrect usage: gen_rand_str <number's order of magnitude>\n");	
		return (INT_GEN_XS_ARGS);
	}
	order = atoi(av[1]);
	if (order > 8)
	{
		fprintf(stderr, "Invalid order: must be between 0-8.\n");	
		return (INT_GEN_INVALID_ORDER);
	}
	nbr	= gen_rand_int(order);
	printf("%i", nbr);
	return (0);
}
