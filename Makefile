CC = cc 
FLAGS = -Wall -Wextra -Werror

INCS = libft.h
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	   ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c \
	   ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	   ft_atoi.c ft_strdup.c

OBJS = $(SRCS:%.c=%.o)

NAME = libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -include $(INCS) -c $^ -o $@ 

$(NAME): $(OBJS) $(INCS)
	ar rcs $(NAME) $(OBJS) $(INCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
