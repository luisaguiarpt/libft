CC = cc
FLAGS = -Wall -Wextra -Werror -g

PRNTDIR = ..
SRCDIR = srcs 
INCDIR = includes
BINDIR = bin
TESTDIR = tests

# Source files
FT_SRC1 = $(PRNTDIR)/ft_toupper.c $(PRNTDIR)/ft_tolower.c $(PRNTDIR)/ft_isprint.c $(PRNTDIR)/ft_isascii.c $(PRNTDIR)/ft_isalnum.c $(PRNTDIR)/ft_isdigit.c $(PRNTDIR)/ft_isalpha.c)
TST1_SRC = $(TESTDIR)/test1.c
RND_SRC = $(SRCDIR)/gen_rand_int.c $(SRCDIR)/gen_rand_str.c

# Executables
FT_EXE1 = $(addprefix $(BINDIR)/ft_,toupper tolower isprint isascii isalnum isdigit isalpha)
SYS_EXE1 = $(addprefix $(BINDIR)/sys_,toupper tolower isprint isascii isalnum isdigit isalpha)
RND_EXE = $(BINDIR)/gen_rand_int $(BINDIR)/gen_rand_str

all: $(FT_EXE1) $(SYS_EXE1) $(RND_EXE)

# Rule for test executables using libft
$(BINDIR)/ft_%: $(PRNTDIR)/ft_%.c $(TST1_SRC)
	$(CC) $(FLAGS) -DUSE_FT -DFT=ft_$* $^ -o $@ -I $(INCDIR)

# Rule for system test executables
$(BINDIR)/sys_%: $(TST1_SRC)
	$(CC) $(FLAGS) -DFT=$* $< -o $@ -I $(INCDIR)

# Rule for random generators
$(BINDIR)/gen_rand_int: srcs/gen_rand_int.c
	$(CC) $(FLAGS) $< -o $@ -I $(INCDIR)

$(BINDIR)/gen_rand_str: srcs/gen_rand_str.c
	$(CC) $(FLAGS) $< -o $@ -I $(INCDIR)

.PHONY: tests clean fclean re

tests:
	bash ./tests/run_tests_1.sh
	bash ./tests/run_tests_1_1.sh

clean:
	rm -f $(FT_EXE1) $(SYS_EXE1) $(RND_EXE)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(NAME)
