#include "error_msg.h"	// error messages for str_gen
#include <stdio.h>	// printf
#include <stdlib.h>	// malloc, exit
#include <string.h>	// strlen
#include <unistd.h>	// read, close
#include <fcntl.h>	// open
#include <stdint.h>	// uint8_t

char	*gen_rand_str(int len)
{
	char		*str;
	int			i = 0; 
	int			urandom_fd;
	const char	charset[] = "\n\t\r\a\b\v\f!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	int			charset_len = strlen(charset);
	uint8_t		byte = 0;

	if (!(str = malloc((len + 1) * sizeof(char))))
	{
		perror("can't malloc");
		exit(MALLOC_ERR);
	}
	if (!(urandom_fd = open("/dev/urandom", O_RDONLY)))
	{
		perror("open /dev/urandom");
		exit(URAND_OPEN_FAILURE);
	}
	while (i < len)
	{
		if (read(urandom_fd, &byte, sizeof(byte)) != sizeof(byte))
		{
			perror("read /dev/urandom");
			close(urandom_fd);
			exit(URAND_READ_FAILURE);
		}
		str[i] = charset[byte % charset_len];
		i++;
	}
	str[i] = '\0';
	close(urandom_fd);
	return (str);

}

int	main(int ac, char **av)
{
	int		len;
	char	*str;

	if (ac == 1)
	{
		printf("No argument passed.\nCorrect usage: gen_rand_str <string length>\n");	
		return (STR_GEN_NO_ARG);
	}
	else if (ac > 2)
	{
		printf("Too many arguments passed.\nCorrect usage: gen_rand_str <string length>\n");	
		return (STR_GEN_XS_ARGS);
	}
	else if (!(len = atoi(av[1])))
	{
		printf("Invalid length passed.\n");	
		return (STR_GEN_INVALID_LEN);
	}
	str = gen_rand_str(len);
	printf("%s\n", str);
	return (0);
}
