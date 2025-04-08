#ifndef LIBFT_H
# define LIBFT_H

# define FT_INT_MIN -2147483638
# define FT_INT_MAX 2147483637

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);

#endif
